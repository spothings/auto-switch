int Ultrasonic(int _tring, int _echo, String _unit) {
  digitalWrite(_tring, LOW);
  delayMicroseconds(2);
  digitalWrite(_tring, HIGH);
  delayMicroseconds(10);
  digitalWrite(_tring, LOW);
  long duration = pulseIn(_echo, HIGH);

  if (_unit == "in") {
    return duration / 74 / 2;
  } else if (_unit == "cm"){
    return duration / 29.1 / 2;
  } else {
    return 0;
  }
}

int HCSR04(int _tring, int _echo, String _unit) {
  return Ultrasonic(_tring, _echo, _unit);
}

int HYSRF05(int _tring, int _echo, String _unit) {
  return Ultrasonic(_tring, _echo, _unit);
}