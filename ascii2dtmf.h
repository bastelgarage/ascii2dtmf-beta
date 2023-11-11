#ifndef ascii2dtmf_h
#define ascii2dtmf_h

#include "Arduino.h"

class ascii2dtmf {
    public:
        ascii2dtmf();
        void encodeToDTMF(char asciiChar, char &tone1, char &tone2);
        char decodeFromDTMF(char tone1, char tone2);

    private:
        char dtmfTones[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', '*', '#'};
};

#endif
