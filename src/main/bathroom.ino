void BathroomLamp(bool _status){
  statusBathroom = !_status;
  Relay(PIN_RELAY_BATHROOM, statusBathroom);
  waitingBathroom = WAITING_BATHROOM;
}

uint16_t Bathroom(uint16_t _ultrasonic){
  if (waitingBathroom <= 0) {
    if (_ultrasonic < DISTANCE_ULTRASONIC) BathroomLamp(statusBathroom);
  } else {
    waitingBathroom--;
  }
  return _ultrasonic;
}