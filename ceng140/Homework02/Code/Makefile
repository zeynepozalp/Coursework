#****************************************************************************************************************************************************
#
# Copyright (C) 2018 Selim Temizer.
#
# This program is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
# as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.
#
#****************************************************************************************************************************************************




#- Variables ------------------------------------------------------------------

CC           = gcc
CFLAGS       = -Wall -ansi -pedantic-errors -O6 -g
LIBS         = -lm
INCLUDE_DIRS = -I.
LIBRARY_DIRS = -L.

#- Source Files and Desired Executables ---------------------------------------

SOURCE_FILES = Queue.c Utilities.c CengBook.c
EXE          = cb

#- Object Files ---------------------------------------------------------------

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

#- Rules ----------------------------------------------------------------------

.PHONY   : all run clean cleanall

all      : $(EXE)

.c.o     :
	   $(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $<

$(EXE)   : $(OBJECT_FILES)
	   $(CC) $(CFLAGS) $(LIBRARY_DIRS) -o $(EXE) $(OBJECT_FILES) $(LIBS)

run      :
	   ./$(EXE) 100 40 50

clean    :
	   rm -f $(OBJECT_FILES)

cleanall :
	   rm -f $(OBJECT_FILES) $(EXE) CengBook.dot CengBook.gif

#- Dependencies ---------------------------------------------------------------

Queue.o     : Queue.c     Queue.h
Utilities.o : Utilities.c Utilities.h Queue.h
CengBook.o  : CengBook.c  Utilities.h Queue.h

#******************************************************************************
