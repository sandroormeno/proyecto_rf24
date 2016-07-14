#define CE_PIN 3
#define CSN_PIN 8

#include <SPI.h>
#include "RF24.h"

RF24 radio(CE_PIN, CSN_PIN);

byte address[11] = "Sandro";
//unsigned long payload = 0;

void setup() {
  radio.begin(); // Poner en marcha la radio
  radio.setAutoAck(1); // Asegurar qee autoACK  esta habilitado
  radio.setRetries(15,15); //Máximo retardo entre reintentos y número de reintentos
  radio.openWritingPipe(address); // Escriba a la dirección del dispositivo
}

void loop(void){
  for(int i = 0; i <=60; i++){
    //payload++;
  radio.write( &i, sizeof(unsigned long) ); 
  } 
  delay(100);
}
