void Relay(int _pin, bool _status) {
  if (_status) {
    digitalWrite(_pin, HIGH);
  } else {
    digitalWrite(_pin, LOW);
  }
}