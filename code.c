/*
  Created by: Michael Bruneau
  Created on: March 2025

  This Arduino program displays the distance from the sonar and turns on an LED if an object gets too close to the sonar
*/

// variables & constants
const int TRIG_PIN = 11;
const int ECHO_PIN = 10;
const int LED__POWER_PIN = 8;
long duration;
int distance = 0;
int trigDelays[] = {2, 10};
int TOO_CLOSE = 20;
const float SPEED_OF_SOUND = 0.034;

void setup()
{
  // Setups pins
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  	// sends pulse
  	digitalWrite(TRIG_PIN, LOW);
  	delayMicroseconds(trigDelays[0]);
  	digitalWrite(TRIG_PIN, HIGH);
  	delayMicroseconds(trigDelays[1]);
  	digitalWrite(TRIG_PIN, LOW);
  
 	//receives pulse
  	duration = pulseIn(ECHO_PIN, HIGH);
      
    // Calculating the distance
  	distance = duration * SPEED_OF_SOUND / 2;

  	// Prints the distance on the Serial Monitor
  	Serial.print("Distance: ");
  	Serial.println(distance);
    Serial.println(" cm");
  
  	// Turns on LED if a object gets close to the sonar
  	if (distance <= TOO_CLOSE) {
    	digitalWrite(LED__POWER_PIN, HIGH);
    } else {
    	digitalWrite(LED__POWER_PIN, LOW);
    }
        
}
