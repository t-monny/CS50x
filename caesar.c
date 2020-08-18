#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string arglist[])
{
// Check user has only inputted two command line arguments.
    if (argc == 2)
    {
// Check each character of user inputted string is a decimal digit, if not, return an error message and close the program.
        int stringlength = strlen(arglist[1]);
        for (int charcount = 0; charcount < stringlength; charcount++)
        {
            int digitcheck = isdigit(arglist[1][charcount]);
            if (digitcheck == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

// Use atoi function to convert the user inputted string into an integer and print the value to the user.
        int keyno = atoi(arglist[1]);
        
// Prompt user for a string.
        string plaintext = get_string("plaintext: ");

// Use strlen to give the length of the string
        int ptlen = strlen(plaintext);

// Create new string named "ciphertext", set it to mirror plaintext for now.
        string ciphertext = plaintext;

// Look at the first character in the user inputted string "plaintext", if the character is a letter we want to change it using the cipher key.
// Repeat this for each character in the string, for the length of the string "ptlen"
        for (int y = 0; y < ptlen; y++)
        {
            int lettercheck = isalpha(plaintext[y]);
            if (lettercheck != 0)
// If changing the character by the key amount will be out of range of ascii characters, subtract 26 from character first.
// Use numero 26 to loop through alphabet.
            {
                if ((127 - plaintext[y]) < keyno % 26)
                {
                    ciphertext[y] = plaintext[y] - 26 + keyno % 26;
                }
                
// If changing the character in user inputted string by key number gives a new character that remains within ascii limits...
// ... using numero 26 to cycle through alphabet, then change each character by the amount given by the user inputted key.
                else
                {
                    ciphertext[y] = plaintext[y] + (keyno % 26);
                }

// if resulting character is not a letter i.e. above range of uppercase or lowercase letters, subtract 26 to loop it back around through...
// ... the alphabet.
                if ((ciphertext[y] < 97 && ciphertext[y] > 90) || (ciphertext[y] <= 127 && ciphertext[y] > 122))
                {
                    ciphertext[y] = ciphertext[y] - 26;
                }
            }
        }

// Print the resulting ciphertext to the user.
        printf("ciphertext: %s\n", ciphertext);

    }

// If the nnumber of command line arguments is not 2 then print an error message and close the program.
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

