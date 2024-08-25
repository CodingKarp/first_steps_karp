#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string argv);
char rotate(char c, int n);
void print_usage()
{
    printf("Usage: ./caeser key\n");
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        print_usage();
        return 1;
    }

    if (only_digits(argv[1]))
    {
        print_usage();
        return 1;
    }

    int key = atoi(argv[1]);
    string plain_text = get_string("plaintext: ");
    int x = strlen(plain_text);
    char ciphertext[x + 1];
    for (int i = 0; i < x; i++)
    {
        ciphertext[i] = rotate(plain_text[i], key);
    }
    ciphertext[x] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

char rotate(char c, int n) // ciphers the text
{
    int cypher_char;
    int letter = c;
    if (isalpha(c) && isupper(c))
    {
        cypher_char = (letter - 'A' + n) % 26; 
        cypher_char = cypher_char + 'A';
    }
    else if (isalpha(c) && islower(c))
    {
        cypher_char = (letter - 'a' + n) % 26;
        cypher_char = cypher_char + 'a';
    }
    else
    {
        cypher_char = letter;
    }
    return cypher_char;
}

bool only_digits(string s) // checks user command input
{
    int s_length = strlen(s);
    for (int i = 0; i < s_length; i++)
    {
        if (!isdigit(s[i]))
        {
            return true;
        }
    }

    return false;
}
