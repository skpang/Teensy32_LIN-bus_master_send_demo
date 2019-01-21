/*
 * This is a Teensy 3.2 LIN-Bus demo using this board:
 * http://skpang.co.uk/catalog/teensy-canbus-and-linbus-breakout-board-include-teensy-32-p-1566.html
 * 
 * It is used to control the Microchip APGRD004 LIN RGB LED.
 * 
 * skpang.co.uk 2019
 * 
 * 
 */
#include "lin-bus.h"

int led = 13;
int lin_cs = 23;
int tx_pin = 1;

lib_bus lin(BAUD_9600,1);

uint8_t lin_data[8]; 
void setup() 
{
  pinMode(led, OUTPUT);    
  pinMode(lin_cs, OUTPUT); 
  digitalWrite(led, HIGH);   
  digitalWrite(lin_cs, HIGH);    
  
  delay(1000);  
  Serial.begin(11520);            // Configure serial port for debug
  Serial.print("LIN-bus test");

  delay(100);
   
  digitalWrite(led, LOW); 
}

void loop() 
{
   lin_data[0] = 0x1F; 
   lin_data[1] = 0x00;
   lin_data[2] = 0x80;    // Green
   lin_data[3] = 0x00;
   lin_data[4] = 0x0f;   
   lin.write(0x23, lin_data, 5); 
   delay(100); 

   lin_data[0] = 0x1F;
   lin_data[1] = 0x80;    // Red
   lin_data[2] = 0x00;
   lin_data[3] = 0x00;
   lin_data[4] = 0x0f; 
   lin.write(0x23, lin_data, 5); 

   delay(100); 

   lin_data[0] = 0x1F;
   lin_data[1] = 0x00;
   lin_data[2] = 0x00;
   lin_data[3] = 0x80;    // Blue
   lin_data[4] = 0x0f; 
   lin.write(0x23, lin_data, 5);


   digitalWrite(led, HIGH);   
   delay(100); 
   digitalWrite(led, LOW);  
}
