#define CE_PIN 9
#define CSN_PIN 10 

#include <SPI.h>
#include "RF24.h"

RF24 radio(CE_PIN, CSN_PIN);

byte address[11] = "Sandro";
unsigned long payload = 0;
int led = 5; //PWM

void setup() {
  Serial.begin(115200);
  radio.begin(); // Poner en marcha la radio
  radio.setAutoAck(1); // Asegurar qee autoACK  esta habilitado
  radio.setRetries(15,15); //Máximo retardo entre reintentos y número de reintentos
  radio.openReadingPipe(1, address); //Escriba a la dirección del dispositivo
  radio.startListening();
}

void loop(void){
  pinMode(led, OUTPUT); // Habilitado como salida
  radio.stopListening();
  radio.startListening();
  radio.read( &payload, sizeof(unsigned long) );
  if(payload != 0){
    Serial.print("Escucha ");
    analogWrite(led, int (payload));
    Serial.println(payload);
  }
  delay(100);
}
