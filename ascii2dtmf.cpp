#include "ascii2dtmf.h"

YourLibraryName::YourLibraryName() {
    // Konstruktor (falls benötigt)
}

void ascii2dtmf::encodeToDTMF(char asciiChar, char &tone1, char &tone2) {
    int asciiValue = (int)asciiChar;
    tone1 = dtmfTones[asciiValue / 16];
    tone2 = dtmfTones[asciiValue % 16];
}

char ascii2dtmf::decodeFromDTMF(char tone1, char tone2) {
    int tone1Index = -1;
    int tone2Index = -1;

    // Finde die Indizes der Töne
    for (int i = 0; i < 16; i++) {
        if (dtmfTones[i] == tone1) tone1Index = i;
        if (dtmfTones[i] == tone2) tone2Index = i;
    }

    if (tone1Index == -1 || tone2Index == -1) return '\0'; // Fehlerfall

    return (char)(tone1Index * 16 + tone2Index);
}

