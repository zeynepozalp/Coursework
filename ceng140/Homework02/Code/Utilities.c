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
| - This file contains the definitions of some static global variables, and implementations of the utility functions declared in the header file.
| - In order to use these utilities, include the "Utilities.h" header file in your application, and then compile and link this file with the rest of
|   your application files.
|
****************************************************************************************************************************************************/




/* Includes ****************************************************************************************************************************************/

#include "Utilities.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include "Queue.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************************************************************************************************************/




/* Static Global Variable Definitions **************************************************************************************************************/

static unsigned maxNumberOfUsers          = 0 ;
static unsigned maxUserNameLength         = 0 ;
static unsigned maxNumberOfFriendsPerUser = 0 ;

/***************************************************************************************************************************************************/




/* Utility Functions *******************************************************************************************************************************/

void configureCengBook ( unsigned aMaxNumberOfUsers , unsigned aMaxUserNameLength , unsigned aMaxNumberOfFriendsPerUser )
{
  if ( aMaxUserNameLength > MAX_TOKEN_LENGTH )
  {
    NL ;  printf( "Error: MaxUserNameLength cannot be greater than %d! Exiting!\n\n" , MAX_TOKEN_LENGTH ) ;  exit( 0 ) ;
  }

  maxNumberOfUsers          = aMaxNumberOfUsers          ;
  maxUserNameLength         = aMaxUserNameLength         ;
  maxNumberOfFriendsPerUser = aMaxNumberOfFriendsPerUser ;
}

/*=================================================================================================================================================*/

unsigned getMaxNumberOfUsers          ( void ) { return maxNumberOfUsers          ; }
unsigned getMaxUserNameLength         ( void ) { return maxUserNameLength         ; }
unsigned getMaxNumberOfFriendsPerUser ( void ) { return maxNumberOfFriendsPerUser ; }

/*=================================================================================================================================================*/

BookPtr allocateBook ( void )
{
  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  BookPtr bookPtr = (BookPtr) malloc( sizeof( Book ) ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  if ( bookPtr != NULL )
  {
    bookPtr->userPointers = (UserPtrArray) malloc( maxNumberOfUsers * sizeof( UserPtr ) ) ;

    if (  bookPtr->userPointers != NULL  )
    {
      int i ;

      bookPtr->numberOfUsers = 0 ;

      for ( i = 0 ; i < maxNumberOfUsers ; i++ )  { bookPtr->userPointers[i] = NULL ; }
    }
    else  /* bookPtr->userPointers == NULL */
    {
      free( bookPtr ) ;

      bookPtr = NULL  ;
    }
  }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  return bookPtr ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/
}

/*=================================================================================================================================================*/

void deallocateBook ( BookPtr bookPtr )
{
  int i ;

  if ( bookPtr == NULL )  { return ; }

  for ( i = 0 ; i < maxNumberOfUsers ; i++ )  { deallocateUser( bookPtr->userPointers[i] ) ; }

  free( bookPtr->userPointers ) ;
  free( bookPtr               ) ;
}

/*=================================================================================================================================================*/

UserPtr allocateUser ( String name )
{
  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  UserPtr userPtr = (UserPtr) malloc( sizeof( User ) ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  if ( userPtr != NULL )
  {
    userPtr->name = (String) malloc( (maxUserNameLength + 1) * sizeof( char ) ) ;

    if ( userPtr->name != NULL )
    {
      userPtr->friendPointers = (UserPtrArray) malloc( maxNumberOfFriendsPerUser * sizeof( UserPtr ) ) ;

      if ( userPtr->friendPointers != NULL )
      {
        int i ;

        /* The following way of copying a string is safer than : strcpy( userPtr->name , name ) */

        strncpy( userPtr->name , name , maxUserNameLength + 1 ) ;  userPtr->name[ maxUserNameLength ] = '\0' ;

        userPtr->numberOfFollowers = 0 ;
        userPtr->numberOfFriends   = 0 ;

        for ( i = 0 ; i < maxNumberOfFriendsPerUser ; i++ )  { userPtr->friendPointers[i] = NULL ; }
      }
      else  /* userPtr->friendPointers == NULL */
      {
        free( userPtr->name ) ;
        free( userPtr       ) ;

        userPtr = NULL ;
      }
    }
    else  /* userPtr->name == NULL */
    {
      free( userPtr ) ;

      userPtr = NULL ;
    }
  }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  return userPtr ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/
}

/*=================================================================================================================================================*/

void deallocateUser ( UserPtr userPtr )
{
  if ( userPtr == NULL )  { return ; }

  free( userPtr->name           ) ;
  free( userPtr->friendPointers ) ;
  free( userPtr                 ) ;
}

/*=================================================================================================================================================*/

UserPtr getUserPtrByName ( BookPtr bookPtr , String userName )
{
  int i ;

  for ( i = 0 ; i < bookPtr->numberOfUsers ; i++ )
  {
    if ( strcmp( bookPtr->userPointers[i]->name , userName ) == 0 )  { return bookPtr->userPointers[i] ; }
  }

  return NULL ;
}

/*=================================================================================================================================================*/

UserPtr getUserPtrByIndex ( BookPtr bookPtr , int userIndex )
{
  if ( userIndex >= bookPtr->numberOfUsers )  { return NULL ; }

  return bookPtr->userPointers[ userIndex ] ;
}

/*=================================================================================================================================================*/

int getUserIndexByPtr ( BookPtr bookPtr , UserPtr userPtr )
{
  int i ;

  for ( i = 0 ; i < bookPtr->numberOfUsers ; i++ )
  {
    if ( userPtr == bookPtr->userPointers[i] )  { return i ; }
  }

  return -1 ;
}

/*=================================================================================================================================================*/

void printUser ( UserPtr userPtr )
{
  int i ;

  I2 ;  printf( "%s : %u Follower(s) , %u Friend(s)\n" , userPtr->name , userPtr->numberOfFollowers , userPtr->numberOfFriends ) ;

  if ( userPtr->numberOfFriends > 0 )  { printf( "\n" ) ; }

  for ( i = 0 ; i < userPtr->numberOfFriends ; i++ )
  {
    I2 ;  printf( "%d - %s\n" , i + 1 , userPtr->friendPointers[i]->name ) ;
  }
}

/*=================================================================================================================================================*/

boolean isConnected ( UserPtr userPtr1 , UserPtr userPtr2 )
{
  int i ;

  for ( i = 0 ; i < userPtr1->numberOfFriends ; i++ )
  {
    if ( userPtr1->friendPointers[i] == userPtr2 )  { return TRUE ; }
  }

  return FALSE ;
}

/*=================================================================================================================================================*/

boolean removeConnection ( UserPtr userPtr , UserPtr friendPtr )
{
  int i , friendIndex ;

  for ( friendIndex = 0 ; friendIndex < userPtr->numberOfFriends ; friendIndex++ )
  {
    if ( userPtr->friendPointers[friendIndex] == friendPtr )  { break ; }
  }

  if ( friendIndex >= userPtr->numberOfFriends )  { return FALSE ; }

  for ( i = friendIndex ; i < userPtr->numberOfFriends - 1 ; i++ )
  {
    userPtr->friendPointers[i] = userPtr->friendPointers[i+1] ;
  }

  userPtr->friendPointers[ --(userPtr->numberOfFriends) ] = NULL ;

  (friendPtr->numberOfFollowers)-- ;

  return TRUE ;
}

/*=================================================================================================================================================*/

int compareByName ( UserPtr userPtr1 , UserPtr userPtr2 )
{
  return strcmp( userPtr1->name , userPtr2->name ) ;
}

/*=================================================================================================================================================*/

int compareByPopularity ( UserPtr userPtr1 , UserPtr userPtr2 )
{
  if      (  userPtr1->numberOfFollowers >  userPtr2->numberOfFollowers  )  { return  1 ; }
  else if (  userPtr1->numberOfFollowers == userPtr2->numberOfFollowers  )  { return  0 ; }
  else    /* userPtr1->numberOfFollowers <  userPtr2->numberOfFollowers */  { return -1 ; }
}

/*=================================================================================================================================================*/

void sortBook ( BookPtr bookPtr , ComparatorFunctionPointer compareFunctionPtr , boolean ascending )  /* Bubble sort */ /*IKINCI PARAMETREYI ANLAMADIM?? */
{
  int     index1   , index2   , comparisonResult ;
  UserPtr userPtr1 , userPtr2                    ;

  for ( index1 = bookPtr->numberOfUsers - 1 ; index1 > 0 ; index1-- )
  {
    for ( index2 = 0 ; index2 < index1 ; index2++ )
    {
      userPtr1 = bookPtr->userPointers[ index2     ] ;
      userPtr2 = bookPtr->userPointers[ index2 + 1 ] ;

      comparisonResult = (* compareFunctionPtr)( userPtr1 , userPtr2 ) ;

      if ( ascending == FALSE )  { comparisonResult *= -1 ; }

      if ( comparisonResult > 0 )
      {
        bookPtr->userPointers[ index2     ] = userPtr2 ;
        bookPtr->userPointers[ index2 + 1 ] = userPtr1 ;
      }
    }
  }
}

/*=================================================================================================================================================*/

UserPtrArray shortestPath ( BookPtr bookPtr , UserPtr startUserPtr , UserPtr targetUserPtr )  /* Breadth-first search (with uniform edge cost) */
{
  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  static QueuePtr       queuePtr                 = NULL  ;  /* First-in first-out (FIFO) queue                 (one of the search tools) */
  static int          * followerIndicesArray     = NULL  ;  /* Array that keeps the index of the follower user (one of the search tools) */
  static UserPtrArray   friendPtrChainArray      = NULL  ;  /* Array that keeps pointers to users in the chain (one of the search tools) */
  static boolean        isSearchToolsInitialized = FALSE ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  UserPtr userPtr   , friendPtr                                          ;
  int     userIndex , friendIndex , startUserIndex , targetUserIndex , i ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  if ( startUserPtr == targetUserPtr )  { return NULL ; }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  if ( isSearchToolsInitialized == FALSE )
  {
    queuePtr = qAllocate( maxNumberOfUsers ) ;

    if ( queuePtr == NULL )  { return NULL ; }

    followerIndicesArray = (int *) malloc( maxNumberOfUsers * sizeof( int ) ) ;

    if ( followerIndicesArray == NULL )  { free( queuePtr ) ;  queuePtr = NULL ;  return NULL ; }

    friendPtrChainArray = (UserPtrArray) malloc( (maxNumberOfUsers + 1) * sizeof( UserPtr ) ) ;

    if ( friendPtrChainArray == NULL )
    {
      free( queuePtr             ) ;  queuePtr             = NULL ;
      free( followerIndicesArray ) ;  followerIndicesArray = NULL ;

      return NULL ;
    }

    isSearchToolsInitialized = TRUE ;
  }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  startUserIndex  = getUserIndexByPtr( bookPtr , startUserPtr  ) ;
  targetUserIndex = getUserIndexByPtr( bookPtr , targetUserPtr ) ;

  /* In the "followerIndicesArray" array ;                                                                                                 */
  /* - The value "-2" is chosen to mark users that are "not-visited" in the search yet                                                     */
  /* - The value "-1" is chosen as a special follower index for the start user (follower of start user is not important in finding a path) */

  for ( i = 0 ; i < maxNumberOfUsers ; i++ )  { followerIndicesArray[i] = -2 ; }

  followerIndicesArray[ startUserIndex ] = -1 ;

  qReset( queuePtr                ) ;
  qPut  ( queuePtr , startUserPtr ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  while ( ! qIsEmpty( queuePtr ) )
  {
    userPtr   = (UserPtr) qGet( queuePtr ) ;
    userIndex = getUserIndexByPtr( bookPtr , userPtr ) ;

    for ( i = 0 ; i < userPtr->numberOfFriends ; i++ )
    {
      friendPtr   = userPtr->friendPointers[i]               ;
      friendIndex = getUserIndexByPtr( bookPtr , friendPtr ) ;

      if ( followerIndicesArray[ friendIndex ] == -2 )
      {
        followerIndicesArray[ friendIndex ] = userIndex ;

        if ( friendPtr == targetUserPtr )  { qReset( queuePtr ) ;  break ; }

        qPut( queuePtr , friendPtr ) ;
      }
    }
  }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  if ( followerIndicesArray[ targetUserIndex ] == -2 )  { return NULL ; }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  userIndex                = targetUserIndex  ;
  i                        = maxNumberOfUsers ;
  friendPtrChainArray[ i ] = NULL             ;

  while ( userIndex >= 0 )
  {
    friendPtrChainArray[ --i ] = bookPtr->userPointers[ userIndex ] ;

    userIndex = followerIndicesArray[ userIndex ] ;
  }

  return ( friendPtrChainArray + i ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/
}

/*=================================================================================================================================================*/

void indent ( unsigned short numberOfSpaces )
{
  int i ;

  for ( i = 0 ; i < numberOfSpaces ; i++ )  { printf( " " ) ; }
}

/*=================================================================================================================================================*/

void newline ( unsigned short numberOfLines )
{
  int i ;

  for ( i = 0 ; i < numberOfLines ; i++ )  { printf( "\n" ) ; }
}

/*=================================================================================================================================================*/

StringArray tokenize ( String inText , int * outNumberOfTokens )
{
  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  static char    tokens[ MAX_TOKENS ][ MAX_TOKEN_LENGTH + 1 ] ;  /* Static storage for the tokens which will be retrieved from the input text */
  static String  result[ MAX_TOKENS ]                         ;  /* Static storage for the result to be returned                              */
  static boolean isResultInitialized = FALSE                  ;  /* The entries of result need to be initialized just once, this is its flag  */

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  int     currentTokenIndex          = 0     ;  /* Index of the current token being retrieved from the input text                       */
  int     textCharacterIndex         = 0     ;  /* Index of the current character about to be read from the input text                  */
  int     currentTokenCharacterIndex = 0     ;  /* Index of the current character position (to be written) of the current token         */
  char    currentCharacter           = '\0'  ;  /* Current character that has just been retrieved from the input text                   */
  boolean insideToken                = FALSE ;  /* Are we currently inside a token (collecting its letters from the input text), or not */
  boolean endOfTextReached           = FALSE ;  /* Should we stop processing, or not                                                    */

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  if ( ! isResultInitialized )
  {
    int i ;

    for ( i = 0 ; i < MAX_TOKENS ; i++ )  { result[i] = tokens[i] ; }

    isResultInitialized = TRUE ;
  }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  while ( endOfTextReached != TRUE )
  {
    currentCharacter = inText[ textCharacterIndex++ ] ;

    switch ( currentCharacter )
    {
      /*-------------------------------------------------------------------------------------------------------------------------------------------*/
      /* String termination and whitespace characters */

      case  '\0' : /* String termination character */  endOfTextReached = TRUE ;  /* Deliberate fall-through here */
      case  ' '  : /* (0x20) Space           (SPC) */
      case  '\t' : /* (0x09) Horizontal tab  (TAB) */
      case  '\n' : /* (0x0a) Newline         (LF ) */
      case  '\v' : /* (0x0b) Vertical tab    (VT ) */
      case  '\f' : /* (0x0c) Form feed       (FF ) */
      case  '\r' : /* (0x0d) Carriage return (CR ) */

                   if ( insideToken == TRUE )  /* We were processing a token, and now the token has been ended */
                   {
                     tokens[ currentTokenIndex++ ][ currentTokenCharacterIndex ] = '\0'  ;
                     currentTokenCharacterIndex                                  = 0     ;
                     insideToken                                                 = FALSE ;
                   }
                   /* else, we can just let the loop skip over the current character, there is nothing special to be done */

                   break ;
      /*-------------------------------------------------------------------------------------------------------------------------------------------*/
      /* Non-whitespace characters */

      default    : if ( insideToken == FALSE )  /* We were skipping over whitespace characters, but now a new token has started */
                   {
                     insideToken = TRUE ;
                   }
                   /* else, the processing of the current token continues, there is nothing special to be done */

                   if ( currentTokenCharacterIndex < MAX_TOKEN_LENGTH )
                   {
                     tokens[ currentTokenIndex ][ currentTokenCharacterIndex++ ] = currentCharacter ;
                   }
                   /* else, the current token is longer than MAX_TOKEN_LENGTH, so we skip (truncate) the extra characters */

                   break ;
      /*-------------------------------------------------------------------------------------------------------------------------------------------*/
    }

    if ( currentTokenIndex == MAX_TOKENS )  /* We need to stop collecting new tokens, they will not fit in the static storage allocated for them */
    {
      endOfTextReached = TRUE ;
    }
  }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  *outNumberOfTokens = currentTokenIndex ;

  return result ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/
}

/***************************************************************************************************************************************************/
