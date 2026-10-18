// The Learning Garden - color swap test
// White card = purple, blue fob = blue, any other tag = soft white.
// Putting a different tag on the reader switches the color right away.

#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_NeoPixel.h>

// RFID reader pins (Arduino Mega)
#define RST_PIN 5
#define SS_PIN  53

// LED ring
#define LED_PIN     6
#define LED_COUNT   16
#define BRIGHTNESS  25     // 0-255

// Tag IDs
byte cardId[] = {0x6E, 0x1C, 0xD7, 0x06};
byte fobId[]  = {0x31, 0x17, 0x00, 0x64};

const unsigned long LIGHT_TIME_MS = 2000;   // how long the ring stays lit

// Timer instead of delay(), so the reader keeps checking for tags
unsigned long lightOnAt = 0;
bool lightOn = false;

MFRC522 reader(SS_PIN, RST_PIN);
Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// True if the tag just read has the same 4-byte ID as storedId
bool idMatches(byte *storedId) {
  return reader.uid.size == 4 && memcmp(reader.uid.uidByte, storedId, 4) == 0;
}

void setup() {
  Serial.begin(9600);
  SPI.begin();
  reader.PCD_Init();

  ring.begin();
  ring.setBrightness(BRIGHTNESS);
  ring.clear();
  ring.show();

  Serial.println("Ready. Tap a card or tag.");
}

void loop() {
  // Turn the light off once its time is up.
  // This has to come first, before the returns below.
  if (lightOn && millis() - lightOnAt >= LIGHT_TIME_MS) {
    ring.clear();
    ring.show();
    lightOn = false;
  }

  // Wait until a new tag is on the reader
  if (!reader.PICC_IsNewCardPresent()) return;
  if (!reader.PICC_ReadCardSerial()) return;

  // Print the tag's ID
  Serial.print("Card UID:");
  for (byte i = 0; i < reader.uid.size; i++) {
    Serial.print(reader.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(reader.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Pick the color for this tag
  uint32_t color;
  if (idMatches(cardId)) {
    color = ring.Color(140, 0, 255);   // purple
  } else if (idMatches(fobId)) {
    color = ring.Color(0, 100, 255);   // blue
  } else {
    color = ring.Color(60, 60, 60);    // soft white for unknown tags
  }

  // Light the ring and start (or restart) the timer
  ring.fill(color);
  ring.show();
  lightOnAt = millis();
  lightOn = true;

  // Put the tag to sleep so holding it there gives one reaction
  reader.PICC_HaltA();
}
