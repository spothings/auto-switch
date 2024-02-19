#include "lib/relay.h"
#include "lib/ultrasonic.h"

#define WAITING_KITCHEN 6000
#define WAITING_BATHROOM 100
#define DISTANCE_ULTRASONIC 60

#define PIN_PIR 2
#define PIN_TRIG 3
#define PIN_ECHO 4
#define PIN_RELAY_KITCHEN 5
#define PIN_RELAY_BATHROOM 6

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