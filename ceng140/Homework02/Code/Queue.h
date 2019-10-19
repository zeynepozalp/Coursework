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
| This file contains the necessary declarations for the queue data structure, which is implemented in "Queue.c" file.
|
****************************************************************************************************************************************************/




/* Multiple Inclusion Guard ************************************************************************************************************************/

#ifndef __QUEUE_DATA_STRUCTURE__
#define __QUEUE_DATA_STRUCTURE__

/***************************************************************************************************************************************************/




/* Macro Definitions *******************************************************************************************************************************/

#ifndef QUEUE_ELEMENT_TYPE

  /* C language does not support templates and/or generic (parametric) data types, but it is possible to emulate generic data types using macros.  */
  /* Below, you may choose the type of the elements to be stored in your queues.                                                                   */

  #define QUEUE_ELEMENT_TYPE  void *

#endif

/***************************************************************************************************************************************************/




/* Type Definitions ********************************************************************************************************************************/

typedef QUEUE_ELEMENT_TYPE   QueueElement      ;
typedef QueueElement       * QueueElementArray ;
typedef struct queue         Queue             ;  /* This is a forward type definition. The "struct queue" data type will be defined below. */
typedef Queue              * QueuePtr          ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

struct queue
{
  unsigned          size     ;
  unsigned          head     ;
  unsigned          tail     ;
  QueueElementArray elements ;
} ;

/***************************************************************************************************************************************************/




/* Declarations (Prototypes) of Queue Data Structure Functions *************************************************************************************/

QueuePtr     qAllocate   ( unsigned maxNumberOfElements             ) ;
void         qDeallocate ( QueuePtr queuePtr                        ) ;
void         qReset      ( QueuePtr queuePtr                        ) ;
void         qPut        ( QueuePtr queuePtr , QueueElement element ) ;
QueueElement qGet        ( QueuePtr queuePtr                        ) ;
int          qIsEmpty    ( QueuePtr queuePtr                        ) ;

/***************************************************************************************************************************************************/




/* End of Multiple Inclusion Guard *****************************************************************************************************************/

#endif

/***************************************************************************************************************************************************/
