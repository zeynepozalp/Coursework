/* Explanations *************************************************************************************************************************************
|
| This file implements CengBook, which is a realistic simulation of a mini social-media application.
|
****************************************************************************************************************************************************/




/* Includes ****************************************************************************************************************************************/

#include "Utilities.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************************************************************************************************************/




/* Macro Definitions *******************************************************************************************************************************/

#define AUTHOR ( "ZEYNEP OZALP" )  /* Author's name */  /* TODO: Replace with your name */

/***************************************************************************************************************************************************/




/* Global Variable Definitions *********************************************************************************************************************/

BookPtr bookPtr ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#if   defined(_WIN16) || defined(_WIN32) || defined(_WIN64)

  char operatingSystem[] = "Windows" ;  /* This is a Windows environment.                            */

#elif defined(__linux__)

  char operatingSystem[] = "Linux"   ;  /* This is a Linux environment (any GNU/Linux distribution). */

#elif defined(__APPLE__)

  char operatingSystem[] = "MacOSX"  ;  /* This is a Mac OS X environment.                           */

#endif

/***************************************************************************************************************************************************/




/* Functions ***************************************************************************************************************************************/

void printUsage ( String applicationName )
{
  NL ;

  printf( "Usage: %s <MaxNumberOfUsers> <MaxUserNameLength> <MaxNumberOfFriendsPerUser>\n\n" , applicationName ) ;
}

/*=================================================================================================================================================*/

void printBanner ( void )
{
  NL ;

  printf( "*******************************************************************************" "\n"          ) ;
  printf( "* CengBook                                                                    *" "\n"          ) ;
  printf( "* by %-72s *"                                                                    "\n" , AUTHOR ) ;
  printf( "*******************************************************************************" "\n"          ) ;
}

/*=================================================================================================================================================*/

void printMenu ( void )
{
  NL ;

  printf( "*******************************************************************************" "\n" ) ;
  printf( "Help                       : Print this menu"                                    "\n" ) ;
  printf( "List                       : List all users"                                     "\n" ) ;
  printf( "Plot                       : Create a plot of CengBook (requires GraphViz)"      "\n" ) ;
  printf( "Quit                       : Exit application"                                   "\n" ) ;
  printf( "-------------------------------------------------------------------------------" "\n" ) ;
  printf( "Register   <user>          : Create a new user and add it to CengBook"           "\n" ) ;
  printf( "Delete     <user>          : Delete user from CengBook"                          "\n" ) ;
  printf( "Find       <user>          : Search CengBook for user, display user information" "\n" ) ;
  printf( "Connect    <user1> <user2> : Add a connection from user1 to user2"               "\n" ) ;
  printf( "Disconnect <user1> <user2> : Remove connection from user1 to user2"              "\n" ) ;
  printf( "Path       <user1> <user2> : Find shortest path from user1 to user2"             "\n" ) ;
  printf( "-------------------------------------------------------------------------------" "\n" ) ;
  printf( "Sort <abc|pop> <asc|desc>  : Sort all users (alphabetically or by popularity)"   "\n" ) ;
  printf( "*******************************************************************************" "\n" ) ;
}

/*=================================================================================================================================================*/

void commandHelp ( void )
{
  /* TODO */
  printMenu();
}

/*=================================================================================================================================================*/

void commandList ( void )
{
  /* TODO */
  int i=0;
  NL;
  if(bookPtr->numberOfUsers==0) {
    I2; printf("Cengbook is empty"); NL;
  }
  else{
    while(i<(bookPtr->numberOfUsers)){
      if((bookPtr->userPointers)[i]!=NULL){
        I2 ;  printf( "%s : %u Follower(s) , %u Friend(s)\n" , ((bookPtr->userPointers)[i])->name , ((bookPtr->userPointers)[i])->numberOfFollowers , ((bookPtr->userPointers)[i])->numberOfFriends ) ;
      }
      i++;
    }
  }
}

/*=================================================================================================================================================*/

void commandPlot ( void )
{
  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  UserPtr   userPtr             , friendPtr              ;
  int       userIndex           , friendIndex            ;
  String    runDotSystemCommand , openImageSystemCommand ;

  FILE    * file = fopen( "CengBook.dot" , "w" )         ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  fprintf( file , "digraph CengBook"                                                       "\n"                            ) ;
  fprintf( file , "{"                                                                      "\n"                            ) ;
  fprintf( file , "  graph [label=\"CengBook\\nNumber of users = %d\" , labelloc=t] ;"     "\n\n" , bookPtr->numberOfUsers ) ;
  fprintf( file , "  node  [shape=ellipse , fontcolor=black , color=red , penwidth=2.0] ;" "\n\n"                          ) ;
  fprintf( file , "  edge  [color=blue , penwidth=2.0] ;"                                  "\n\n"                          ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  for ( userIndex = 0 ; userIndex < bookPtr->numberOfUsers ; userIndex++ )
  {
    userPtr = bookPtr->userPointers[ userIndex ] ;

    fprintf( file , "  %s [label=\"%s\\n%d Friend(s)\\n%d Follower(s)\"] ;\n" ,
             userPtr->name                                                    ,
             userPtr->name                                                    ,
             userPtr->numberOfFriends                                         ,
             userPtr->numberOfFollowers                                       ) ;
  }

  if ( bookPtr->numberOfUsers > 0 )  { fprintf( file , "\n" ) ; }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  for ( userIndex = 0 ; userIndex < bookPtr->numberOfUsers ; userIndex++ )
  {
    userPtr = bookPtr->userPointers[ userIndex ] ;

    for ( friendIndex = 0 ; friendIndex < userPtr->numberOfFriends ; friendIndex++ )
    {
      friendPtr = userPtr->friendPointers[ friendIndex ] ;

      fprintf( file , "  %s -> %s ;\n" , userPtr->name , friendPtr->name ) ;
    }
  }

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  fprintf( file , "}\n" ) ;
  fclose ( file         ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/

  if ( strcmp( operatingSystem , "Windows" ) == 0 )
  {
    runDotSystemCommand    = "CMD /C dot -Tgif CengBook.dot -o CengBook.gif" ;
    openImageSystemCommand = "CMD /C START CengBook.gif"                     ;
  }
  else  /* Assumption: Linux */
  {
    runDotSystemCommand    = "dot -Tgif CengBook.dot -o CengBook.gif"        ;
    openImageSystemCommand = "xdg-open CengBook.gif &"                       ;
  }

  if ( system( runDotSystemCommand    ) ) ;  /* "if" statement is used to eliminate warning about unused return value of "system" call */
  if ( system( openImageSystemCommand ) ) ;  /* "if" statement is used to eliminate warning about unused return value of "system" call */

  NL ;  I2 ;  printf( "Plot prepared\n" ) ;

  /*-----------------------------------------------------------------------------------------------------------------------------------------------*/
}

/*=================================================================================================================================================*/

void commandQuit ( void )
{
  /* TODO */
  deallocateBook(bookPtr);
  NL; I2;
  printf("Have a nice day");
  NL; NL;
  exit(0);
}

/*=================================================================================================================================================*/

void commandRegister ( String userName )
{
  /* TODO */
  unsigned max=getMaxNumberOfUsers();
  unsigned maxName=getMaxUserNameLength();
  NL; I2;

  if(bookPtr->numberOfUsers==max) {printf("Cengbook is full, cannot register any new users!");}

  else if (strlen(userName)>maxName) {printf("User name is longer than %d characters!", maxName);}

  else {
    UserPtr newUser = allocateUser(userName);
    bookPtr->userPointers[(bookPtr->numberOfUsers)]=newUser;
    bookPtr->numberOfUsers++;
    printf("User '%s' registered successfully", userName);
  }
  NL;
}

/*=================================================================================================================================================*/

void commandDelete ( String userName ) /* BUNDA BİR SORUN VAR BENCE */
{
  /* TODO */
  UserPtr currFriend, currUser, userptr=getUserPtrByName(bookPtr, userName);
  int index, i;
  unsigned max=getMaxNumberOfUsers();
  NL;
  if (userptr==NULL) { I2; printf("User '%s' not found in Cengbook!", userName); NL;}
  else {
    if((userptr->numberOfFollowers)!=0) {
      for(i=0; i<(bookPtr->numberOfUsers); i++){
        currUser=(bookPtr->userPointers)[i];
        if(isConnected(currUser,userptr)) {
          removeConnection(currUser, userptr);
          I2; printf("User '%s' is removed from friends of user '%s'", userName, currUser->name); NL;
        }
      }
    }
    if((userptr->numberOfFriends)!=0) {
      for(i=0; i<(userptr->numberOfFriends); i++){
        currFriend=(userptr->friendPointers)[i];
        currFriend->numberOfFollowers--;
        I2; printf("User '%s' is discounted from followers of user '%s'", userName, currFriend->name); NL;
      }
    }
    index=getUserIndexByPtr(bookPtr, userptr);
    bookPtr->userPointers[index]=NULL;
    for(i=index; i<(bookPtr->numberOfUsers); i++){
      (bookPtr->userPointers)[index]=(bookPtr->userPointers)[index+1];
    }
    bookPtr->numberOfUsers--;
    deallocateUser(userptr);
    I2; printf("User '%s' is deleted from Cengbook", userName); NL;
  }
}

/*=================================================================================================================================================*/

void commandFind ( String userName )
{
  /* TODO */
  UserPtr userptr=getUserPtrByName(bookPtr, userName);
  NL;
  if(userptr==NULL) { I2; printf("User '%s' not found in Cengbook!", userName); NL; }
  else {
    printUser(userptr);
  }
}

/*=================================================================================================================================================*/

void commandConnect ( String userName1 , String userName2 )
{
  /* TODO */
  UserPtr userptr1, userptr2;
  userptr1=getUserPtrByName(bookPtr, userName1);
  userptr2=getUserPtrByName(bookPtr, userName2);
  NL;
  if(userptr1==NULL) { I2; printf("User '%s' not found in Cengbook!", userName1); NL; }
  if(userptr2==NULL) { I2; printf("User '%s' not found in Cengbook!", userName2); NL; }
  if(userptr1==NULL || userptr2==NULL) return;
  else if(isConnected(userptr1, userptr2)) { I2; printf("User '%s' is already connected to '%s'!", userName1, userName2); NL; }
  else{
    (userptr1->friendPointers)[userptr1->numberOfFriends]=userptr2;
    userptr1->numberOfFriends++;
    userptr2->numberOfFollowers++;
    I2; printf("User '%s' is successfully connected to user '%s'", userName1, userName2); NL;
  }
}

/*=================================================================================================================================================*/

void commandDisconnect ( String userName1 , String userName2 )
{
  /* TODO */
  UserPtr userptr1, userptr2;
  int i, j;
  userptr1=getUserPtrByName(bookPtr, userName1);
  userptr2=getUserPtrByName(bookPtr, userName2);
  NL;
  if(userptr1==NULL) { I2; printf("User '%s' not found in Cengbook!", userName1); NL; }
  if(userptr2==NULL) { I2; printf("User '%s' not found in Cengbook!", userName2); NL; }
  if(userptr1==NULL || userptr2==NULL) return;
  else if(!(isConnected(userptr1, userptr2))) { I2; printf("User '%s' and user '%s' are not connected!", userName1, userName2); NL; }
  else{
    for(i=0; i<(userptr1->numberOfFriends); i++){
      if((userptr1->friendPointers)[i]==userptr2) break;
    }
    for(j=i-1;j<(userptr1->numberOfFriends);j++){
      (userptr1->friendPointers)[j]=(userptr1->friendPointers)[j+1];
    }
    (userptr1->friendPointers)[userptr1->numberOfFriends]=NULL;
    userptr1->numberOfFriends--;
    userptr2->numberOfFollowers--;
    I2; printf("User '%s' successfully disconnected from user '%s'", userName1, userName2); NL;
  }
}

/*=================================================================================================================================================*/

void commandPath ( String userName1 , String userName2 )
{
  /* TODO */
  UserPtr userptr1, userptr2;
  UserPtrArray result;
  int i=0;
  userptr1=getUserPtrByName(bookPtr, userName1);
  userptr2=getUserPtrByName(bookPtr, userName2);
  NL;
  if(userptr1==NULL) { I2; printf("User '%s' not found in Cengbook!", userName1); NL; }
  if(userptr2==NULL) { I2; printf("User '%s' not found in Cengbook!", userName2); NL; }
  if(userptr1==NULL || userptr2==NULL) return;
  if(userptr1==userptr2) { I2; printf("Path to self queried!"); NL; return; }
  I2;
  result=shortestPath(bookPtr, userptr1, userptr2);
  if(result==NULL) { printf("There is no path from user '%s' to user '%s'", userName1, userName2); NL; return; }
  while(result[i]!=NULL){
    printf("'%s'", (result[i])->name);
    if(result[++i]!=NULL) { printf(" -> "); }
  }
  NL;
}

/*=================================================================================================================================================*/

void commandSort ( String criterion , String order )
{
  /* TODO */
  ComparatorFunctionPointer abc=&(compareByName);
  ComparatorFunctionPointer pop=&(compareByPopularity);
  NL; I2;
  if(strcmp(order, "asc")==0 && strcmp(criterion, "abc")==0){
    sortBook(bookPtr, abc, 1);
    printf("CengBook sorted 'alphabetically' in 'ascending' order");
  }
  else if(strcmp(order, "asc")==0 && strcmp(criterion, "pop")==0){
    sortBook(bookPtr, pop, 1);
    printf("CengBook sorted 'by popularity' in 'ascending' order");
  }
  else if(strcmp(order, "desc")==0 && strcmp(criterion, "abc")==0){
    sortBook(bookPtr, abc, 0);
    printf("CengBook sorted 'alphabetically' in 'descending' order");
  }
  else if(strcmp(order, "desc")==0 && strcmp(criterion, "pop")==0){
    sortBook(bookPtr, pop, 0);
    printf("CengBook sorted 'by popularity' in 'descending' order");
  }
  else{
    if(strcmp(order, "asc")==0 || strcmp(order, "desc")==0){
      printf("Invalid sort criterion '%s'!", criterion);
    }
    else if(strcmp(criterion, "abc")==0 || strcmp(criterion, "pop")==0){
      printf("Invalid sort order '%s'!", order);
    }
    else{
      printf("Invalid sort criterion '%s'!", criterion); NL; I2;
      printf("Invalid sort order '%s'!", order);
    }
  }
  NL;
}

/*=================================================================================================================================================*/

void processInput ( String input )
{
  int         i                                                    ;
  int         numberOfTokens = 0                                   ;
  StringArray tokens         = tokenize( input , &numberOfTokens ) ;
  String      command                                              ;

  if ( numberOfTokens < 1 )  { return ; }

  command = tokens[0] ;

  for ( i = 0 ; i < strlen( command ) ; i++ )  { if ( ( command[i] >= 'A' ) && ( command[i] <= 'Z' ) )  { command[i] += 'a' - 'A' ; } }

  if      ( strcmp( command , "help"       ) == 0 )  { if ( numberOfTokens == 1 ) { commandHelp      (                       ) ;  return ; } }
  else if ( strcmp( command , "list"       ) == 0 )  { if ( numberOfTokens == 1 ) { commandList      (                       ) ;  return ; } }
  else if ( strcmp( command , "plot"       ) == 0 )  { if ( numberOfTokens == 1 ) { commandPlot      (                       ) ;  return ; } }
  else if ( strcmp( command , "quit"       ) == 0 )  { if ( numberOfTokens == 1 ) { commandQuit      (                       ) ;  return ; } }
  else if ( strcmp( command , "register"   ) == 0 )  { if ( numberOfTokens == 2 ) { commandRegister  ( tokens[1]             ) ;  return ; } }
  else if ( strcmp( command , "delete"     ) == 0 )  { if ( numberOfTokens == 2 ) { commandDelete    ( tokens[1]             ) ;  return ; } }
  else if ( strcmp( command , "find"       ) == 0 )  { if ( numberOfTokens == 2 ) { commandFind      ( tokens[1]             ) ;  return ; } }
  else if ( strcmp( command , "connect"    ) == 0 )  { if ( numberOfTokens == 3 ) { commandConnect   ( tokens[1] , tokens[2] ) ;  return ; } }
  else if ( strcmp( command , "disconnect" ) == 0 )  { if ( numberOfTokens == 3 ) { commandDisconnect( tokens[1] , tokens[2] ) ;  return ; } }
  else if ( strcmp( command , "path"       ) == 0 )  { if ( numberOfTokens == 3 ) { commandPath      ( tokens[1] , tokens[2] ) ;  return ; } }
  else if ( strcmp( command , "sort"       ) == 0 )  { if ( numberOfTokens == 3 ) { commandSort      ( tokens[1] , tokens[2] ) ;  return ; } }
  else                                               { NL ;  I2 ;  printf( "Invalid command!\n" ) ;                               return ;   }

  /* If we reach here, the user must have provided incorrect number of arguments to a valid command */

  command[0] += 'A' - 'a' ;

  NL ;  I2 ;  printf( "Incorrect number of arguments provided for the command '%s'!\n" , command ) ;
}

/***************************************************************************************************************************************************/




/* Main Function ***********************************************************************************************************************************/

int main ( int argc , char * argv[] )
{
  char input [ MAX_INPUT_LENGTH ] ;

  if ( argc < 4 )  { printUsage( argv[0] ) ;  return 0 ; }

  configureCengBook( /* maxNumberOfUsers          */ atoi( argv[1] ) ,
                     /* maxUserNameLength         */ atoi( argv[2] ) ,
                     /* maxNumberOfFriendsPerUser */ atoi( argv[3] ) ) ;

  bookPtr = allocateBook() ;

  if ( bookPtr == NULL )  { NL ;  printf( "Error: Cannot allocate memory to store CengBook! Exiting!\n\n" ) ;  exit( 0 ) ; }

  printBanner() ;
  printMenu  () ;

  while ( TRUE )
  {
    NL                        ;  /* New line     */
    printf( "[CENGBOOK] > " ) ;  /* Print prompt */

    if ( fgets( input , MAX_INPUT_LENGTH , stdin ) == NULL )  /* Read input line, 'fgets' is safer than 'gets'. */
    {
      /* In the following two lines, the "if" statements surrounding the "freopen" function calls are used to eliminate warnings. */

      if   ( strcmp( operatingSystem , "Windows" ) == 0 )  { if ( freopen( "CON"      , "r" , stdin ) == NULL ) ; }
      else /* Assumption:               Linux          */  { if ( freopen( "/dev/tty" , "r" , stdin ) == NULL ) ; }

      continue ;
    }

    processInput( input ) ;  /* Tokenize and process the input command */
  }

  return 0 ;
}

/***************************************************************************************************************************************************/
