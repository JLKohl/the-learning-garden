# The Learning Garden

**Jennifer Kohl**

## Purpose

The Learning Garden is a physical interactive learning environment geared towards helping non- or low-verbal autistic children have a non-screen way to learn about the world around them.

## Background/Prior Knowledge

The technology used for this project will be based on Arduino; a lot of it will involve working with RFID sensors and LED lights.

I have worked with Arduino boards on my own a little, and I have also taken a class in Arduino at a technology conference, where I was taught how to find code in the Arduino Library and how to wire several projects that I got working. Outside of that, I have very little knowledge of using Arduino, and I am very excited to get to work with it in depth this semester, as I am hoping it will become a significant part of my work in the future.

There are not a lot of studies done on using RFID for learning with children who have disabilities, but in my research, I did find one significant study, published in the journal *Sensors* ([source](https://pmc.ncbi.nlm.nih.gov/articles/PMC4541810/)). This study found that using a tangible user interface with children with Down syndrome had a positive effect on their learning outcomes. Although it is not the same disability, the study shows that using tangibles, as I would in the Learning Garden, can have a positive impact on those who struggle to learn what are generally considered basic skills.

## Description

This product is going to be a physical interactive set intended for use in a classroom or home setting with high-needs non- or low-verbal autistic children. It will be used to help teach children basic learning concepts such as colors, numbers, and letters.

The interactive Learning Garden will also have an interchangeable top, meaning extended versions of this project could include other tops for other basic learning needs, such as household routines or objects — possibly a kitchen top with objects found in a kitchen, or a top laying out bedtime items to give a more tactile, visual bedtime schedule.

The base will be set up like a garden scene, with a top plate that resembles a garden. It will have at least five holes connected to servos so that they can move, and those holes will also contain RFID readers. Each item — whether it's a flower, a letter, or a number — will sit on a stem with a base that fits into the hole. That base will have an RFID chip inside it, so the sensor can read which piece has been inserted. In most cases, the code will trigger the matching reaction as soon as the object is inserted, though for some objects the reaction may instead be tied to removal, depending on what best fits that piece's lesson. I will also include a speaker so that words can be associated with whatever is inserted, helping these kids connect objects with words.

## Significance

The significance of this project could be a great impact on the increasing non-verbal and low-verbal populations, giving these children a chance to learn with more tactile objects, where most of their learning at the moment is done with pictures on cards and electronic devices. Although these items are very effective at helping children learn, there is a gap when it comes to tangible objects.

The Learning Garden will not only allow for tangible objects to be used, but it will also allow for the immediate cause and effect that is often needed for a child to want to continue interacting with an object — something that is often only found in high-technology devices. This is especially important with high level autistic children because they often struggle with the concept of cause and effect and having immediate high response helps them learn that feedback loop. I've seen this firsthand in my own classroom — many of my students don't yet understand that their own actions can cause something to happen, and building that understanding is a big part of what I want this project to help with.

I believe this project would be perfect for a resume because it shows an understanding of how a product needs to be useful, reliable, and geared toward the audience it's intended for. It will show that I am willing to work hard, research the people I am creating for, and that I have a passion for filling product gaps with useful products.

## New Computer Science Concepts

A lot of what I will be doing in this project will be new to me. Fortunately, I love researching and working toward something I am passionate about. I will be learning how to work with physical sets, and I will be learning a lot more about Arduino and how to set up breadboards, servos, and other parts.

I have worked with all of these things before in small, insignificant projects, but it will be amazing to be able to put it all together to build something that I am creating myself.

## Interestingness

I am absolutely thrilled to be building this project for a lot of reasons. I am very passionate about world-building and making physical sets that are interactive.

I also spend my days in a non- to low-verbal autistic classroom, watching kids work so hard just to learn what other kids just pick up when they are little. I want to build them something that will not just be helpful, but will also be fun for them to learn with. Just waking up in the morning and functioning can be a chore for them, so my hope is to bring just a bit more joy into the way they perceive learning and the world in general.

## Milestones, Tasks and Schedule

Total: **126 hours**, Sep 28 – Dec 17. Fixed deadlines: technology prototype due Oct 17, requirements specification due Oct 31.

| Dates | Task | Hours |
| --- | --- | --- |
| Sep 28–Oct 4 | Order hardware (Arduino, one RFID reader, tags, servo, LED, power supply) and do focused research on the RFID and Servo libraries | 10 |
| Oct 5–11 | Wire and code the single-socket circuit: one RFID reader, one servo, one LED and speaker reacting to one tag | 10 |
| Oct 12–17 | Debug and polish the single-socket build, then finalize and submit the technology prototype (fixed deadline: Oct 17) | 8 |
| Oct 19–25 | Begin drafting the requirements specification while starting to wire and test additional sockets in parallel | 10 |
| Oct 26–31 | Finish and submit the requirements specification (fixed deadline: Oct 31); continue scaling sockets alongside it | 10 |
| Nov 2–8 | Finish scaling to all five sockets: wiring, power distribution, solving reader-interference issues | 14 |
| Nov 9–15 | Build the reaction logic architecture (tag-to-reaction mapping, kept as configurable data) | 12 |
| Nov 16–22 | Design and fabricate the base/enclosure | 12 |
| Nov 23–29 | Design and build the full token set (flowers, letters, numbers, colors) with RFID tags (reduced hours — Thanksgiving break falls here) | 6 |
| Nov 30–Dec 6 | Full integration testing and debugging | 10 |
| Dec 7–10 | Durability pass, plus documentation and final report | 10 |
| Dec 11–17 | Buffer for last-minute fixes and demo rehearsal before submission, and SPED talk due | 14 |

## Resources

**Electronics**

| Item | Cost |
| --- | --- |
| Arduino Uno R3 | $27.60 |
| PCA9685 servo driver board | $9 |
| MFRC522 RFID reader modules (×5) | $20 |
| RFID stickers, 20mm, sealed inside each token base | $9 |
| SG90 micro servos (×5) | $16 |
| Addressable LED strip (WS2812/NeoPixel), 1m | $16 |
| DFPlayer Mini MP3 module | $9 |
| Small 8-ohm speaker | $4 |
| MicroSD card | $7 |
| Breadboard + jumper wire kit | $13 |
| 5V USB wall adapter (for the Arduino) | $8 |
| 5V 2–3A power supply (for the PCA9685/servos) | $12 |

**Structure & craft**

| Item | Cost |
| --- | --- |
| Floral/craft wire (bendable stem armature) | ~$6 |
| Flexible clear tubing (light-pipe sleeve over the wire) | ~$10 |
| 3D printer filament (base and flower tops) | $18 |
| Fake flower heads | $12 |

**Tools**

| Item | Cost |
| --- | --- |
| Soldering iron kit | $25 |
| Multimeter | $18 |

## Dependencies

This project depends on the Arduino programming language (a variant of C/C++), which I'll be writing in through the Arduino IDE. Development and testing will happen on my own personal computer, with finished code uploaded to the physical Arduino board over USB. Once deployed, the build runs independently off its own power adapters — no computer needs to stay connected.

I'm also depending on a handful of free, open-source libraries: the MFRC522 library for the RFID readers, Adafruit's PWM Servo Driver library for the PCA9685, and the Wire library for I2C communication.