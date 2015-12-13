/*
Adafruit Arduino - Lesson 14. Sweep
*/

#include <Servo.h> 

int servoPin = 9;
 
Servo servo;  
 
int angle = 0;   // servo position in degrees 
const int buttonPin = 2;     // the number of the pushbutton pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
const int ledPin =  13;      // the number of the LED pin

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);     
  servo.attach(servoPin); 
}


 
void loop() 
{ 
    // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
    for(angle = 10; angle < 120; angle++)  
    {                                  
      servo.write(angle);               
      delay(10);                   
    } 
    // now scan back from 180 to 0 degrees
    for(angle = 120; angle > 10; angle--)    
    {                                
      servo.write(angle);           
      delay(15);       
    } 
  }
}

