/* Explanations *************************************************************************************************************************************
|
| The Tic-Tac-Toe board has 9 cells. We will assume that the cell numbering is as follows:
|
|   c0 | c1 | c2
|   ------------
|   c3 | c4 | c5
|   ------------
|   c6 | c7 | c8
|
****************************************************************************************************************************************************/




/* Includes ****************************************************************************************************************************************/

#include "Utilities.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>   /* For standard input/output functions */

/***************************************************************************************************************************************************/




/* Definitions *************************************************************************************************************************************/

#define AUTHOR  ( "Zeynep Ozalp" )  /* Author's name                                   */

#define EMPTY   ( ' '             )  /* Label for empty cells                           */
#define PLAYER1 ( 'X'             )  /* Label for player 1 and cells marked by player 1 */
#define PLAYER2 ( 'O'             )  /* Label for player 2 and cells marked by player 2 */

/***************************************************************************************************************************************************/




/* Type Definitions ********************************************************************************************************************************/

typedef unsigned char boolean ;

/***************************************************************************************************************************************************/




/* Global Variables ********************************************************************************************************************************/

char c0 , c1 , c2 , c3 , c4 , c5 , c6 , c7 , c8 ;  /* Cells of the Tic-Tac-Toe board */

/***************************************************************************************************************************************************/




/* Functions ***************************************************************************************************************************************/

/* Initializes the global variables. */

void initializeGlobalVariables ( void )
{
  /* TODO */
  c0=c1=c2=c3=c4=c5=c6=c7=c8=EMPTY;
}

/*=================================================================================================================================================*/

/* Prints a banner including the author name. */

void printBanner ( void )
{
  printf(                                                                                   "\n"          ) ;
  printf( "*******************************************************************************" "\n"          ) ;
  printf( "* Tic-Tac-Toe                                                                 *" "\n"          ) ;
  printf( "* by %-72s *"                                                                    "\n" , AUTHOR ) ;
  printf( "*******************************************************************************" "\n"          ) ;
}

/*=================================================================================================================================================*/

/* Prints the current board configuration. */

void printBoard ( void ){
    printf("    Cells                                    Board\n");
    printf(".-----------.                           .-----------.\n");
    printf("| 0 | 1 | 2 |                           | %c | %c | %c |\n", c0, c1, c2);
    printf("|-----------|                           |-----------|\n");
    printf("| 3 | 4 | 5 |                           | %c | %c | %c |\n", c3, c4, c5);
    printf("|-----------|                           |-----------|\n");
    printf("| 6 | 7 | 8 |                           | %c | %c | %c |\n", c6, c7, c8);
    printf("'-----------'                           '-----------'\n");
}

/*=================================================================================================================================================*/

/* Gets the next move of "player", and marks it on the board.                     */
/* Loops (and asks again) if the input is not valid, or if the cell is not empty. */

void getNextMove ( char player )
{
  /* TODO */
    int move=9, is_input_correct=0;
    do {
      printf("%c, enter your next move (0-8) : ", player);
      if(scanf("%d", &move)!=1);
      clearInputBuffer();
      printf("\n");
      if (move<0 || move>8){
         printf("Incorrect Input! Please try again.\n\n");
         continue;
       }
       else if (0<=move && move<=8){
         switch(move){
           case 0:
             if (c0 != EMPTY) {
               printf("Cell is not empty! Please try again!\n\n");
               break;
             }
             c0=player;
             is_input_correct=1;
             break;
           case 1:
             if (c1 != EMPTY) {
               printf("Cell is not empty! Please try again!\n\n");
               break;
             }
             c1=player;
             is_input_correct=1;
             break;
           case 2:
               if (c2 != EMPTY) {
                 printf("Cell is not empty! Please try again!\n\n");
                 break;
               }
               c2=player;
               is_input_correct=1;
               break;
           case 3:
               if (c3 != EMPTY) {
                 printf("Cell is not empty! Please try again!\n\n");
                 break;
               }
               c3=player;
               is_input_correct=1;
               break;
           case 4:
                 if (c4 != EMPTY) {
                   printf("Cell is not empty! Please try again!\n\n");
                   break;
                 }
                 c4=player;
                 is_input_correct=1;
                 break;
           case 5:
                   if (c5 != EMPTY) {
                     printf("Cell is not empty! Please try again!\n\n");
                     break;
                   }
                   c5=player;
                   is_input_correct=1;
                   break;
           case 6:
                   if (c6 != EMPTY) {
                     printf("Cell is not empty! Please try again!\n\n");
                     break;
                   }
                   c6=player;
                   is_input_correct=1;
                   break;
           case 7:
                   if (c7 != EMPTY) {
                     printf("Cell is not empty! Please try again!\n\n");
                     break;
                   }
                   c7=player;
                   is_input_correct=1;
                   break;
           case 8:
                   if (c8 != EMPTY) {
                       printf("Cell is not empty! Please try again!\n\n");
                       break;
                   }
                   c8=player;
                   is_input_correct=1;
                   break;
         }
         continue;
    }
  }while(!is_input_correct);
}

/*=================================================================================================================================================*/

/* Checks if one of the players wins the game, or if the board is full and the game ended with a draw. Prints how the game ended. */
/* Returns TRUE if the game ended, otherwise, does not print anything and just returns FALSE.                                     */

boolean checkAndPrintGameResult ( void )
{
  /* TODO */
    if (c0 == c1 && c0 == c2 && c0 != ' ') {
        printf("Player %c WINS (top row)!\n", c0);
    } else if (c3 == c4 && c3 == c5 && c3 != ' ') {
        printf("Player %c WINS (middle row)!\n", c3);
    } else if (c6 == c7 && c6 == c8 && c6 != ' ') {
        printf("Player %c WINS (bottom row)!\n", c6);
    } else if (c0 == c3 && c0 == c6 && c0 != ' ') {
        printf("Player %c WINS (left column)!\n", c0);
    } else if (c1 == c4 && c1 == c7 && c1 != ' ') {
        printf("Player %c WINS (middle column)!\n", c1);
    } else if (c2 == c5 && c2 == c8 && c2 != ' ') {
        printf("Player %c WINS (right column)!\n", c2);
    } else if (c0 == c4 && c0 == c8 && c0 != ' ') {
        printf("Player %c WINS (primary diagonal)!\n", c0);
    } else if (c2 == c4 && c2 == c6 && c2 != ' ') {
        printf("Player %c WINS (secondary diagonal)!\n", c2);
    } else if (c0 != ' ' && c1 != ' ' && c2 != ' ' && c3 != ' ' && c4 != ' ' && c5 != ' ' && c6 != ' ' && c7 != ' '
               && c8 != ' ') {
        printf("DRAW!\n");
    } else {
        return FALSE;
    }
    return TRUE;
}

/***************************************************************************************************************************************************/




/* Main Function ***********************************************************************************************************************************/

/* Initializes the global variables.                                                                                                          */
/* Prints banner.                                                                                                                             */
/* Randomly chooses one of the players to start first.                                                                                        */
/* Asks each player to make a move in turn until the game finishes (prints the board configuration each time before a player makes her move). */
/* Prints the game result.                                                                                                                    */
/* Prints a goodbye message.                                                                                                                  */
/* Prints the number of random numbers that were generated during the game play.                                                              */

int main ( void )
{
  char currentPlayer = ( ( randomIntegerMinMaxUnBiased( 0 , 1 ) == 0 ) ? PLAYER1 : PLAYER2 ) ;

  initializeGlobalVariables() ; /* initialize empty?? */
  printBanner              () ; /* This is done */
  printBoard               () ; /* print board for the situation of the game! */

  do
  {
    getNextMove( currentPlayer ) ;
    printBoard (               ) ;

    if   ( currentPlayer == PLAYER1 )  { currentPlayer = PLAYER2 ; }
    else                               { currentPlayer = PLAYER1 ; }
  }
  while ( checkAndPrintGameResult() == FALSE ) ;

  printf( "\nGood game. Have a nice day!\n" ) ;

  printf( "\n%d random numbers were generated during the game play.\n\n" , numberOfRandomNumbersGenerated ) ;

  return 0 ;
}

/***************************************************************************************************************************************************/
