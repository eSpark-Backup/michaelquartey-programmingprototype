
#include <TFT_HX8357_Due.h> // Hardware-specific library

TFT_HX8357_Due tft = TFT_HX8357_Due();       // Invoke custom library

#define CENTRE 240

int gray_value;

void setup()
{
  Serial.begin(38400);
  
  // Setup the LCD
  tft.init();
  tft.setRotation(1);
  
  tft.fillScreen(TFT_BLACK);
}

void loop()
{
  

  tft.fillRect(0, 0, 480, 14, tft.color565(210, 210, 210));

  tft.setTextColor(tft.color565(255, 255, 0),tft.color565(210, 210, 210));

  tft.drawCentreString("Sonographie - stoppi", CENTRE, 3, 1);
  
  
  
  tft.drawRoundRect(100, 100, 100, 100, 10, (uint16_t)tft.color565(100, 100, 100));  


  
  for(int j = 0; j < 102; j++)
     {
      for(int i = 0; i < 160; i++)
         {
          gray_value = 2*i; //random(255);
         
          tft.fillRect(i * 3, 15 + j * 3, 3, 3, (uint16_t) tft.color565(gray_value, gray_value, gray_value));   // Format = (x_start, y_start, x_Breite, y_Breite, Farbe)
                                                                                                     // ======================================================

                   
          //tft.fillRect(i * 3, 15 + j * 3, 3, 3, tft.color565(0, 0, 0));   // Format = (x_start, y_start, x_Breite, y_Breite, Farbe)
          
          //tft.fillRect(100, 15 + 20, 2, 40, tft.color565(gray_value, gray_value, gray_value));
          
          delay(1);
         }
     }
}
