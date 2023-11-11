#include "ascii2dtmf.h"

ascii2dtmf::ascii2dtmf() {
    // Konstruktor (falls benötigt)
}

void ascii2dtmf::encodeToDTMF(char asciiChar, char &tone1, char &tone2) {
    int asciiValue = (int)asciiChar;
    tone1 = dtmfTones[asciiValue / 16];
    tone2 = dtmfTones[asciiValue % 16];
}

char ascii2dtmf::decodeFromDTMF(char tone1, char tone2) {
    int tone1Index = findToneIndex(tone1);
    int tone2Index = findToneIndex(tone2);

    if (tone1Index == -1 || tone2Index == -1) {
        // Fehlerhafte Tonangaben
        return '\0'; // Rückgabe eines Null-Zeichens bei Fehlern
    }

    return (char)(tone1Index * 16 + tone2Index);
}

int ascii2dtmf::findToneIndex(char tone) {
    for (int i = 0; i < 16; i++) {
        if (dtmfTones[i] == tone) {
            return i;
        }
    }
    return -1; // Ton not found
}
