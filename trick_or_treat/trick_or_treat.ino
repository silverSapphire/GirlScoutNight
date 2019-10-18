/*
 * created by Rui Santos, https://randomnerdtutorials.com
 * 
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */

#include <Servo.h>

Servo servo;

int val;

int trigPin1 = 13;    // Trigger
int echoPin1 = 12;    // Echo

int trigPin2 = 4;
int echoPin2 = 3;
long duration1, duration2, inches1, inches2;
 
void setup() {

  servo.attach(9);
  
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}
 
void loop() {

  if(inches1 < 10)
  {
    servo.write(180);
  }
  else
  {
    servo.write(0);
  }
  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration1 = pulseIn(echoPin1, HIGH);
 
  // Convert the time into a distance
  inches1 = (duration1/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  Serial.print(inches1);
  Serial.println();
  
  delay(250);
}
