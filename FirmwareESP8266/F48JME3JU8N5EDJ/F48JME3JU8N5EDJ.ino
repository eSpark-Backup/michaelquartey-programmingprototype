unsigned long start_time;
unsigned long stop_time;
unsigned long values[100];
#define ADC0_Pin A0 /* ESP8266 Analog Pin ADC0 = A0 */

void setup()
 {        
  Serial.begin(9600);  
  
  // adc_init(ADC, SystemCoreClock, 21000000UL, ADC_STARTUP_FAST);

  // //analogReadResolution(10);
  
  // ADC->ADC_MR |= 0x80;  //set free running mode on ADC
  // //ADC->ADC_CR=2;
  // ADC->ADC_CHER = 0x80; //enable ADC on pin A0
  pinMode(ADC0_Pin, INPUT);


 }

void loop()
 {
  unsigned int i;
    
  start_time = micros();
  
  for(i=0;i<100;i++)
   {
    //while((ADC->ADC_ISR & 0x80)==0); // wait for conversion
    values[i]= analogRead(ADC0_Pin); //get values
   }
  
  stop_time = micros();

  Serial.print("Total time: ");
  Serial.println(stop_time-start_time); 
  Serial.print("Average time per conversion: ");
  Serial.println((float)(stop_time-start_time)/100);

  Serial.println("Values: ");
  
  for(i=0;i<100;i++)
   {
    Serial.println(values[i]);
   }
  
  delay(8000);
 }
