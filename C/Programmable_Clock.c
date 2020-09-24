/**
Author: Etienne Cárdenas Wertheimer
Date:   03/01/2020
Description:
The following program simulates the operation of a programmable clock
**/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void programmableClock(int, int, int);

int main(int argc, char **argv)
{
    int hours, minutes, seconds;

    do  //do until you enter a valid format
    {
        printf("Real time clock hh:mm:ss format\n\n");

        printf("Setting hours[0-23]:\t");
        scanf("%d", &hours);
        printf("Setting minutes[0-59]:\t");
        scanf("%d", &minutes);
        printf("Setting seconds[0-59]:\t");
        scanf("%d", &seconds);

        if((hours < 0 || hours > 23) || (minutes < 0 || minutes > 59) || (seconds < 0 || seconds > 59))
        {
            printf("\nInvalid format. Please enter the correct format for each time variable\n");
            system("PAUSE");
            system("CLS");
        }
        else
            break;
    } while(1);

    system("CLS");

    printf("%d:%d:%d Hrs.", hours, minutes, seconds);

    programmableClock(hours, minutes, seconds);

    return 0;
}

void programmableClock(int hours, int minutes, int seconds)
{
    clock_t prevTime, startTime, elapsedTime;

    prevTime = 0;
    startTime = clock();

    do
    {
        elapsedTime = (double)(clock() - startTime)/CLOCKS_PER_SEC; //Timer in seconds by using the internal clock

        if(elapsedTime >= prevTime + 1) //Enter here every 1 second elapsed
        {
            system("CLS");
            prevTime = elapsedTime;

            if(seconds < 59)
            {
                seconds ++;
            }
            else
            {
                if(hours == 23 && minutes == 59 && seconds == 59)
                {
                    hours = 0;
                    minutes = 0;
                    seconds = 0;
                }
                else
                {
                    if(minutes == 59 && seconds == 59)
                {
                    hours++;
                    minutes = 0;
                    seconds = 0;
                }
                    else
                    {
                        seconds = 0;
                        minutes ++;
                    }
                }
            }

             printf("%d:%d:%d Hrs.", hours, minutes, seconds);  //Update time
        }
    } while(1); //Infinite loop
}
