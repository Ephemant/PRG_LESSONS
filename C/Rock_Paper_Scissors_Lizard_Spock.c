/**
Author: Etienne Cárdenas Wertheimer
Date:   27/07/2020
Description:
The following program consists of a modification of the classic Rock, Paper, Scissors game called Rock, Paper, Scissors, Lizard, Spock.
You have the option to play Player vs Player, or Player vs CPU
Rules:
    rock crushes scissors
    rock crushes lizard
    paper covers rock
    paper disproves Spock
    Scissors cuts paper
    scissors decapitates lizard
    lizard eats paper
    lizard poisons Spock
    Spock vaporizes rock
    Spock smashes scissors
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** Init Player struct ***
typedef struct Players
{
    char name[64];    //player name
    int play;         //player play
    int score;        //player score
    int cpu;           //cpu = 1 => random plays will be selected
} Player;
//*** End Struct ***

void loop();
void selectPlay(Player*, int*, int*);
void header();
void menu(Player*);

int main(int argc, char **argv)
{
    srand(getpid());    //Generate pseudo random numbers in function of the process ID

    loop();

    return 0;
}

void loop()
{
    Player player[2];     //Array of 2 players

    int turn = 0, round = 0;

    menu(player);

    do
    {
        //If the turn is greater than 0 and it is also an even number, it means that both shirts selected their plays
        //Then...it's time to evaluate the result...
        if(turn > 0 && turn%2 == 0)
        {
            //Rock = 0; Paper = 1; Scissors = 2; Lizzard = 3; Spock = 4;
            //Player 1 Wins
            if((player[0].play == 0 && player[1].play == 2)
               || (player[0].play == 0 && player[1].play == 3)
               || (player[0].play == 1 && player[1].play == 0)
               || (player[0].play == 1 && player[1].play == 4)
               || (player[0].play == 2 && player[1].play == 1)
               || (player[0].play == 2 && player[1].play == 3)
               || (player[0].play == 3 && player[1].play == 1)
               || (player[0].play == 3 && player[1].play == 4)
               || (player[0].play == 4 && player[1].play == 0)
               || (player[0].play == 4 && player[1].play == 2))
            {
                system("CLS");
                printf("Round %d: %s wins\n", round + 1, player[0].name);

                player[0].score++;
                round++;

                system("PAUSE");
            }
            else
            {
                //Player 2 Wins
                if((player[0].play == 2 && player[1].play == 0)
                   || (player[0].play == 3 && player[1].play == 0)
                   || (player[0].play == 0 && player[1].play == 1)
                   || (player[0].play == 4 && player[1].play == 1)
                   || (player[0].play == 1 && player[1].play == 2)
                   || (player[0].play == 3 && player[1].play == 2)
                   || (player[0].play == 1 && player[1].play == 3)
                   || (player[0].play == 4 && player[1].play == 3)
                   || (player[0].play == 0 && player[1].play == 4)
                   || (player[0].play == 2 && player[1].play == 4))
                {
                    system("CLS");
                    printf("Round %d: %s wins\n", round + 1, player[1].name);

                    player[1].score++;
                    round++;

                    system("PAUSE");
                }
                //Draw
                else
                {
                    system("CLS");
                    printf("Round %d: DRAW!\n", round + 1);

                    round++;

                    system("PAUSE");
                }
            }
            //Show players score
            system("CLS");
            printf("Score:\n\n");
            printf("%s: %d\n", player[0].name, player[0].score);
            printf("%s: %d\n\n", player[1].name, player[1].score);
            system("PAUSE");
        }
        selectPlay(player, &turn, &round);

    } while(1);
}

void menu(Player *player)
{
    int op;

    system("CLS");

    header();   //Main menu header

    printf("Select a game option:\n\n");

    printf("\t1.- Player vs Player\n");
    printf("\t2.- Player vs CPU\n");
    printf("\t3.- Exit");

    printf("\n\nOption: ");
    scanf("%d", &op);

    switch(op)
    {
        //If option 1 is selected player_1 and player_2 attributes will be filled; player.cpu = 0 => Player vs Player
        case 1:
            strcpy(player[0].name, "Player 1");
            player[0].score = 0;
            player[0].cpu = 0;

            strcpy(player[1].name, "Player 2");
            player[1].score = 0;
            player[1].cpu = 0;

            break;

        //If option 2 is selected player_1 and player_2 attributes will be filled; player.cpu = 1 => Player vs CPU
        case 2:
            strcpy(player[0].name, "Player 1");
            player[0].score = 0;
            player[0].cpu = 0;

            strcpy(player[1].name, "CPU");
            player[1].score = 0;
            player[1].cpu = 1;

            break;

        //op 3 => Close program
        case 3:
            exit(0);
        default:
            break;
    }
}

void selectPlay(Player *player, int *turn, int *round)
{
    int op;
    int idx_player = 1;    //Index which indicates the player turn; even = player_1, odd = player_2

    system("CLS");

    printf("Turn: %d\t", *turn + 1);
    printf("Round: %d\n\n", *round + 1);
    printf("Select a play:\n\n");
    printf("\t1.- Rock\n");
    printf("\t2.- Paper\n");
    printf("\t3.- Scissors\n");
    printf("\t4.- Lizzard\n");
    printf("\t5.- Spock\n");
    printf("\t6.- Back\n");

    if(*turn%2 == 0)
    {
        idx_player = 0;

        printf("\nPlay %s: ", player[idx_player].name);
        scanf("%d", &op);
    }
    else
    {
        //If player_2 is CPU....
        if(player[idx_player].cpu == 1)
        {
            //CPU can't choose to go back to the main menu (op [1-5] are allowed)
            op = (rand() % (5 + 1 - 1)) + 1;
            system("CLS");

            switch(op)
            {
                case 1:
                    printf("The computer has play: Rock\n");
                    break;
                case 2:
                    printf("The computer has play: Paper\n");
                    break;
                case 3:
                    printf("The computer has play: Scissors\n");
                    break;
                case 4:
                    printf("The computer has play: Lizzard\n");
                    break;
                case 5:
                    printf("The computer has play: Spock\n");
                    break;
            }

            system("PAUSE");
        }
        //Else...The Player 2 can select manually the option
        else
        {
            printf("\nPlay %s: ", player[idx_player].name);
            scanf("%d", &op);
        }
    }
    //The value contained in the turn address is increased by 1 => Next turn, Next player
    *turn = *turn + 1;

    //Play selected
    if(op > 0 && op < 6)
    {
        player[idx_player].play = op - 1;
    }
    //Else, go back to the main menu
    else
    {
        *turn = 0;
        *round = 0;
        menu(player);
    }
}

void header()
{
    int length = 41;

    for(int i = 0; i < length; i++)
    {
        printf("*");
    }
    printf("\n*");
    for(int i = 0; i < length - 2; i++)
    {
        printf(" ");
    }
    printf("*\n");

    printf("*\t\t  Juego  \t\t*\n");
    printf("*\t   Rock, Paper, Scissors \t*\n");
    printf("*\t      Lizzard, Spock\t\t*");

    printf("\n*");
    for(int i = 0; i < length - 2; i++)
    {
        printf(" ");
    }
    printf("*\n");

    for(int i = 0; i < length; i++)
    {
        printf("*");
    }

    printf("\n\n");
}
