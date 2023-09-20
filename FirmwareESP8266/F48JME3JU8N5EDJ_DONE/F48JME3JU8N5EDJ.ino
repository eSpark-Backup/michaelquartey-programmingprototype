#include "user_interface.h"
#include "core_esp8266_wiring_analog.cpp"


#define num_samples 100
#define ADC0_Pin A0 /* ESP8266 Analog Pin ADC0 = A0 */

uint16_t adc_num = num_samples;
uint8_t adc_clk_div = 4;
uint16_t values[num_samples];
unsigned long start_time;
unsigned long stop_time;

void setup() {
  Serial.begin(115200);
  pinMode(ADC0_Pin, INPUT);
}

void loop() {
  unsigned int i;

  start_time = micros();

  system_adc_read_fast(values, adc_num, adc_clk_div);

  stop_time = micros();

  Serial.print("Total time: ");
  Serial.println(stop_time - start_time);
  Serial.print("Average time per conversion: ");
  Serial.println((float)(stop_time - start_time) / 100);

  Serial.println("Values: ");

  for (i = 0; i < 100; i++) {
    Serial.println(values[i]);
  }

  delay(8000);
}