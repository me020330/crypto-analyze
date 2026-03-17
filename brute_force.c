#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // за isupper()

char caesar_decrypt_char(char c, int k) {
        if (isupper(c)) 
        {
			return (((int)c - 'A' - k + 26) % 26 + 'A');
		} 
        else if(islower(c))
        {
            return (((int)c - 'a' - k + 26) % 26 + 'a');
        }
		return c;
}

int main()
{
    char encrypted_text[] = "Pm ol ohk hufaopun jvumpkluaphs av zhf, ol dyval pa pu jpwoly, aoha pz, if zv johunpun aol vykly vm aol slaalyz vm aol hswohila, aoha uva h dvyk jvbsk il thkl vba.";
    char decrypted_text[strlen(encrypted_text)];
    
    for(int i = 1; i <= 25; i++)
    {
		for (int j = 0; j <= strlen(encrypted_text); j++)
		{ 
			decrypted_text[j] = caesar_decrypt_char(encrypted_text[j], i); 
		}
		printf("[%d]: %s\n", i, decrypted_text);
	}
    
    return EXIT_SUCCESS;
}