#include <HTTPClient.h> //for SPIFFS AssemblyAI and Gemini
#include <ArduinoJson.h> //for SPIFFS AssemblyAI and Gemini
String extractAnswer(const String& response) {
  StaticJsonDocument<2048> doc;
  byte trying = 0;
t:
  DeserializationError error = deserializeJson(doc, response);
  if (error) {
    Serial.println("Failed to parse response.trying");
    trying++;
    if (trying <= 3) goto t;
    else return "Failed to parse response.";
  }

  // Extract the answer from the JSON response
  JsonArray candidates = doc["candidates"];
  if (candidates.isNull() || candidates.size() == 0) {
    Serial.println("No candidates found in response.trying");
    trying++;
    if (trying <= 3) goto t;
    else return "No candidates found in response.";
  }

  const char* text = candidates[0]["content"]["parts"][0]["text"];
  if (text == nullptr) {
    Serial.println("No text found in response.trying");
    trying++;
    if (trying <= 3) goto t;
    else return "No text found in response.";
  }

  String answer = String(text);

  // Remove Markdown formatting
  answer.replace("**", "");
  answer.replace("*", "");
  answer.replace("##", "");
  answer.replace("#", "");

  return answer;
}
void get_geminiResponse(String question) {
  // Make HTTP POST request to Gemini AI API
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(apiUrl);
    http.addHeader("Content-Type", "application/json");
    
    // Construct JSON request body
    String requestBody = "{\"contents\":[{\"parts\":[{\"text\":\"" + question + question_End + "\"}]}],"
                         "\"generationConfig\": {\"temperature\": " + temperature + ", \"maxOutputTokens\": " + maxOutputTokens + "}}";

    int httpResponseCode = http.POST(requestBody);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("HTTP Response code: " + String(httpResponseCode));
      Serial.println("Response: " + response);

      // Extract the answer text and remove Markdown formatting
      answer = extractAnswer(response);
      
      Serial.println("Answer: " + answer);
//       if (answer != "") audio_tts(answer);
    } else {
      Serial.println("Error on HTTP request");
    }
    http.end();
  }
//  transcriptionText = ""; //clean assembly ai response
}
