/**
Author: Etienne Cárdenas Wertheimer
Date: 23/09/2020
Description:

The following program performed Caesar Cipher over a string as user input.
You also have the option of decrypting the message knowing the number of rounds.
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void cipher(char*, int, int);
void decipher(char*, int, int);

int main(int argc, char** argv[])
{
    int rounds = 0, offset = 3;
    int maxChars = 64;
    char strData[maxChars];

    printf("*** Caesar Cipher ***\n\n");

    printf("Enter message to encrypt: ");
    fflush(stdin);
    fgets(strData, maxChars, stdin);

    printf("Enter number of rounds: ");
    do //rounds shall be an integer number greater than Zero
    {
        scanf("%d", &rounds);
    } while(rounds <= 0);


    cipher(strData, rounds, offset);

    decipher(strData, rounds, offset);

    return 0;

}

void cipher(char *data, int rounds, int offset)
{
    printf("\n*** Encrypting Your Message ***\n");

    for(int r = 0; r < rounds; r++)
    {
        //printf("\nRound %d\n\n", r+1);

        for(int i = 0; i < strlen(data); i++)
        {
            /** Mapping chars between A=0, ..., Z = 26 from ASCII **/

            //If uppercase
            if(data[i] >= 65 && data[i] <= 90)
            {
                data[i] = (data[i] - 65 + offset)%26; //Shift Right to the next Char
                /**
                    The remainder (%) operator in C is only equal to the modulo if the numbers are positive.
                    If the divisor is negative and the dividend is positive, the result of the remainder will be negative
                    Then, to obtain the value of the modulo the dividend must be added to the previous result
                **/
                if(data[i] < 0)
                {
                    data[i] = (data[i] + 26) + 65;
                }
                else
                    data[i] = data[i] + 65;
            }
            //If lowercase
            else if(data[i] >= 97 && data[i] <= 122)
            {
                data[i] = (data[i] - 97 + offset)%26;

                if(data[i] < 0)
                {
                    data[i] = (data[i] + 26) + 97;
                }
                else
                    data[i] = data[i] + 97;
            }
            //Other symbols are ignored
            else
                continue;

        }
        //printf("The cipher message at round %d: %s",(r+1), data);
    }


    printf("\nThe encrypted message is: %s", data);
}

void decipher(char *data, int rounds, int offset)
{
    printf("\n*** Decrypting Your Message ***\n");

    for(int r = 0; r < rounds; r++)
    {
        //printf("\nRound %d\n\n", r+1);

        for(int i = 0; i < strlen(data); i++)
        {
            if(data[i] >= 65 && data[i] <= 90)
            {
                data[i] = (data[i] - 65 - offset)%26; //Shift Left to the next Char

                if(data[i] < 0)
                {
                    data[i] = (data[i] + 26) + 65;
                }
                else
                    data[i] = data[i] + 65;
            }
            else if(data[i] >= 97 && data[i] <= 122)
            {
                data[i] = (data[i] - 97 - offset)%26;

                if(data[i] < 0)
                {
                    data[i] = (data[i] + 26) + 97;
                }
                else
                    data[i] = data[i] + 97;
            }
            else
                continue;
        }
        //printf("The cipher message at round %d: %s",(r+1), data);
    }

    printf("\nThe decrypted message is: %s", data);
}
