/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Sc0ott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(4, HIGH);   // allumer la LED  rouge 1 (HIGH is the voltage level)
  digitalWrite(5, HIGH);   // allumer la LED verte 2 (HIGH is the voltage level)
  delay (3000);               // attendre 3 seconde
  digitalWrite(5, LOW);   // eteindre la LED verte 2 (LOW is the voltage level)
  digitalWrite(6, HIGH);   // allumer la LED jaune 2 (HIGH is the voltage level)
  delay (1000);               //attendre 1 seconde
  digitalWrite(4, LOW);   // eteindre la LED rouge 1 (HIGH is the voltage level)
  digitalWrite(6, LOW);   // eteindre la LED jaune 2 (LOW is the voltage level)
  digitalWrite(7, HIGH);   // eteindre la LED rouge 2 (LOW is the voltage level)
  digitalWrite(2, HIGH);   // allumer la LED verte 1 (HIGH is the voltage level)
  delay (3000);               // attendre 3 seconde
  digitalWrite(2, LOW);   // eteindre la LED verte 1 (LOW is the voltage level)
  digitalWrite(3, HIGH);   // allumer la LED jaune 1 (HIGH is the voltage level)
  delay (1000);              // attendre 1 seconde
  digitalWrite(7, LOW);   // eteindre la LED rouge 2 (LOW is the voltage level)
  digitalWrite(3, LOW);   // eteindre la LED jaune 1 (HIGH is the voltage level)
}
