/*
Copyright 1987-2012 Robert B. K. Dewar and Mark Emmer.
Copyright 2012 David Shields

This file is part of Macro SPITBOL.

    Macro SPITBOL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Macro SPITBOL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Macro SPITBOL.  If not, see <http://www.gnu.org/licenses/>.
*/

/*

        zysax - after execution cleanup

        Here we just indicate that further output should go to the
        compiler output file, as opposed to stdout from executing program.

        Parameters:
            None
        Returns:
            Nothing
        Exits:
            None
*/

#include "port.h"
#include "os.h"

extern char *outptr;

zysax()
{
    /*  swcoup does real work  */
    Enter("zysax");
    swcoup(outptr);
    Exit("zysax");
    return EXI_0;
}
