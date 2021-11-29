/*
  - Voltage Meter
      The output voltage of the sensor is converted by ADC.


  Created 23 Nov. 2019
  by Yi-Xuan Wang

  References:
  https://en.wikipedia.org/wiki/Voltmeter
*/

/*--- Preprocessor ---*/
#define sigPin A0 // Voltage meter signal pin w/ ADC
#define N 800     // Measurment sampling number for smoothing

/*--- Constants ---*/
const unsigned long baudSpeed = 115200UL;           // Sets the data rate in bits per second (baud) for serial data transmission
const unsigned long period = 1000UL;                // The value is a number of milliseconds

const byte vIn = 5;                                             // Supply voltage from Arduino
const byte resBits = 10;                                        // Resolution of ADC (10 bits)
const float vConv = (float)(vIn / (pow(2.0, resBits) - 1.0f));  // Voltage of ADC level (2^bits)

/*--- Global Variables ---*/
unsigned long startTime;    // Start time
unsigned long currentTime;  // Current time

float vOut;                 // Output of the ADC

/*--- Function Prototype ---*/
void setup(void);
void loop(void);
void getVolt(byte );

/*--- Initialization ---*/
void setup(void) {
  Serial.begin(baudSpeed);  // Initializes serial port
  pinMode(sigPin, INPUT);   // Initializes potentiometer pin
  startTime = millis();     // Initial start time

  // Voltage Meter Initialization
  vOut = 0.0f;
}

/*--- Measurement ---*/
void loop(void) {
  // Every second, calculate and print the measured value
  currentTime = millis();                     // Get the current "time"
  
  if ((currentTime - startTime) >= period) {  // Test whether the period has elapsed
    getVolt(sigPin);

    /*--- Sensor prompt ---*/
    Serial.print("Voltage: ");
    Serial.print(vOut, 4);
    Serial.println(" V");

    /*--- System Return ---*/
    startTime = currentTime;  // Save the start time of the current state
  } else {
    return;
  }
}

/*--- Functions Definition ---*/
// Implementation of Analog Voltage Reading
void getVolt(byte signalPin) {
  for (unsigned int i = 0UL; i < N; ++i) {    // Get samples for smooth the value
    vOut = vOut + analogRead(signalPin);
    delay(1);                                 // delay in between reads for stability
  }
  vOut = (vOut * vConv) / N;                  // ADC of voltage meter output voltage

  if (isinf(vOut) || isnan(vOut)) {
    vOut = -1;
  }
}
