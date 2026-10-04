# The Learning Garden

A screen-free, hands-on interactive learning board for high-needs nonverbal and low-verbal learners.

> **Status: design and early prototyping.** This is my senior capstone project at BYU-Idaho (Fall 2026). Right now this repo holds the design documentation and diagrams. Code, wiring, and build photos will be added as the project is built.

## Why I'm building this

I work as a special education paraprofessional in a self-contained classroom. A lot of my students' instruction happens on an iPad or with flat materials like picture cards. Very little of it is something a student can hold in their hands that reacts right away, the same way every time.

The Learning Garden is built to fill that gap. A student picks up a piece, places it in the garden, and the garden responds immediately with light and movement. The same action always gets the same fun reaction, and that consistency is what the project is aiming for.

## How it works

1. The board has **five sockets**, each with its own RFID reader.
2. Learning pieces ("tokens") such as flowers, letters, numbers, and colors each have an **RFID tag sealed inside the base**.
3. When a student places a token in a socket, the board identifies it and that socket reacts: a ring of LEDs "dances" around it and the socket spins.
4. A teacher sets how many sockets are active (one to five) using a **switch per socket**, so the same board fits different ability levels, including the "field of three" choice format many of my students already use.

### Interchangeable tops

The garden is the first "top," but the base is designed to be reused. Tops lock onto the base, and a reader in the base identifies which top is attached. The same token can then trigger a different, theme-appropriate reaction depending on the top.

The interaction logic stays the same across tops. Only the tag-to-reaction mapping changes, so a new theme is a new configuration rather than new code.

## Design principles

- **Consistent.** The same action gets the same immediate reaction every time.
- **Tangible and screen-free.** Everything the student sees and touches is physical.
- **Classroom-proof.** No knobs to pull off, no loose cards to lose, and nothing peelable. Tags are sealed inside the tokens.
- **Forgiving.** Tokens drop into a socket in any orientation.
- **Adjustable.** One to five active sockets, set by the teacher.
- **Extensible.** New themes reuse the same base, sockets, and read logic.

## Planned hardware

| Part | Purpose |
| --- | --- |
| Arduino Mega 2560 Rev3 | Main controller |
| RFID reader per socket | Identifies the token placed in each socket |
| RFID reader in the base | Identifies which top is attached |
| 16-LED WS2812B ring per socket | Light reactions |
| Servo per socket | Spins the socket |
| PCA9685 servo driver board (I2C) | Generates the control signals for all the servos |
| Switch per socket | Sets which sockets are active |
| 3D-printed sockets and tokens | Keyed so the token and socket turn together |

## Diagrams

<!-- Replace the file names below with your actual diagram files in the diagrams/ folder. -->

### System overview
![System overview](diagrams/system-overview.png)

### Wiring
![Wiring diagram](diagrams/wiring.png)

### Interaction flow
![Interaction flow](diagrams/interaction-flow.png)

## Roadmap

- [ ] Technology prototype (October 17, 2026)
- [ ] Requirements specification (October 31, 2026)
- [ ] Garden top built and working
- [ ] Final delivery (December 17, 2026)

### Stretch goals

- A second top (a table for kitchen vocabulary) to prove the base can be reused with a new theme
- A simple animatronic "wave" greeting using a single micro servo

## Repository layout

```
the-learning-garden/
├── README.md
├── diagrams/     design and wiring diagrams
├── docs/         proposal and requirements documents (coming)
└── firmware/     Arduino code (coming)
```

## About me

I'm Jennifer Kohl, a Software Development student at Brigham Young University–Idaho and a special education paraprofessional. More of my work is at [github.com/JLKohl](https://github.com/JLKohl).
