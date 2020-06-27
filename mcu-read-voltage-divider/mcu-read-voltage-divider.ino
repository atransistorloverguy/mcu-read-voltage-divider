/*
 * Simple Arduino voltage divider tutorial 
 * to measure any voltage above the operating voltage of the board/MCU
 *
 *
 * SMM's Blog - Shams El-Din Mohamed Abdul Monem 
 * All rights reserved 2020
*/

#define BAUD 9600 // Computer Serial speed
#define PIN A0 // Analog pin connected to the output of the voltage divider

const unsigned long r1 = 330;// the resistance of resistor 1 (R1) in "Ohms"
const unsigned long r2 = 220;// the resistance of resistor 2 (R2) in "Ohms"
const float sys_voltage = 4.91;// The voltage of the MCU, can be 3.3V, 5V or even as low as 1.8V!

float vout;// The output voltage from the resistor-divider (The voltage from the analoge pin)
float vin;// The true input voltage we want to mesure

int resoulotion = 1023; // ADC resoulotion, in arduinos UNO,Nano,Mini it's 1023

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUD);
}

void loop() {
  Serial.println(getVoltage());
  delay(100);
}

float getVoltage(){
  // Here we calculate the voltage the Arduino reads, 
  // which is the output voltage of the voltage divider
  int sensorValue = analogRead(PIN);
  float voltage = sensorValue * (sys_voltage / resoulotion);

  return calculate(r1, r2, voltage);
}

float calculate(unsigned long r_1, unsigned long r_2, float vout){
  /*
   The main rule is:
   Vout = Vin x (R2/R1+R2)

   the inverse of it:
   Vin = (Vout x (R1+R2)) / R2
  */
  return (vout*((float)r_1+(float)r_2) / (float)r_2);
}
