#include "lib/ultrasonic.h"
#include "lib/relay.h"

#define WAITINGKITCHEN 6000
#define WAITINGBATHROOM 100
#define DISTANCEULTRASONIC 60

const uint8_t
    PIR = 2,
    TRIG = 3,
    ECHO = 4,
    KITCHEN = 5,
    BATHROOM = 6;

uint8_t
    waitingKitchen,
    waitingBathroom;

bool
    statusPir,
    statusKitchen,
    statusBathroom;

void setup()
{
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(KITCHEN, OUTPUT);
  pinMode(BATHROOM, OUTPUT);

  statusKitchen = false;
  statusBathroom = false;
}

void loop()
{
  // Kitchen
  bool pir = digitalRead(PIR);
  if (waitingKitchen <= 0)
  {
    KitchenLamp(pir);
  }
  else
  {
    if (statusPir != pir)
    {
      statusPir = pir;
      waitingKitchen = WAITINGKITCHEN;
    }
    else if (!pir)
    {
      waitingKitchen--;
    }
  }

  // Bathroom
  unsigned short int ultrasonic = HCSR04(TRIG, ECHO, "cm");
  if (waitingBathroom <= 0)
  {
    if (ultrasonic < DISTANCEULTRASONIC)
    {
      Relay(BATHROOM, !statusBathroom);
      statusBathroom = !statusBathroom;
      waitingBathroom = WAITINGBATHROOM;
    }
  }
  else
  {
    waitingBathroom--;
  }

  SerialMonitor(pir, ultrasonic);
}

void SerialMonitor(int _pir, int _ultrasinic)
{
  Serial.print(_pir);
  Serial.print("\t");
  Serial.print(waitingKitchen);
  Serial.print("\t");
  Serial.print(statusKitchen);
  Serial.print(" | ");
  Serial.print(_ultrasinic);
  Serial.print("\t");
  Serial.print(waitingBathroom);
  Serial.print("\t");
  Serial.print(statusBathroom);
  Serial.print("\n");
}

void KitchenLamp(int _pir)
{
  statusKitchen = _pir;
  Relay(KITCHEN, statusKitchen);
  if (_pir)
  {
    waitingKitchen = WAITINGKITCHEN;
  }
}