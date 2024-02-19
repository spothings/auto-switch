void KitchenLamp(bool _status){
  statusKitchen = _status;
  Relay(PIN_RELAY_KITCHEN, statusKitchen);
  if (statusKitchen) waitingKitchen = WAITING_KITCHEN;
}

String Kitchen(bool _pir){
  if (waitingKitchen <= 0) {
    KitchenLamp(_pir);
  } else {
    if (statusPir != _pir) {
      statusPir = _pir;
      waitingKitchen = WAITING_KITCHEN;
    } else if (!_pir) {
      waitingKitchen--;
    }
  }
  return _pir ? "true" : "false";
}