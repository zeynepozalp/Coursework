/****************************************************************************************************************************************************
|
| Copyright (C) 2018 Selim Temizer.
|
| This program is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
| as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
|
| This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
|
| You should have received a copy of the GNU Lesser General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.
|
****************************************************************************************************************************************************/




/* Explanations *************************************************************************************************************************************
|
| This file contains the declarations of the global variables, and the utility functions that are defined in "Utilities.c" file.
|
****************************************************************************************************************************************************/




/* Multiple Inclusion Guard ************************************************************************************************************************/

#ifndef __CENG140_SECTION2_HOMEWORK_UTILITIES__
#define __CENG140_SECTION2_HOMEWORK_UTILITIES__

/***************************************************************************************************************************************************/




/* Macro Definitions *******************************************************************************************************************************/

#define TRUE  ( 1 )
#define FALSE ( 0 )

/***************************************************************************************************************************************************/




/* Declarations of Global Variables ****************************************************************************************************************/

extern unsigned int numberOfRandomNumbersGenerated ;

/***************************************************************************************************************************************************/




/* Declarations (Prototypes) of Utility Functions **************************************************************************************************/

void seedRandomNumberGenerator  ( void              ) ;  /* Seeds random number generator if it has not been seeded before. */

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

int randomIntegerMaxNaive       ( int max           ) ;  /* Returns a random integer between 0 and max, inclusive; [0,max]. */
int randomIntegerMaxUnBiased    ( int max           ) ;  /* Returns a random integer between 0 and max, inclusive; [0,max]. */

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

int randomIntegerMinMaxNaive    ( int min , int max ) ;  /* Returns a random integer between min and max, inclusive; [min,max]. */
int randomIntegerMinMaxUnBiased ( int min , int max ) ;  /* Returns a random integer between min and max, inclusive; [min,max]. */

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Returns a random integer that is not equal to "except", and that is between min and max, inclusive; [min,max]. */
/* Assumption: The range [min,max] contains at least 2 numbers, or "except" is not within the range.              */

int randomIntegerMinMaxUnBiasedExcept1 ( int min , int max , int except ) ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Returns a random integer that is not equal to "except1" or "except2", and that is between min and max, inclusive; [min,max]. */
/* Assumption: The range [min,max] contains at least 3 numbers, or "except1" and/or "except2" are not within the range.         */

int randomIntegerMinMaxUnBiasedExcept2 ( int min , int max , int except1 , int except2 ) ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Assumes that the input buffer is NOT empty (otherwise blocks the application and asks the user for input). */
/* Consumes all the characters in the input buffer until and including the first occurance of '\n' or EOF.    */
/* Returns the last character read, that is, '\n' or EOF.                                                     */

int clearInputBuffer ( void ) ;

/***************************************************************************************************************************************************/




/* End of Multiple Inclusion Guard *****************************************************************************************************************/

#endif

/***************************************************************************************************************************************************/
