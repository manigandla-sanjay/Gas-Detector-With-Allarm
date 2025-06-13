# Gas Leak Detector with Alarm
#### Author: Bocaletto Luca

**Files**  
- `README.md`  
- `GasLeakDetector.ino`

## 1. Concept  
Continuously monitor combustible gas (LPG, methane, smoke) with an MQ-2 sensor. When the analog reading exceeds a user-defined threshold, trigger a visual (red LED) and audible (buzzer) alarm for a fixed duration, while a green LED indicates “safe” status.

## 2. Bill of Materials  
- 1 × Arduino Uno (or Nano)  
- 1 × MQ-2 gas sensor module (with onboard potentiometer)  
- 1 × Active buzzer  
- 1 × Red LED + 220 Ω resistor  
- 1 × Green LED + 220 Ω resistor  
- Breadboard + jumper wires  
- USB cable for power/programming  

## 3. Wiring Diagram

    MQ-2 Module         Arduino Uno
    ┌───────────────┐    ┌───────────┐
    │ VCC ─────────► 5V │           │
    │ GND ─────────► GND│           │
    │ AO  ─────────► A0 │ MQ-2 AO    │
    │ DO  ─────────► D2 │ (unused)   │
    └───────────────┘    └───────────┘

    Red LED            Arduino Uno
    ┌────────┐         ┌───────────┐
    │ Anode ─┬─► D8    │           │
    │ Cathode─┴─► GND  │           │
    └────────┘         └───────────┘

    Green LED          Arduino Uno
    ┌────────┐         ┌───────────┐
    │ Anode ─┬─► D7    │           │
    │ Cathode─┴─► GND  │           │
    └────────┘         └───────────┘

    Buzzer             Arduino Uno
    ┌────────┐         ┌───────────┐
    │ +    ──┬─► D9    │           │
    │ –    ──┴─► GND   │           │
    └────────┘         └───────────┘

> Use 220 Ω resistors on both LEDs. Adjust MQ-2 onboard potentiometer so clean-air reading ≈200–300.

## 4. Software Setup  
1. Install Arduino IDE (≥1.8.x).  
2. Create a folder named `GasLeakDetector`, and inside save:  
   - `README.md` (this file)  
   - `GasLeakDetector.ino` (source code below)  
3. Open the folder in Arduino IDE; it will load `GasLeakDetector.ino`.  
4. Select **Arduino Uno** (or your board) and correct COM port.  

## 5. Usage  
1. Upload sketch.  
2. Open Serial Monitor at **9600 baud** to see live gas analog values.  
3. In clean air the green LED stays on.  
4. When `gasValue` > `GAS_THRESHOLD` (default 300), the red LED and buzzer blink for 10 s.  
5. After alarm timeout, system returns to safe state.

---

Say **continua** when you’re ready for project #5!  
