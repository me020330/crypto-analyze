#include <stdio.h>
#include <string.h>
#include "vigenere.h"

int main() {

    char text[100] = "ATTACK";
    char key[] = "LEMON";

    printf("Original: %s\n", text);

    encrypt(text, key);
    printf("Encrypted: %s\n", text);

    decrypt(text, key);
    printf("Decrypted: %s\n", text);

    return 0;
}
