#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void Encrypt(char *str)
{
    short key = 5;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != 10)
        {
            if (isupper(str[i]))
            {
                str[i] = ((str[i] - 65 + key) % 26) + 65;
            }
            else if (islower(str[i]))
            {
                str[i] = ((str[i] - 97 + key) % 26) + 97;
            }
        }
        else
        {
            str[i] = 0x00;
        }
    }
    printf("ciphertext: %s\n", str);
}
int binToDec(long long n)
{
    int dec = 0, i = 0, rem;

    while (n != 0)
    {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}
void Decrypt(char *s)
{
    short key = 5;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != 10 && s[i] != 32)
        {

            if (isupper(s[i]))
            {
                s[i] = ((s[i] - 65 - key) % 26) + 65;
            }
            else
            {
                s[i] = ((s[i] - 97 - key) % 26) + 97;
            }
        }
    }
    printf("Plaintext: %s", s);
}

char *Encode(char *str)
{
    short len = strlen(str);
    str[len - 1] = '\0';

    char *binary = malloc(len * 8 + 1);

    binary[0] = '\0';
    for (size_t i = 0; i < len - 1; ++i)
    {
        char ch = str[i];
        for (int j = 7; j >= 0; --j)
        {
            if (ch & (1 << j))
            {
                strcat(binary, "1");
            }
            else
            {
                strcat(binary, "0");
            }
        }
        strcat(binary, " ");
    }
    return (binary);
}

char *Decode(char *str)
{
    char *token;
    int bin;
    char *charecter;
    char string[100];
    int i = 0;
    str[strlen(str) - 1] = '\0';
    token = strtok(str, " ");
    while (token != NULL)
    {
        // printf("%s\n", token);
        bin = binToDec(atoi(token));
        charecter = (char)bin;
        string[i] = charecter;
        // printf("%c", string[i]);
        token = strtok(NULL, " ");
        i++;
    }

    printf("Your decoded string: %s\n", string);
    return string;
}

int main()
{
    char input[100];
    short loop = 1;

    while (loop == 1)
    {
        printf("What would you like to do: [Encrypt] [Decrypt] [Encode] [Decode] [Quit]\n");
        gets(input);

        if (strcmp(input, "encrypt") == 0)
        {
            printf("What would you like to Encrypt? \n");
            fgets(input, 100, stdin);
            // printf("Your Encrypted string is: %s", Encrypt(input));
            Encrypt(input);
        }
        else if (strcmp(input, "decrypt") == 0)
        {
            printf("What would you like to Decrypt? \n");
            fgets(input, 100, stdin);
            // printf("Your Decrpyted string is: %s", Decrypt(input));
            Decrypt(input);
        }
        else if (strcmp(input, "encode") == 0)
        {
            printf("What would you like to Encode? \n");
            fgets(input, 100, stdin);
            printf("Your Encoded string is: %s", Encode(input));
            // Encode(input);
        }
        else if (strcmp(input, "decode") == 0)
        {
            printf("What would you like to Decode? \n");
            fgets(input, 100, stdin);
            Decode(input);
        }
        else if (strcmp(input, "binary") == 0)
        {

            printf("What is the number? \n");
            int n;
            scanf("%d", &n);
            printf("Your number in Decimal: %d\n", binToDec(n));
        }

        else
        {
            printf("Unkown Command. Please try again... \n");
        }
        printf("\n");
    }
}