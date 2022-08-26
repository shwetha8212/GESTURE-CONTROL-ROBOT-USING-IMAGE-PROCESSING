int motorA1 = 5; // Pin 2 of L293 
int motorA2 = 6; // Pin 7 of L293 
int motorB1 = 9; // Pin 10 of L293 
int motorB2 = 10; // Pin 14 of L293 
int vel = 255; // Speed Of Motors (0-255) 
char state = '0'; // Initialise Motors 
#define rxpin 7
#define txpin 8
//#include "SoftwareSerial.h"
//SoftwareSerial mySerial(rxPin, txPin); // RX, TX
//SoftwareSerial serial_connection(10, 11);   //Create a serial connection with TX and RX on these pins of bluetooth
void setup() { Serial.begin(9600); // Initialize serial communication at 115200 bits per second // Set pins as outputs 
    //serial_connection.begin(9600);    //Initialize communications with the bluetooth module
    pinMode(motorA1, OUTPUT); 
    pinMode(motorA2, OUTPUT); 
    pinMode(motorB1, OUTPUT); 
    pinMode(motorB2, OUTPUT);} 
void loop() { 
  if(Serial.available()>0){ // Reads from bluetooth and stores its 
         state = Serial.read(); }Serial.println(state);
         if(state==5 || state=='5'){ // Forward
      Serial.println(state);
      
      
      digitalWrite(motorA1, 1);
      digitalWrite(motorA2, 0);
      digitalWrite(motorB1, 1);
      digitalWrite(motorB2, 0); } 
      
        if(state==2 || state=='2'){ // Reverse 
       Serial.println(state); 
       digitalWrite(motorA1, 0); 
       digitalWrite(motorA2, 1); 
       digitalWrite(motorB1, 0); 
       digitalWrite(motorB2, 1); 
       } 
        if(state==3 || state=='3'){ // Right 
       Serial.println(state); 
       digitalWrite(motorA1, 1);
       digitalWrite(motorA2, 0); 
       digitalWrite(motorB1, 0); 
       digitalWrite(motorB2, 0); } 
       
        if(state==4 || state=='4'){ // Left 
       Serial.println(state);
       digitalWrite(13,1);
       digitalWrite(motorA1, 0); 
       digitalWrite(motorA2, 0);
       digitalWrite(motorB1, 1); 
       digitalWrite(motorB2, 0); }
        if(state==1 || state=='1'){ // Stop 
       Serial.println(state);
       digitalWrite(motorA1, 0); 
       digitalWrite(motorA2, 0); 
       digitalWrite(motorB1, 0);
       digitalWrite(motorB2, 0); } }
//       delay(2000);}
