// The Learning Garden - first combined test
// Tap any RFID card or tag: the LED ring turns purple for 2 seconds.

#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_NeoPixel.h>
#include <DFRobotDFPlayerMini.h>
#include <Servo.h>

// RFID reader pins (Arduino Mega)
#define RST_PIN 5
#define SS_PIN 53

// LED ring
#define LED_PIN 6
#define LED_COUNT 16
#define BRIGHTNESS 5 // 0-255, kept low for students

// Card numbers
byte cardId[] = {0x6E, 0x1C, 0xD7, 0x06};
byte fobId[] = {0x31, 0x17, 0x00, 0x64};

// getting the audio player
DFRobotDFPlayerMini player;
// gettning the servo
Servo flower;

// setting up a timer so that the servo loop will not run into issues with delay

unsigned long lightOnAt = 0;
bool lightOn = false;
const unsigned long LIGHT_TIME_MS = 2000; // how long the ring stays lit

// for flower shake
unsigned long lastWiggle = 0;
bool wiggleLeft = false;
const unsigned long WIGGLE_MS = 150; // time between wiggles

MFRC522 reader(SS_PIN, RST_PIN);
Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  reader.PCD_Init();
  reader.PCD_SetAntennaGain(reader.RxGain_max);

  ring.begin();
  ring.setBrightness(BRIGHTNESS);
  ring.clear();
  ring.show();

  Serial1.begin(9600);
  player.begin(Serial1, false, true);
  player.volume(20);

  flower.attach(9);
  flower.write(90);

  Serial.println("Ready. Place your flower.");
}

void loop()
{

  if (lightOn && millis() - lightOnAt >= LIGHT_TIME_MS)
  {
    ring.clear();
    ring.show();
    lightOn = false;
    flower.write(90);
  }

  if (lightOn && millis() - lastWiggle >= WIGGLE_MS)
  {
    lastWiggle = millis();
    wiggleLeft = !wiggleLeft;            // flip left/right
    flower.write(wiggleLeft ? 70 : 110); // small shake around 90
  }

  // Wait until a new card is on the reader
  if (!reader.PICC_IsNewCardPresent())
    return;
  if (!reader.PICC_ReadCardSerial())
    return;

  // Print the card's ID so you can write it down
  Serial.print("Card UID:");
  for (byte i = 0; i < reader.uid.size; i++)
  {
    Serial.print(reader.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(reader.uid.uidByte[i], HEX);
  }
  Serial.println();

  if (memcmp(reader.uid.uidByte, fobId, 4) == 0)
  {
    // turn the ring yellow for yellow flower
    ring.fill(ring.Color(255, 255, 77));
    ring.show();
    player.play(1);
    lightOnAt = millis();
    lightOn = true;
    flower.write(150);
  }

  // Put the card to sleep so one tap gives one reaction
  reader.PICC_HaltA();
}
