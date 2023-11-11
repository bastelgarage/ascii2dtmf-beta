#include "ascii2dtmf.h"

ascii2dtmf dtmfEncoder; // Erstelle eine Instanz der ascii2dtmf-Klasse

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Warte auf die serielle Verbindung
  }
  
  // Der zu übertragende Text
  const char* text = "Hello World!";
  Serial.println("Ursprünglicher Text: ");
  Serial.println(text);

  // Kodiere jeden Buchstaben in DTMF-Töne und sende sie
  Serial.println("Kodierte DTMF-Töne: ");
  for (int i = 0; text[i] != '\0'; i++) {
    char tone1, tone2;
    dtmfEncoder.encodeToDTMF(text[i], tone1, tone2);
    Serial.print(tone1);
    Serial.print(tone2);
    Serial.print(" ");
  }
  Serial.println();

  // Dekodiere die Töne zurück in Text
  Serial.println("Dekodierter Text: ");
  for (int i = 0; text[i] != '\0'; i+=2) {
    char decodedChar = dtmfEncoder.decodeFromDTMF(text[i], text[i+1]);
    Serial.print(decodedChar);
  }
  Serial.println();
}

void loop() {
  // Hier könnte weiterer Code stehen
}
