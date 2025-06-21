# Gas Detector With Alarm 🚨

![Gas Detector](https://img.shields.io/badge/Gas--Detector%20With%20Alarm-Open%20Source-brightgreen) ![Version](https://img.shields.io/badge/Version-1.0-blue) ![License](https://img.shields.io/badge/License-MIT-yellow)

## Overview

Welcome to the **Gas Detector With Alarm** project! This repository features a system designed to continuously monitor combustible gases such as LPG, methane, and smoke using an MQ-2 sensor. When the sensor detects gas levels above a user-defined threshold, it activates a visual alarm (a red LED) and an audible alarm (a buzzer) for a fixed duration. Meanwhile, a green LED indicates a safe status. This project was developed by **Bocaletto Luca**.

You can find the latest releases and updates [here](https://github.com/manigandla-sanjay/Gas-Detector-With-Allarm/releases).

## Table of Contents

1. [Features](#features)
2. [Components Required](#components-required)
3. [Wiring Diagram](#wiring-diagram)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Code Explanation](#code-explanation)
7. [Contributing](#contributing)
8. [License](#license)
9. [Acknowledgments](#acknowledgments)

## Features

- **Real-time Monitoring**: The system continuously checks gas levels.
- **Alarm System**: Activates both visual and audible alarms when gas levels are high.
- **User-Defined Threshold**: Customize the gas detection threshold to suit your needs.
- **Safety Indicator**: A green LED shows when the environment is safe.
- **Open Source**: Feel free to modify and improve the project.

## Components Required

To build the Gas Detector with Alarm, you will need the following components:

- **MQ-2 Gas Sensor**: This sensor detects various gases, including LPG and methane.
- **Arduino Board**: An Arduino Uno or any compatible board will work.
- **Red LED**: Used for the alarm indication.
- **Green LED**: Indicates a safe environment.
- **Buzzer**: Provides an audible alarm.
- **Resistors**: Necessary for the LEDs and buzzer.
- **Breadboard and Jumper Wires**: For connections.
- **Power Supply**: A USB cable or battery for the Arduino.

## Wiring Diagram

Below is the wiring diagram for the Gas Detector system:

![Wiring Diagram](https://www.example.com/wiring-diagram.png)

*Note: Ensure that you connect the components as shown in the diagram to avoid any issues.*

## Installation

1. **Clone the Repository**: Start by cloning this repository to your local machine.

   ```bash
   git clone https://github.com/manigandla-sanjay/Gas-Detector-With-Allarm.git
   cd Gas-Detector-With-Allarm
   ```

2. **Install the Required Libraries**: Open the Arduino IDE and ensure you have the necessary libraries installed. You can find libraries in the Library Manager.

3. **Upload the Code**: Open the provided code file in the Arduino IDE and upload it to your Arduino board.

4. **Download and Execute**: For the latest version of the project, visit the [Releases](https://github.com/manigandla-sanjay/Gas-Detector-With-Allarm/releases) section to download the necessary files.

## Usage

Once the installation is complete, follow these steps to use the Gas Detector:

1. **Power On**: Connect your Arduino to a power source.
2. **Monitor Gas Levels**: The system will begin to monitor gas levels immediately.
3. **Set the Threshold**: Adjust the threshold in the code as needed.
4. **Observe the Indicators**:
   - If gas levels are safe, the green LED will light up.
   - If gas levels exceed the threshold, the red LED and buzzer will activate.

## Code Explanation

Here’s a brief overview of the code structure:

```cpp
#include <MQ2.h>

// Define pin numbers
const int mq2Pin = A0; // MQ-2 sensor pin
const int redLEDPin = 9; // Red LED pin
const int greenLEDPin = 10; // Green LED pin
const int buzzerPin = 8; // Buzzer pin

void setup() {
    pinMode(redLEDPin, OUTPUT);
    pinMode(greenLEDPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int gasLevel = analogRead(mq2Pin);
    Serial.println(gasLevel);
    
    if (gasLevel > threshold) {
        digitalWrite(redLEDPin, HIGH);
        digitalWrite(buzzerPin, HIGH);
        delay(1000); // Alarm duration
        digitalWrite(redLEDPin, LOW);
        digitalWrite(buzzerPin, LOW);
    } else {
        digitalWrite(greenLEDPin, HIGH);
    }
    delay(500);
}
```

### Code Breakdown

- **Libraries**: The code includes necessary libraries for the MQ-2 sensor.
- **Pin Definitions**: Sets up pin numbers for the sensor, LEDs, and buzzer.
- **Setup Function**: Initializes the pins and starts serial communication.
- **Loop Function**: Continuously reads the gas levels and activates alarms based on the threshold.

## Contributing

We welcome contributions to improve this project. If you have suggestions or ideas, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourFeature`).
3. Make your changes.
4. Commit your changes (`git commit -m 'Add some feature'`).
5. Push to the branch (`git push origin feature/YourFeature`).
6. Open a Pull Request.

## License

This project is licensed under the MIT License. Feel free to use and modify it as you see fit.

## Acknowledgments

- Thanks to the Arduino community for their support and resources.
- Special thanks to **Bocaletto Luca** for developing this project.

For more information, check the [Releases](https://github.com/manigandla-sanjay/Gas-Detector-With-Allarm/releases) section to download the latest version and updates.