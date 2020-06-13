#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int argv_length = strlen(argv[1]);

        // If condition to check whether the user entered the correct amount of keys
        if (argv_length != 26)
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }

        // Check whether there's numerical key, if yes then return error
        for (int i = 0; i < argv_length; i++)
        {
            if (isdigit(argv[1][i]))
            {
                printf("Usage: ./substitution key (26 char)\n");
                return 1;
            }
        }

        // Create an array of alphabet letters and key to encrypt the text
        string alphabet_key[2];
        alphabet_key[0] = "abcdefghijklmnopqrstuvwxyz";
        alphabet_key[1] = argv[1];

        // Checking repeated key in the input
        for (int i = 0; i < 26; i++)
        {
            int count = 0;
            for (int j = 0; j < 26; j++)
            {
                if (tolower(alphabet_key[1][i]) == tolower(alphabet_key[1][j]))
                {
                    count++;
                    if (count > 1)
                    {
                        printf("Detected repeated key\n");
                        return 1;
                    }
                }
            }
        }

        // Get plaintext from user
        string plain = get_string("plaintext: ");
        printf("ciphertext: ");

        // Encryption process using the key provided
        for (int i = 0; i < strlen(plain); i++)
        {
            if ((plain[i] >= 'a' && plain[i] <= 'z') || (plain[i] >= 'A' && plain[i] <= 'Z'))
            {
                for (int j = 0; j < 26; j++)
                {
                    if (tolower(alphabet_key[0][j]) == tolower(plain[i]))
                    {
                        // Convert uppercase char with key
                        if (isupper(plain[i]))
                        {
                            printf("%c", toupper(alphabet_key[1][j]));
                            break;
                        }
                        // Convert lowercase char with key
                        else
                        {
                            printf("%c", tolower(alphabet_key[1][j]));
                            break;
                        }
                    }
                }
            }

            // If the char is not alphabetic then print that char
            else
            {
                printf("%c", plain[i]);
            }

        }
        printf("\n");
        return 0;
    }
    // Throw error message if the user doesn't provide the correct number of input in command line
    else
    {
        printf("Usage: ./substitution key (26 char)\n");
        return 1;
    }
}
