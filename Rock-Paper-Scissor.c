// C program to play rock, paper and scissor game with computer
/* It is a two player game
   Rules of the game: 1)If player 1 choose rock and player 2 choose paper then player 2 wins
                      2)If player 1 choose paper and player 2 choose scissor then player 2 wins
                      3)If player 1 choose scissor and player 2 choose rock then player 2 wins
                      4)If both chooses same then it's a tie
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// Rule function to decide the winner
int rule(char you, char comp)
{
    /*
      If both player and computer choice is same then rule function returns the value -1
      If player wins then this function returns the value 1
      If computer wind then this function returns the value 0
    */
    // Here "r" denotes rock, 'p' denotes paper, 's' denotes scissor
    if(you == comp)
        return -1;
    if (you == 'r' && comp == 'p')
        return 0;
    else if(you == 'p' && comp == 'r')
        return 1;
    if (you == 'r' && comp == 's')
        return 1;
    else if (you == 's' && comp == 'r')
        return 0;
    if (you == 's' && comp == 'p')
        return 1;
    else if (you == 'p' && comp == 's')
        return 0;

}

int main()
{
    // Array of pointers used for printing the option that computer chose
    char *options[3] = {
        "Rock",
        "Paper",
        "Scissor"
    };
    // Declaring required variables
    int n,c ;
    int result=1;

    // Declaring select variable to store the option player selected
    char select[8];

    printf ("Please choose rock, paper, scissor or quit: ");
    scanf("%s",select);

    // Declaring variable that takes the first letter in select variable
    char you = select[0];
    char comp;

    // Chooses random number every time
    srand(time(NULL));

    // If player chooses quit then while loop exits
    // Here 'q' denotes quit
    while( you != 'q')
    {
        // Prints new line
        printf("\n");

        // Makes the random number less than 100
        n = rand() % 100;

        // Using probability 100 is divided roughly among rock, paper and stone using random number
        if (n<=33)
        {
          comp = 'r';
        }
        else if (n>33 && n<=66)
        {
          comp = 'p' ;
        }
        else
        {
          comp = 's' ;
        }

        // Only if player chooses one among rock, paper or scissor the program continues further
        if (strcmp(select,"rock")==0 || strcmp(select,"paper")==0 || strcmp(select,"scissor")==0)
        {
            // Calling rule function
            result = rule(you, comp);

            // Capitalizing the first character in select variable
            select[0] = toupper(select[0]);

            // Printing the chosen options by player and computer
            printf("You chose: %s",select);
            printf("\nComputer choose: ");

            // Printing each character of chosen option of computer
            if (comp == 'r')
            {
                c = 0;
                while(*(options[0] + c) != '\0')
                {
                    printf("%c", *(options[0]+ c));
                    c++;
                }
            }
            if (comp == 'p'  )
            {
                c = 0;
                while(*(options[1] + c) != '\0')
                {
                    printf("%c", *(options[1]+ c));
                    c++;
                }
            }
            if (comp == 's'  )
            {
                c = 0;
                while(*(options[2] + c) != '\0')
                {
                    printf("%c", *(options[2]+ c));
                    c++;
                }
            }

            // Printing the result
            if(result == -1)
            {
                printf("\nResult: Tie \n");
            }
            else if(result == 0)
            {
                printf("\nResult: Computer  won \n ");
            }
            else
            {
                printf("\nResult: Player won\n ");
            }
        }
        else
        {
            // Player have to choose again
            printf ("Please choose rock, paper, scissor or quit: ");
            scanf("%s",select);

            you = select[0];
        }
    }
    return 0;
  }
