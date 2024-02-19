#include "config.h"
#include "lib/relay.h"
#include "lib/ultrasonic.h"

int
    waitingKitchen = 0,
    waitingBathroom = 0;

bool
    statusPir = false,
    statusKitchen = false,
    statusBathroom = false;

void setup(){
  Serial.begin(9600);
  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_RELAY_KITCHEN, OUTPUT);
  pinMode(PIN_RELAY_BATHROOM, OUTPUT);
}

void loop(){
  serialMonitor(
    Kitchen(HCSR04(PIN_TRIG, PIN_ECHO, "cm")), 
    Bathroom(digitalRead(PIN_PIR))
  );
}
