/*  
    This is an example using the flash memory on-board the CC430 processor.
    This example uses the LEDs on pins 1-6 on the souvenir sprites.
    Using this code the sprite will cycle throught the LEDs in order.
    If the power cable is unplugged (or if the sprite goes out of the sun)
    Upon reboot it will go straight to the LED it left on
    However, although very unlikely, if the power is disconected at the exact moment
    thats the erase command is being carried out, then upon reboot it will start the 
    whole script from the beginning.
*/

#include "CCFlash.h"          //Include the function to allow the use of the flash memory

#define flash SEGMENT_D       //Use the flash segment D to write to

unsigned char p = 0;          //Set p as a character

void setup() 
{
  pinMode(1, OUTPUT);         //Set the LED pins as output pins
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  digitalWrite(1, LOW);       //Ensure all LEDs are off (not completely necessary)
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  
  
  Flash.read(flash, &p, 1);   //Read 'p' in the flash memory
  if ((!p=='A') && (!p=='B') && (!p=='C') && (!p=='D') && (!p=='E') && (!p=='F'))  //If 'p' is not A,B,C,D,E,F then: 
  {
      Flash.erase(flash);     //Clear the flash memory
      Flash.write(flash, (unsigned char*) "A" ,1);    //Write 'A' to the memory
  }
}

void loop() 
{
   
  Flash.read(flash, &p, 1);    //Read 'p' in the memory
  switch(p) 
  {
    case 'A':                 //If 'p' is 'A' then:
      digitalWrite(1, HIGH);  //Flash the LED on pin 1
      delay(500);
      digitalWrite(1, LOW);
      delay(500);
      Flash.erase(flash);     //Clear the memory and:
      Flash.write(flash, (unsigned char*) "B" ,1);  //Write 'B' to it
      break ;
    case 'B':                  //If 'p' is 'B' then:
      digitalWrite(2, HIGH);   //Flash the LED on pin 2
      delay(500);
      digitalWrite(2, LOW);
      delay(500);
      Flash.erase(flash);      //CLear the memory and:
      Flash.write(flash, (unsigned char*) "C" ,1);  //Write 'C' to it
      break ;
    case 'C':                  //If 'p' is 'C' then:
      digitalWrite(3, HIGH);   //Flash the LED on pin 3
      delay(500);
      digitalWrite(3, LOW);
      delay(500);
      Flash.erase(flash);      //Clear the memory and:
      Flash.write(flash, (unsigned char*) "D" ,1);  //Write 'D' to it
      break ;
    case 'D':                  //If 'p' is 'D' then:
      digitalWrite(4, HIGH);   //Flash the LED on pin 4
      delay(500);
      digitalWrite(4, LOW);
      delay(500);
      Flash.erase(flash);     //Clear the memory and:
      Flash.write(flash, (unsigned char*) "E" ,1);  //Write 'E' to it
      break ;
    case 'E':                 //If 'p' is 'E' then:
      digitalWrite(5, HIGH);  //Flash the LED on pin 5
      delay(500);
      digitalWrite(5, LOW);
      delay(500);
      Flash.erase(flash);     //Clear the memory and:
      Flash.write(flash, (unsigned char*) "F" ,1);  //Write 'F' to it
      break ;
    case 'F':                 //If 'p' is 'F' then:
      digitalWrite(6, HIGH);  //Flash the LED on pin 6
      delay(500);
      digitalWrite(6, LOW);
      delay(500);
      Flash.erase(flash);     //Clear the memory and:
      Flash.write(flash, (unsigned char*) "A" ,1);  //Write 'A' to it
      break ;
  }
}
