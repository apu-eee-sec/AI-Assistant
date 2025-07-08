#include <UrlEncode.h> //encoding
//#include "Arduino.h"

#include "Audio.h"

const char* Voicerss_apiKey = "apiKey";


#define I2S_DOUT     6
#define I2S_BCLK     4//4
#define I2S_LRC      7//7
Audio audio;
void audio_begin() {
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
}
void audio_volume(int vol) {
  audio.setVolume(vol);
}
void audio_tts(String txt) {
  String url = String("https://api.voicerss.org/?key=") + Voicerss_apiKey + "&hl=en-au&c=MP3&v=Isla&f=16khz_16bit_mono&src=" + urlEncode(txt);
    audio.connecttohost(url.c_str());
//  audio.connecttospeech("Bangladesh is a country, not a city or county. It is located in South Asia", "en"); // Google TTS
//  audio.connecttohost("https://radio.talksport.com/stream?gdpr=0&partnerId=RadioTime");
  while (audio.isRunning()) audio.loop();
}
void audio_info(const char *info) {
  Serial.print("audio_info: "); Serial.println(info);
}
