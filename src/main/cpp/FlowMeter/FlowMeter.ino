/* Copyright [yyyy] [name of copyright owner]
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Measuring the rising edges of the signal
volatile int NbTopsFan;

int result;

// The pin location of the sensor
int hallsensor = 2;

/*
 * This is the function that the interupt calls
 */
void rpm ()
{
    // Measure the rising and falling edge of the hall effect sensors
    // signal
    NbTopsFan++;
}

void readFlowMeter()
{
 NbTopsFan = 0;        // Set NbTops to 0 ready for calculations
 sei();                // Enables interrupts
 delay (1000);         // Wait 1 second
 cli();                // Disable interrupts
 result = (NbTopsFan * 60 / 7.5); // (Pulse frequency x 60) / 7.5Q, = flow rate in L/hour

 Serial.print (result, DEC); // Prints the number calculated above
 Serial.print (" L/hour\r\n"); // Prints "L/hour" and returns a  new line
}

/*
 * Runs once, when the sketch starts
 */
void setup() //
{
 pinMode(hallsensor, INPUT); // Initializes digital pin 2 as an input
 Serial.begin(9600);         // This is the setup function where the serial port is initialised,

 attachInterrupt(0, rpm, RISING); //and the interrupt is attached
}

/*
 * the loop() method runs over and over again,
 * as long as the Arduino has power
 */
void loop ()
{
    readFlowMeter();
}
