void SPIFFS_begin() {
  // Initialize SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS initialisation failed!");
    while (1) yield();
  }
  else Serial.println("SPIFFS Init successful");
}
