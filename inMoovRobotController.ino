//IbraTech Arm Mover Code
//Moves the inMoov robot arm based on the input of a potentiometer
#include <Servo.h>

Servo fingers[5];  // Array containing Servo objects (to control the fingers)

int potpin = 0;  // Pin which potentiometer is connected to
int val;    // Value read from potPin

void setup() { //Setup function - Code that runs once
  for (int i = 0; i < 5; i++){ //For loop, runs while i is less than 5. i starts at 0 and increments once everytime the loop runs
    fingers[i].attach(i); //Initializes each servo object in fingers to it's corresponding pin (0-4)
  }
  //Generally here we would put pinMode(potPin, INPUT), but pins are input by default so it's not necissary
}

void loop() { //Looping function - Code that loops
  val = analogRead(potpin);            // Reading the value from the potentiometer
  //The above value is between 0 and 1023
  //Servos want values from 0 and 180
  val = map(val, 0, 1023, 0, 180);     // Here we "scale" the value and constrain it work with servos (0-180)
  for (Servo s: fingers){ //Different type of for loop, called a foreach loop. Iterates through every entry in the fingers array
    s.write(val);
  }
}
