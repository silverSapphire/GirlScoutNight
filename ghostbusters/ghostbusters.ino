/* Use a photoresistor (or photocell) to turn on an LED in the dark
   More info and circuit schematic: http://www.ardumotive.com/how-to-use-a-photoresistor-en.html
   Dev: Michalis Vasilakis // Date: 8/6/2015 // www.ardumotive.com */

//Higher number = more light needed to turn off.
//Increase by increments of 10 to finetune.
//CHANGE THIS AUDREY :)
int threshold = 700;   

//Constants
const int pResistor1 = A0; // Photoresistor at Arduino analog pin A0
const int ledPin1=9;       // Led pin at Arduino pin 9
const int pResistor2 = A1;
const int pResistor3 = A2;
const int ledPin2 = 2;
const int ledPin3 = 3;

//Variables
int value1;          // Store value from photoresistor (0-1023)
int value2;
int value3;

void setup(){
 pinMode(ledPin1, OUTPUT);  // Set lepPin - 9 pin as an output
 pinMode(pResistor1, INPUT);// Set pResistor - A0 pin as an input (optional)
 pinMode(pResistor2, INPUT);
 pinMode(ledPin2, OUTPUT);
 pinMode(ledPin3, OUTPUT);
 pinMode(pResistor3, INPUT);
}

void loop(){
  value1 = analogRead(pResistor1);
  value2 = analogRead(pResistor2);
  value3 = analogRead(pResistor3);
  
  //You can change value "25"
  if (value1 < threshold){
    digitalWrite(ledPin1, HIGH);  
  }
  else{
    digitalWrite(ledPin1, LOW); 
  }

  if (value2 < threshold){
    digitalWrite(ledPin2, HIGH);  
  }
  else{
    digitalWrite(ledPin2, LOW); 
  }
  
  if (value3 < threshold) {
    digitalWrite(ledPin3, HIGH);  //Turn led off
  }
  else{
    digitalWrite(ledPin3, LOW); //Turn led on
  }
  
  delay(50); //Small delay
}
