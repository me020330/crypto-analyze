#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000

char* vigenere_cipher(const char* plaintext, const char* key, const char* mode)
{
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    int key_index = 0;
    char a = ' ';

    char* output = malloc(sizeof(char) * (plaintext_len + 1));

    for(int i = 0; plaintext[i] != '\0'; i++){
        char symbol = plaintext[i];
        if(isalpha(symbol))
        {
            char k_char = toupper(key[key_index % key_len]);
            int shift = k_char - 'A';
            
            if (islower(symbol)) a = 'a';
            else if (isupper(symbol)) a = 'A';

            if (mode == "encrypt")
            {
                output[i] = ((symbol - a + shift) % 26) + a;
            }
            
            else if (mode == "decrypt")
            {
                output[i] = ((symbol - a - shift + 26) % 26) + a;
            }

            key_index++;
        }
        else 
        {
            output[i] = plaintext[i];
        }
    }

    output[plaintext_len] = '\0';
    return output;
}

int main()
{
    char plaintext[MAXN];
    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    char key[MAXN];
    printf("Enter key: ");
    scanf("%s", key);

    char* cipher = vigenere_cipher(plaintext, key, "encrypt");

    printf("Encrypted: %s\n", cipher);

    cipher = vigenere_cipher(cipher, key, "decrypt");

    printf("Decrypted: %s\n", cipher);

    return EXIT_SUCCESS;
}