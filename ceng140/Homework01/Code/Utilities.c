

/* Explanations *************************************************************************************************************************************
|
| - This file contains the definitions of some global variables, and implementations of some general-purpose utility functions.
| - In order to use these utilities, include the "Utilities.h" header file in your application, and then compile and link this file with the rest of
|   your application files.
|
****************************************************************************************************************************************************/




/* Includes ****************************************************************************************************************************************/

#include "Utilities.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <time.h>    /* For "time" function                                                                       */
#include <stdio.h>   /* For standard input/output functions, and definitions of some symbolic constants, like EOF */
#include <stdlib.h>  /* For "rand" and "srand" functions                                                          */

/***************************************************************************************************************************************************/




/* Global Variable Definitions *********************************************************************************************************************/

unsigned int numberOfRandomNumbersGenerated = 0 ;

/***************************************************************************************************************************************************/




/* Static Global Variable Definitions **************************************************************************************************************/

static unsigned char isRandomNumberGeneratorSeeded = FALSE ;

/***************************************************************************************************************************************************/




/* Utility Functions *******************************************************************************************************************************/

/* Seeds random number generator if it has not been seeded before. */

void seedRandomNumberGenerator ( void )
{
  if ( isRandomNumberGeneratorSeeded == FALSE )
  {
    srand( (unsigned int) time( NULL ) ) ;

    isRandomNumberGeneratorSeeded = TRUE ;
  }
}

/*=================================================================================================================================================*/

/* Returns a random integer between 0 and max, inclusive; [0,max]. */

int randomIntegerMaxNaive ( int max )
{
  numberOfRandomNumbersGenerated++ ;

  if ( max < 0 )  { return 0 ; }

  seedRandomNumberGenerator() ;

  return ( rand() % (max + 1) ) ;
}

/*=================================================================================================================================================*/

/* Returns a random integer between 0 and max, inclusive; [0,max]. */

int randomIntegerMaxUnBiased ( int max )
{
  int adjustedRandMax ;
  int result          ;

  numberOfRandomNumbersGenerated++ ;

  if ( max < 0 )  { return 0 ; }

  seedRandomNumberGenerator() ;

  adjustedRandMax = RAND_MAX - ( RAND_MAX % (max + 1) ) ;

  do { result = rand() ; } while ( result >= adjustedRandMax ) ;

  return ( result % (max + 1) ) ;
}

/*=================================================================================================================================================*/

/* Returns a random integer between min and max, inclusive; [min,max]. */

int randomIntegerMinMaxNaive ( int min , int max )
{
  if ( min > max )
  {
    numberOfRandomNumbersGenerated++ ;

    return min ;
  }

  return ( min + randomIntegerMaxNaive( max - min ) ) ;
}

/*=================================================================================================================================================*/

/* Returns a random integer between min and max, inclusive; [min,max]. */

int randomIntegerMinMaxUnBiased ( int min , int max )
{
  if ( min > max )
  {
    numberOfRandomNumbersGenerated++ ;

    return min ;
  }

  return ( min + randomIntegerMaxUnBiased( max - min ) ) ;
}

/*=================================================================================================================================================*/

/* Returns a random integer that is not equal to "except", and that is between min and max, inclusive; [min,max]. */
/* Assumption: The range [min,max] contains at least 2 numbers, or "except" is not within the range.              */

int randomIntegerMinMaxUnBiasedExcept1 ( int min , int max , int except )
{
  int result = randomIntegerMinMaxUnBiased( min , max ) ;

  if ( result == except    )  { result++     ; }
  if ( result == (max + 1) )  { result = min ; }

  return result ;
}

/*=================================================================================================================================================*/

/* Returns a random integer that is not equal to "except1" or "except2", and that is between min and max, inclusive; [min,max]. */
/* Assumption: The range [min,max] contains at least 3 numbers, or "except1" and/or "except2" are not within the range.         */

int randomIntegerMinMaxUnBiasedExcept2 ( int min , int max , int except1 , int except2 )
{
  int result = randomIntegerMinMaxUnBiased( min , max ) ;

  if ( ( result == except1 ) || ( result == except2 )  )  { result++     ; }  /* Check if result is equal to the smallest of except1 and except2 */
  if ( result == (max + 1)                             )  { result = min ; }

  if ( ( result == except1 ) || ( result == except2 )  )  { result++     ; }  /* Check if result is equal to the biggest of except1 and except2 */
  if ( result == (max + 1)                             )  { result = min ; }

  return result ;
}

/*=================================================================================================================================================*/

/* Assumes that the input buffer is NOT empty (otherwise blocks the application and asks the user for input). */
/* Consumes all the characters in the input buffer until and including the first occurance of '\n' or EOF.    */
/* Returns the last character read, that is, '\n' or EOF.                                                     */

int clearInputBuffer ( void )
{
  int c ;

  do { c = getchar() ; } while ( ( c != '\n' ) && ( c != EOF ) ) ;

  return c ;
}

/***************************************************************************************************************************************************/
