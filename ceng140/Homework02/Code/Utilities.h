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
| This file contains some common macros, definitions of new types, and declarations of some utility functions that are defined in "Utilities.c" file.
|
****************************************************************************************************************************************************/




/* Multiple Inclusion Guard ************************************************************************************************************************/

#ifndef __CENG140_SECTION2_HOMEWORK_UTILITIES__
#define __CENG140_SECTION2_HOMEWORK_UTILITIES__

/***************************************************************************************************************************************************/




/* Macro Definitions *******************************************************************************************************************************/

#define TRUE             ( 1            )
#define FALSE            ( 0            )

#define MAX_TOKENS       ( 5            )
#define MAX_TOKEN_LENGTH ( 50           )
#define MAX_INPUT_LENGTH ( 100          )

#define NL               ( newline( 1 ) )
#define I2               ( indent ( 2 ) )
#define I4               ( indent ( 4 ) )

/***************************************************************************************************************************************************/




/* Type Definitions ********************************************************************************************************************************/

typedef char        * String       ;
typedef String      * StringArray  ;
typedef int           boolean      ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

typedef struct user   User         ;  /* This is a forward type definition. The "struct user" data type will be defined below. */
typedef User        * UserPtr      ;
typedef User        * UserArray    ;
typedef UserPtr     * UserPtrArray ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

typedef struct book   Book         ;  /* This is a forward type definition. The "struct book" data type will be defined below. */
typedef Book        * BookPtr      ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

typedef int (* ComparatorFunctionPointer) ( UserPtr , UserPtr ) ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

struct user
{
  String       name                ;  /* Name of the user                                    */
  unsigned int numberOfFollowers   ;  /* Number of incoming connections                      */
  unsigned int numberOfFriends     ;  /* Number of outgoing connections                      */
  UserPtrArray friendPointers      ;  /* Array of pointers to friends (outgoing connections) */
} ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

struct book
{
  unsigned     numberOfUsers       ;  /* Number of CengBook users that have registered so far */
  UserPtrArray userPointers        ;  /* Array of pointers to users                           */
} ;

/***************************************************************************************************************************************************/




/* Declarations (Prototypes) of Utility Functions **************************************************************************************************/

/* Configuration Related Functions ----------------------------------------------------------------------------------------------------------------*/

void configureCengBook ( unsigned maxNumberOfUsers          ,  /* This function should be called before any other function in this utility package */
                         unsigned maxUserNameLength         ,
                         unsigned maxNumberOfFriendsPerUser ) ;

unsigned getMaxNumberOfUsers          ( void ) ;
unsigned getMaxUserNameLength         ( void ) ;
unsigned getMaxNumberOfFriendsPerUser ( void ) ;

/* Allocation/Deallocation Functions --------------------------------------------------------------------------------------------------------------*/

BookPtr allocateBook   ( void            ) ;
void    deallocateBook ( BookPtr bookPtr ) ;

UserPtr allocateUser   ( String  name    ) ;
void    deallocateUser ( UserPtr userPtr ) ;

/* User Manipulation Functions --------------------------------------------------------------------------------------------------------------------*/

UserPtr getUserPtrByName  ( BookPtr bookPtr  , String  userName  ) ;
UserPtr getUserPtrByIndex ( BookPtr bookPtr  , int     userIndex ) ;
int     getUserIndexByPtr ( BookPtr bookPtr  , UserPtr userPtr   ) ;

void    printUser         ( UserPtr userPtr                      ) ;
boolean isConnected       ( UserPtr userPtr1 , UserPtr userPtr2  ) ;
boolean removeConnection  ( UserPtr userPtr  , UserPtr friendPtr ) ;

/* Sorting Related Functions ----------------------------------------------------------------------------------------------------------------------*/

int compareByName       ( UserPtr userPtr1 , UserPtr userPtr2 ) ;
int compareByPopularity ( UserPtr userPtr1 , UserPtr userPtr2 ) ;

void sortBook ( BookPtr bookPtr , ComparatorFunctionPointer compareFunctionPtr , boolean ascending ) ;

/* Searching Related Functions --------------------------------------------------------------------------------------------------------------------*/

UserPtrArray shortestPath ( BookPtr bookPtr , UserPtr startUserPtr , UserPtr targetUserPtr ) ;

/* Input/Output Related Functions -----------------------------------------------------------------------------------------------------------------*/

void indent  ( unsigned short numberOfSpaces ) ;
void newline ( unsigned short numberOfLines  ) ;

StringArray tokenize ( String inText , int * outNumberOfTokens ) ;

/***************************************************************************************************************************************************/




/* End of Multiple Inclusion Guard *****************************************************************************************************************/

#endif

/***************************************************************************************************************************************************/
