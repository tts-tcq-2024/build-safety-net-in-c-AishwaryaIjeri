#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Mapping of characters to Soundex codes
char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}

// Generate the Soundex code for a given name
void generateSoundex(const char *name, char *soundex) {
    if (!name || !soundex) {
        return; // Handle invalid pointers
    }

    int len = strlen(name);
    if (len == 0) {
        strcpy(soundex, "0000");
        return;
    }

    // Initialize the Soundex code
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    // Iterate over the remaining characters
    for (int i = 1; i < len && sIndex < 4; ++i) {
        char code = getSoundexCode(name[i]);
        // Only add code if it's not '0' and different from the last added code
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    // Pad with '0' if necessary
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    // Null-terminate the result
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
