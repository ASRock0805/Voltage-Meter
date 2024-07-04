# Voltage Meter

This is a project that implements a simple voltage meter using the Arduino. The sensor's output voltage is converted by the ADC (Analog to Digital Converter) and displayed via the serial monitor.

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

Defines the signal pin and the number of samples for smoothing.

Constants
