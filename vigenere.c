#include <stdio.h>
#include <string.h>
#include "vigenere.h"

void encrypt(char *text, char *key) {

    int textLen = strlen(text);
    int keyLen = strlen(key);

    for(int i = 0; i < textLen; i++) {

        int p = text[i] - 'A';
        int k = key[i % keyLen] - 'A';

        char c = (p + k) % 26 + 'A';
        text[i] = c;
    }
}

void decrypt(char *text, char *key) {

    int textLen = strlen(text);
    int keyLen = strlen(key);

    for(int i = 0; i < textLen; i++) {

        int c = text[i] - 'A';
        int k = key[i % keyLen] - 'A';

        char p = (c - k + 26) % 26 + 'A';
        text[i] = p;
    }
}
