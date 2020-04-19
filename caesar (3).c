#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <wctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check for two arguments in command-line argument

    if (argc != 2)
    {
        printf("I need a single command-line argument\n");
        return 1;
    }
    
    // cast the string argv[1] into a number, called k
    
    int cipher_key = atoi(argv[1]);
    
    // check  that its a non-negative integer less than 2^31 - 26
    if (cipher_key < 0)
    {
        printf("I need a positive digit for the single command-line argument\n");
        return 1;
    }

    int argumentIsNumber = 1;
    
    for (int i = 0; i < strlen(argv[1]); i++) 
    {
        if (isdigit(argv[1][i]) == 0) 
        {
            argumentIsNumber = 0;
            
        }
    }
    
    if (argumentIsNumber == 0)     
    {
        printf("I need a single command-line argument that only has digits\n");
        return 1;
    }
    
    // Prompt user for string of plaintext to encrypt

    string plaintext = get_string("plaintext: ");
    
    // Print "ciphertext: " after which the program will print ciphered text 

    printf("ciphertext: ");
    
    // Encipher the text  
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    { 
        // if upper-case character, add k to the ASCII code of that character (but keep it lower-case) 
        if (isupper(plaintext[i]))
        {
            printf("%c", ((plaintext[i]  - 65 + cipher_key) % 26 + 65));
            
        }
        // if upper-case character, add k to the ASCII code of that character (but keep it lower-case) 
        else if (islower(plaintext[i]))
        {
            printf("%c", ((plaintext[i] - 97 + cipher_key) % 26 + 97));
            
        }
        
        //if non-alphabetical, do not change
        
        else 
        {
            printf("%c", plaintext[i]);
            
        }
        
        
    }
    printf("\n");
}