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
| - This file contains the implementation of the queue data structure.
| - The implementations mostly follow the text on Page 30 of "Algorithms in C" book (1990) by Robert Sedgewick.
| - In order to use the queue data structure, include the "Queue.h" header file in your application, and then compile and link this file with the
|   rest of your application files.
|
****************************************************************************************************************************************************/




/* Includes ****************************************************************************************************************************************/

#include "Queue.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/***************************************************************************************************************************************************/




/* Queue Data Structure Functions ******************************************************************************************************************/

QueuePtr qAllocate ( unsigned maxNumberOfElements ) /* BU FONKSIYON QUE VE ELEMENTS ICIN YER ALIYOR. */
{
  QueuePtr queuePtr = (QueuePtr) malloc( sizeof( Queue ) ) ;

  if ( queuePtr == NULL )  { return NULL ; }

  queuePtr->elements = (QueueElementArray) malloc( (maxNumberOfElements + 1) * sizeof( QueueElement ) ) ; /*NEDEN +1 FAZLA YER ALDI?*/

  if ( queuePtr->elements == NULL )  { free( queuePtr ) ;  return NULL ; }

  queuePtr->size = maxNumberOfElements ;

  qReset( queuePtr ) ; /*?????*/

  return queuePtr ;
}

/*=================================================================================================================================================*/

void qDeallocate ( QueuePtr queuePtr ) /* QUE ICIN ALINAN YERI FREE ET. */
{
  if ( queuePtr == NULL )  { return ; }

  if ( queuePtr->elements != NULL )  { free( queuePtr->elements ) ; }

  free( queuePtr ) ;
}

/*=================================================================================================================================================*/

void qReset ( QueuePtr queuePtr )
{
  queuePtr->head = 0 ;
  queuePtr->tail = 0 ;
}

/*=================================================================================================================================================*/

void qPut ( QueuePtr queuePtr , QueueElement element ) /*QUENUN SONUNA EKLE. */
{
  queuePtr->elements[ queuePtr->tail++ ] = element ;

  if ( queuePtr->tail > queuePtr->size )  { queuePtr->tail = 0 ; } /*????*/
}

/*=================================================================================================================================================*/

QueueElement qGet ( QueuePtr queuePtr )
{
  QueueElement element = queuePtr->elements[ queuePtr->head++ ] ;

  if ( queuePtr->head > queuePtr->size )  { queuePtr->head = 0 ; } /*????? */

  return element ;
}

/*=================================================================================================================================================*/

int qIsEmpty ( QueuePtr queuePtr )
{
  return ( queuePtr->head == queuePtr->tail ) ;
}

/***************************************************************************************************************************************************/
