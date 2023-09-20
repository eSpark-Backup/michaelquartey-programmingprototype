#include "Arduino.h"
#define pin_output 14
#define pin_input_magnification 12
#define pin_input_sleep 13

#define ADC0_Pin A0 /* ESP8266 Analog Pin ADC0 = A0 */
#define CS_PIN 11
#define RST_PIN 10

unsigned long start_time;
unsigned long stop_time;
unsigned int values[600];  //

int i, j;
int Trigger_time;  //
int gray_value;

#define CENTRE 240

#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];

UTFT myGLCD(ILI9486, CS_PIN, RST_PIN);


// =========================
// ========= SETUP =========
// =========================
char US_0_[] = "0 us";
char US_20_[] = "20 us";

char US_40_[] = "40 us";
char US_60_[] = "60 us";

char US_80_[] = "80 us";
char US_100_[] = "100 us";

char US_120_[] = "120 us";
char US_140_[] = "140 us";

char US_160_[] = "160 us";
char US_180_[] = "180 us";

char US_200_[] = "200 us";
char US_220_[] = "220 us";

char US_240_[] = "240 us";


void setup() {
  Serial.begin(115200);

  //REG_ADC_MR = 0x10380080;  // change from 10380200 to 10380080, 1 is the PREESCALER and 8 means FREERUN

  // ADC->ADC_CHER = 0x03;               // enable ADC on pin A7

  pinMode(pin_output, OUTPUT);
  pinMode(pin_input_magnification, INPUT);  // Switch-input for magnification
  pinMode(pin_input_sleep, INPUT);          // Switch-input for sleep-mode
  pinMode(ADC0_Pin, INPUT);

  digitalWrite(pin_output, LOW);

  Trigger_time = 1;  //

  // Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  myGLCD.clrScr();

  myGLCD.setColor(255, 255, 0);
  myGLCD.fillRect(0, 0, 432, 13);
  myGLCD.setColor(0, 0, 0);
  myGLCD.setBackColor(255, 255, 0);
}



// ========================
// ========= LOOP =========
// ========================


void loop() {
  for (j = 0; j < 18; j++)  //
  {
    //
    // ==========================

    digitalWrite(pin_output, HIGH);
    //delayMicroseconds(Trigger_time);
    digitalWrite(pin_output, LOW);



    //
    // ===========================

    //start_time = micros();

    if (digitalRead(pin_input_magnification) == LOW)  //
    {
      for (i = 0; i < 300; i++) {
        //while((ADC->ADC_ISR) & 0x03)==0);  // wait for conversion

        values[i] = analogRead(ADC0_Pin);  // ADC->ADC_CDR[0];      //get values

        //delayMicroseconds(1);
      }
    } else  //
    {
      for (i = 0; i < 600; i++) {
        // while((ADC->ADC_ISR & 0x03)==0);  // wait for conversion

        values[i] = analogRead(ADC0_Pin);  //get values

        //delayMicroseconds(1);
      }
    }

    //delayMicroseconds(100);
    //delay(5);

    /*
        stop_time = micros();

        Serial.print("Total time for 300 values: ");
        Serial.print(stop_time-start_time);
        Serial.println(" microseconds");
        Serial.print("Average time in microseconds per conversion: ");
        Serial.println((float)(stop_time-start_time)/300);
        */

    /*
        Serial.println("Values: ");
        
        for(i = 0;i < 600; i++)
           {
            Serial.println(values[i]);
           }
        */


    // ==================

    if (digitalRead(pin_input_magnification) == LOW)  //
    {
      myGLCD.setColor(255, 255, 255);
      myGLCD.setBackColor(0, 0, 0);
      myGLCD.drawLine(440, 15, 440, 15 + 300);
      myGLCD.drawLine(440, 15, 445, 15);
      myGLCD.drawLine(440, 65, 445, 65);
      myGLCD.drawLine(440, 115, 445, 115);
      myGLCD.drawLine(440, 165, 445, 165);
      myGLCD.drawLine(440, 215, 445, 215);
      myGLCD.drawLine(440, 265, 445, 265);
      myGLCD.drawLine(440, 315, 445, 315);


      myGLCD.print(US_0_, 450, 10);
      myGLCD.print(US_40_, 450, 60);
      myGLCD.print(US_80_, 450, 110);
      myGLCD.print(US_120_, 450, 160);
      myGLCD.print(US_160_, 450, 210);
      myGLCD.print(US_200_, 450, 260);
      myGLCD.print(US_240_, 450, 310);
      for (i = 0; i < 300; i++) {
        values[i] = map(values[i], 0, 4095, 0, 255);  //

        //values[i] = random(255);

        myGLCD.setColor(values[i], values[i], values[i]);
        myGLCD.fillRect(j * 24, 15 + i, j * 24 + 23, 15 + i);
      }
    } else  //
    {
      myGLCD.setColor(255, 255, 255);
      myGLCD.setBackColor(0, 0, 0);
      myGLCD.drawLine(440, 15, 440, 15 + 300);
      myGLCD.drawLine(440, 15, 445, 15);
      myGLCD.drawLine(440, 65, 445, 65);
      myGLCD.drawLine(440, 115, 445, 115);
      myGLCD.drawLine(440, 165, 445, 165);
      myGLCD.drawLine(440, 215, 445, 215);
      myGLCD.drawLine(440, 265, 445, 265);
      myGLCD.drawLine(440, 315, 445, 315);

      myGLCD.print(US_0_, 450, 10);
      myGLCD.print(US_20_, 450, 60);
      myGLCD.print(US_40_, 450, 110);
      myGLCD.print(US_60_, 450, 160);
      myGLCD.print(US_80_, 450, 210);
      myGLCD.print(US_100_, 450, 260);
      myGLCD.print(US_120_, 450, 310);

      for (i = 0; i < 300; i++) {
        values[2 * i] = map(values[2 * i], 0, 4095, 0, 255);  //

        //values[2*i] = random(255);

        myGLCD.setColor(values[2 * i], values[2 * i], values[2 * i]);
        myGLCD.fillRect(j * 24, 15 + i, j * 24 + 23, 15 + i);
      }
    }


    //
    // =====================

    if (digitalRead(pin_input_sleep) == HIGH) {
      while (digitalRead(pin_input_sleep) == HIGH) {
        // sleeping
      }
    }

    delay(1000);
  }
}
