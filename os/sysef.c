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
        zysef - eject file

        zysef writes an eject (form-feed) to a file.

        Parameters:
            WA - FCBLK pointer or 0
            XR - SCBLK pointer (EJECT argument)
        Returns:
            Nothing
        Exits:
            1 - file does not exist
            2 - inappropriate file
            3 - i/o error
*/

#include "port.h"
#include "os.h"

/*
        ffscblk is one of the few SCBLKs that can be directly allocated
        using a C struct!
*/
static struct scblk ffscblk = {
    0,				/*  type word - ignore          */
    1,				/*  string length               */
    '\f'			/*  string is a form-feed       */
};

zysef()
{
    REGISTER struct fcblk *fcb = WA(struct fcblk *);
    REGISTER struct ioblk *iob = MK_MP(fcb->iob, struct ioblk *);

    Enter("zysef");
    /* ensure the file is open */
    if (!(iob->flg1 & IO_OPN)) {
        Exit("zysef");
	return EXI_1;
    }

    /* write the data, fail if unsuccessful */
    if (oswrite(fcb->mode, fcb->rsz, ffscblk.len, iob, &ffscblk) != 0) {
        Exit("zysef");
	return EXI_2;
    }

    Exit("zysef");
    return EXI_0;
}
