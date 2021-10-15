#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <sys/syscall.h>
#include <unistd.h>

#define TapeLenght 10

/* 
    Struct for transition table cells.
    Element format: (elem, state, head)
    elem:  Value to write to the tape (0/1)
    state: State to which it changes (A/B/C/H)
    head: Describes the movement of head (Right/Left)
*/
struct busyBeaver
{
    int elem;
    int state; // state A = 0; state B = 1; state C = 2; state H = 3
    char head;
};

struct busyBeaver Ttable[3][4]; // Transition table

int tape[TapeLenght] = {0}; // Initial state of tape: 0000000000
int headCell = 2;           // Consider the head to be at tape cell 2 initially

int step;
int state;

/*
    Our 3-state 2-symbol Transition table:(2*3 matrix)
    +---------+---------+--------+-------+
    |         |    A    |    B   |   C   |    
    +---------+---------+--------+-------+             
    |    0    |   1RB   |   0RC  |  1LC  |
    +---------+---------+--------+-------+
    |    1    |   1RH   |   1RB  |  1LA  |
    +---------+---------+--------+-------+
*/

void Print_TT()
{
    printf("\033[1;31m");
    printf("\t-------------------------------------------------------------------\n");
    printf("\033[0m");

    printf("\033[1;32m");
    printf("\t\t\tOur 3-state 2-symbol Transition table\n");
    printf("\033[0m");

    printf("\033[1;31m");
    printf("\t-------------------------------------------------------------------\n\n");
    printf("\033[0m");

    printf("\033[1;34m");
    printf("\t\t\t+---------+---------+--------+-------+\n");
    printf("\t\t\t|         |    A    |    B   |   C   |\n");
    printf("\t\t\t+---------+---------+--------+-------+\n");
    printf("\t\t\t|    0    |   1RB   |   0RC  |  1LC  |\n");
    printf("\t\t\t+---------+---------+--------+-------+\n");
    printf("\t\t\t|    1    |   1RH   |   1RB  |  1LA  |\n");
    printf("\t\t\t+---------+---------+--------+-------+\n\n");
    printf("\033[0m");

    printf("\033[1;31m");
    printf("\t-------------------------------------------------------------------\n");
    printf("\t-------------------------------------------------------------------\n");
    printf("\033[0m");

    return;
}

void displayTape()
{
    printf("\n\t\t\t\t");
    for (int i = 0; i < TapeLenght; i++)
    {
        if (i == headCell)
        {
            printf("\033[1;31m");
            printf("%d ", tape[i]);
            printf("\033[0m");
        }
        else
        {
            printf("\033[0;33m");
            printf("%d ", tape[i]);
            printf("\033[0m");
        }
    }
    printf("\n");

    printf("\t\t\t\t");
    for (int j = 0; j < TapeLenght; j++)
    {
        if (j == headCell)
        {
            printf("\033[1;36m");
            printf("\u2191");
            printf("\033[0m");
            printf("\n");
            break;
        }
        printf("  ");
    }
}

void GameStats()
{
    displayTape();

    printf("\n");

    printf("\033[1;35m");
    printf("-->> ");
    printf("\033[0m");

    printf("\033[1;34m");
    printf("Step: ");
    printf("\033[0m");
    printf("\033[1;31m");
    printf("%d ; ", step);
    printf("\033[0m");

    printf("\033[1;34m");
    printf("State: ");
    printf("\033[0m");
    printf("\033[1;31m");
    printf("%c\n\n", state == 0 ? 'A' : (state == 1 ? 'B' : (state == 2 ? 'C' : 'H')));
    printf("\033[0m");
}

void Game()
{
    system("clear");
    
    step = 0;
    state = 0;
    //**************************** Initializing Transition table ********************************

    // T(A, 0) = (1RB)                                  // T(A, 1) = (1RH)
    Ttable[0][0].elem = 1;                              Ttable[1][0].elem = 1;
    Ttable[0][0].head = 'R';                            Ttable[1][0].head = 'R';
    Ttable[0][0].state = 1;                             Ttable[1][0].state = 3;

    // T(B, 0) = (0RC)                                  // T(B, 1) = (1RB)
    Ttable[0][1].elem = 0;                              Ttable[1][1].elem = 1;
    Ttable[0][1].head = 'R';                            Ttable[1][1].head = 'R';
    Ttable[0][1].state = 2;                             Ttable[1][1].state = 1;

    // T(C, 0) = (1LC)                                  // T(C, 1) = (1LA)
    Ttable[0][2].elem = 1;                              Ttable[1][2].elem = 1;
    Ttable[0][2].head = 'L';                            Ttable[1][2].head = 'L';
    Ttable[0][2].state = 2;                             Ttable[1][2].state = 0;

    //***************************** Printing busy beaver to the console **************************

    Print_TT();

    //******************************* Displaying tape and header ****************************

    printf("\033[1;35m");
    printf("-->> ");
    printf("\033[0m");

    printf("\033[0;37m");
    printf("Tape condition at the start");
    printf("\033[0m");

    //displayTape(); // Tape condition at the start

    do
    {
        GameStats();
        
        printf("\033[1;32m");
        printf("\t*******************************************************************\n");
        printf("\033[0m");

        step = step + 1;

        int Read = tape[headCell];
        tape[headCell] = Ttable[tape[headCell]][state].elem;

        if (Ttable[Read][state].head == 'R')
            headCell = headCell + 1;
        else
            headCell = headCell - 1;
        
        state = Ttable[Read][state].state;

        sleep(4);
    }
    while(state != 3);
    GameStats();
    
    return;
}

int main()
{
    system("clear");
    
    char play = 'Y';
    char stop = 'N';

    char input;

    printf("--- Do you want to look at the 3-state 2-symbol busy beaver ? \n");
    printf("--- Enter 'Y' to start and 'N' to exit\n");
    printf("--- (Y/N): ");

    scanf("%c", &input);

    if(input != play)
    {
        printf("\033[1;32m");
        printf("\t********************** \033[1;31mThank You :)\033[1;32m **************************\n");
        printf("\033[0m");   

        return 0;
    }
    
    Game();

    printf("\033[1;32m");
    printf("\t********************** \033[1;31mThank You :)\033[1;32m **************************\n");
    printf("\033[0m");   

    return 0;
}
