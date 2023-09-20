
#include "AH_MCP4922.h"
#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];
#define CS_PIN 11
#define RST_PIN 10
UTFT myGLCD(ILI9486, CS_PIN, RST_PIN);

int xPos, yPos;         // 
int value;              // 
int pushButton = 2;     // Currently not using
    



// ***************************************
// **************** SETUP ****************
// ***************************************

void setup()
   { 
    Serial.begin(9600);                          // Init serial interface 
    
    // Setup the LCD
    myGLCD.InitLCD();
    myGLCD.setFont(SmallFont);    
    myGLCD.clrScr();
   } 



// *******************************************
// ************** HAUPTSCHLEIFE **************
// *******************************************
char Sonographie[] = "Sonographie - stoppi" ;
void loop()
   {
    myGLCD.setColor(255, 255, 0);
    myGLCD.fillRect(0, 0, 479, 13);
    myGLCD.setColor(0, 0, 0);
    myGLCD.setBackColor(255, 255, 0);
    myGLCD.print(Sonographie, CENTER, 1); 
        
    for (yPos = 0; yPos < 101; yPos++)
       {
        for (xPos = 0; xPos < 160; xPos++)
           {
            value = random(1023);
            
            value = map(value,0,1023,0,255);
            
            myGLCD.setColor(value, value, value);
            myGLCD.fillRect(xPos * 3, 15 + yPos * 3, xPos * 3 + 2, 15 + yPos * 3 + 2);
            //myGLCD.drawPixel(xPos, 15 + yPos);
           }       
        
        
        yPos++;
        
        for (xPos = 159; xPos >= 0; xPos--)
           {
            value = random(1023);
    
            value = map(value,0,1023,0,255);
       
            myGLCD.setColor(value, value, value);
            myGLCD.fillRect(xPos * 3, 15 + yPos * 3, xPos * 3 + 2, 15 + yPos * 3 + 2);
            //myGLCD.drawPixel(xPos, 15 + yPos);
       
           }       
        
       } 
       
   }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
