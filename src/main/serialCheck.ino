void serialMonitor(String _pir, uint16_t _ultrasinic){
  if(!SERIALMONITOR) return;
  Serial.print(_pir);
  Serial.print("\t");
  Serial.print(waitingKitchen);
  Serial.print("\t");
  Serial.print(statusKitchen ? "on" : "off");
  Serial.print(" | ");
  Serial.print(_ultrasinic);
  Serial.print("\t");
  Serial.print(waitingBathroom);
  Serial.print("\t");
  Serial.print(statusBathroom ? "on" : "off");
  Serial.print("\n");
}