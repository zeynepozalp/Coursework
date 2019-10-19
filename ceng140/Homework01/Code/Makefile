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

CC            = gcc
CFLAGS        = -Wall -ansi -pedantic-errors -O6 -g
LIBS          = -lm
INCLUDE_DIRS  = -I.
LIBRARY_DIRS  = -L.

#- Source Files and Desired Executables ---------------------------------------

SOURCE_FILES1 = Utilities.c TicTacToe.c
EXE1          = ttt

SOURCE_FILES2 = Utilities.c DnDW.c
EXE2          = dnd

#- Object Files ---------------------------------------------------------------

OBJECT_FILES1 = $(SOURCE_FILES1:.c=.o)
OBJECT_FILES2 = $(SOURCE_FILES2:.c=.o)

#- Rules ----------------------------------------------------------------------

.PHONY  : all clean

all     : $(EXE1) $(EXE2)

.c.o    :
	  $(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $<

$(EXE1) : $(OBJECT_FILES1)
	  $(CC) $(CFLAGS) $(LIBRARY_DIRS) -o $(EXE1) $(OBJECT_FILES1) $(LIBS)

$(EXE2) : $(OBJECT_FILES2)
	  $(CC) $(CFLAGS) $(LIBRARY_DIRS) -o $(EXE2) $(OBJECT_FILES2) $(LIBS)

clean   :
	  rm -f $(OBJECT_FILES1) $(OBJECT_FILES2) $(EXE1) $(EXE2)

#- Dependencies ---------------------------------------------------------------

DnDW.o      : DnDW.c      Utilities.h
TicTacToe.o : TicTacToe.c Utilities.h
Utilities.o : Utilities.c Utilities.h

#******************************************************************************
