#include<WiFiManager.h>
void wifi_begin(){
  WiFiManager wifi;
  Serial.println("Reset wifi: type 1 ");
  while (Serial.available() == 0) {}
  String auto_reconnect = Serial.readString(); // Read the incoming string
  if(auto_reconnect.toInt()==1)wifi.resetSettings();
  if (Serial.readStringUntil('\n') == "") {} //clearing buffer
  bool res =wifi.autoConnect("Ai Assistant","password111");
  if (!res) {
    Serial.println("Failed to connect Wifi");
  } else {
    Serial.println("Wifi Connected");
  }
}
