// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Mohamed Samir silaya
// Using Arduino IDE 1.6.7
// Using HC-SR04 Module
// Tested on 7 December 2021
// ---------------------------------------------------------------- //
//********* if you want to change pin legs only change here ********
#define echoPin 2  // attach pin Digital 2  to pin Echo 
#define trigPin 3  // attach pin Digital 3  to pin Trig 
#define buzzer  11 // attach pin Digital 11
#define motor   5  // attach pin 5


// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(motor,OUTPUT);      //motor set up for circut ->*https://techzeero.com/arduino-tutorials/vibration-motor-with-arduino/*
  pinMode(buzzer,OUTPUT);    // buzzer setup
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  
}
void loop() {

  // Clear the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor 
  // if you want to check your results 
 /* Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm"); 
  */
  // the range while buzzer will work the scale in cm
if ( 10 < distance  &&  distance <15) 
{
  //this function use to play the buzzer by passing the frequency 
tone(buzzer,200);


}

else if ( 2 < distance  &&  distance <10)
{
tone(buzzer,200);

 digitalWrite(motor, HIGH); //vibrate
  
 
 
}
//Do No thing
else 
{
  noTone(buzzer);
   digitalWrite(motor, LOW);  //stop vibrating
  
 }






  
}

