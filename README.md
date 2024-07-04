# Voltage Meter

This is a project that implements a simple voltage meter using Arduino. The sensor's output voltage is converted by the ADC (Analog to Digital Converter) and displayed via the serial monitor.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Hardware Required](#hardware-required)
  - [Software Required](#software-required)
  - [Setup](#setup)
- [Code Explanation](#code-explanation)
- [Usage](#usage)
- [License](#license)
- [References](#references)

## Introduction

This project demonstrates how to read an analog voltage using an Arduino and display the result on the serial monitor. The output voltage from a sensor is sampled and smoothed over multiple readings to provide a stable voltage measurement.

## Features

- Reads analog voltage from a sensor.
- Uses ADC for voltage conversion.
- Prints the measured voltage to the serial monitor.
- Smoothes the voltage readings by averaging multiple samples.

## Getting Started

### Hardware Required

- Arduino UNO
- Voltage sensor
- Connecting wires

### Software Required

- [Arduino IDE](https://www.arduino.cc/en/software)

### Setup

1. **Connect the Hardware:**
   - Connect the voltage sensor to the Arduino UNO. The signal pin of the sensor should be connected to the analog pin `A0`.

2. **Upload the Code:**
   - Open the Arduino IDE.
   - Copy the code from `voltage_meter.ino` and paste it into the Arduino IDE.
   - Select the correct board and port from the Tools menu.
   - Upload the code to the Arduino UNO.

## Code Explanation

### Preprocessor

```cpp
#define sigPin A0 // Voltage meter signal pin w/ ADC
#define N 800     // Measurement sampling number for smoothing
```
- Defines the signal pin and the number of samples for smoothing.
### Constants

```cpp
const unsigned long baudSpeed = 115200UL;
const unsigned long period = 1000UL;
const float vIn = 5.0f;
const byte resBits = 10;
const float vConv = vIn / (pow(2.0, resBits) - 1.0f);
```
- Sets the baud rate for serial communication, the measurement period, and the voltage conversion constant.

### Initialization

```cpp
void setup(void) {
  Serial.begin(baudSpeed);
  pinMode(sigPin, INPUT);
  startTime = millis();
  measuredVoltage = 0.0f;
}
```
- Initializes the serial port and sets the signal pin as input.

### Measurement Loop

```cpp
void loop(void) {
  currentTime = millis();
  
  if ((currentTime - startTime) >= period) {
    getVolt(sigPin);

    Serial.print("Voltage: ");
    Serial.print(measuredVoltage, 4);
    Serial.println(" V");

    startTime = currentTime;
  } else {
    return;
  }
}
```
- Measures and prints the voltage every second.

### Analog Voltage Reading

```cpp
void getVolt(byte signalPin) {
  measuredVoltage = 0;
  for (unsigned int i = 0U; i < N; ++i) {
    measuredVoltage += analogRead(signalPin);
    delay(1UL);
  }
  measuredVoltage = (measuredVoltage * vConv) / N;

  if (isinf(measuredVoltage) || isnan(measuredVoltage)) {
    measuredVoltage = -1;
  }
}
```
- Reads the analog voltage multiple times and averages the result.

### Usage

1. **Connect the Arduino to your computer:**
   - Open the serial monitor from the Arduino IDE.
   - Set the baud rate to `115200`.
2. **Observe the voltage readings:**
   - The measured voltage will be printed every second on the serial monitor.

### License

This project is licensed under the MIT License - see the LICENSE file for details.

### References

- [Voltmeter - Wikipedia](https://en.wikipedia.org/wiki/Voltmeter)
