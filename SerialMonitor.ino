String question = "";
void serialMonitor() {
  Serial.println("Ask a Question: ");
  while (Serial.available() == 0) {}
  question = Serial.readString(); // Read the incoming string
  question.trim(); // Remove any trailing newline or spaces
  Serial.print("Your Question: ");
  Serial.println(question); // Print the received string
  get_geminiResponse(question);
  if (answer != "") audio_tts(answer);
  answer="";
  question = "";
  if (Serial.readStringUntil('\n') == "") {} //clearing buffer
}
