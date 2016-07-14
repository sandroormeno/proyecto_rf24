#define CE_PIN 3
#define CSN_PIN 8

#include <SPI.h>
#include "RF24.h"

RF24 radio(CE_PIN, CSN_PIN);

byte address[11] = "SimpleNode";
//unsigned long payload = 0;

void setup() {
  radio.begin(); // Start up the radio
  radio.setAutoAck(1); // Ensure autoACK is enabled
  radio.setRetries(15,15); // Max delay between retries & number of retries
  radio.openWritingPipe(address); // Write to device address 'SimpleNode'
}

void loop(void){
  for(int i = 0; i <=255; i++){
    //payload++;
  radio.write( &i, sizeof(unsigned long) ); 
  } 
  delay(30);
}
