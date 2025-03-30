/*
  Created by: Michael Bruneau
  Created on: March 2025

  This Arduio program displays distance from sonar and truns on LED if an object gets to close to the sonar
*/

// variables & constants
const int trigPin = 5;
const int echoPin = 6;
const int LEDPowerPin = 8;
long duration;
int distance = 0;
int trigDelays[] = {2, 10};
int too_close = 20;
const float speedOfSound = 0.034;

void setup()
{
  // Setups pins
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  	// sends pulse
  	digitalWrite(trigPin, LOW);
  	delayMicroseconds(trigDelays[0]);
  	digitalWrite(trigPin, HIGH);
  	delayMicroseconds(trigDelays[1]);
  	digitalWrite(trigPin, LOW);
  
 	//recieves pulse
  	duration = pulseIn(echoPin, HIGH);
      
    // Calculating the distance
  	distance = duration * speedOfSound / 2;

  	// Prints the distance on the Serial Monitor
  	Serial.print("Distance: ");
  	Serial.println(distance);
    Serial.println(" cm");
  
  	// Turns on LED if a object gets close to the sonar
  	if (distance <= too_close) {
    	digitalWrite(LEDPowerPin, HIGH);
    } else {
    	digitalWrite(LEDPowerPin, LOW);
    }
        
}
