#include <SPIFFS.h> //for SPIFFS Storage

/*
   ----------------------------------------------------------------
         Necessary Variable for Gemini Ai Communication
   ----------------------------------------------------------------
*/
String apiKey = "Google API key"; // Replace with your Google API key
const String apiUrl = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash-latest:generateContent?key=" + apiKey;
const String maxOutputTokens = "100";
const String temperature = "1.0";
String answer;
const String question_End = " Used maximum 150 character don\'t use any enter or new line , also avoid any special characters and headline.";

void setup()
{
  //pinMode(8, OUTPUT);
  Serial.begin(115200);
  Serial.println("start");
  SPIFFS_begin();
  wifi_begin();
  delay(1500);
  Serial.println("start");
  audio_begin();
  audio_volume(20);
}


void loop()
{
  serialMonitor();
  //    audio_tts(ans);
}
