/*
Copyright 1987-2012 Robert B. K. Dewar and Mark Emmer.

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
        zysdc - check system expiration date

        zysdc prints any header messages and may check
        the date to see if execution is allowed to proceed.

        Parameters:
            Nothing
        Returns
            Nothing
            No return if execution not permitted

*/

#include "port.h"
#include "os.h"
#include "globals.ext"

#include <stdio.h>

extern int nlines;
extern int compsp;
extern int osisp;
extern int LOWSPMIN;

atlin()
{
#ifdef TRACE
	fprintf(stderr, "at line %d\n",nlines);
	regdump();
#endif
}

rp(char * name,uword reg)
/* print register name and vaue */
{
#ifdef TRACE
	fprintf(stderr," %s %u ",name, reg);
#endif
}

regdump()
{
#ifdef TRACE
	rp("WA", WA(int));
	rp("WB", WB(int));
	rp("WC", WC(int));
	rp("XL", XL(int));
	rp("XR", XR(int));
	rp("XS", XS(int));
	rp("CP", CP(int));
	rp("IA", IA(int));
	fprintf(stderr,"\n");
	fprintf(stderr,"compsp %u",compsp);
	fprintf(stderr,"  osisp %u", osisp);
	fprintf(stderr," LOWSPMIN %u\n", LOWSPMIN);
#endif
}
void Trace(char * type, char * text) 
{
#ifdef TRACE
	fprintf(stderr,"%s %s\n", type, text);
#endif
}
void At(char * text)
{
#ifdef TRACE
	Trace("At", text);
#endif
}
void Enter(char * text) {
#ifdef TRACE
	Trace("Enter", text);
#endif
}
void Exit(char * text) 
{
#ifdef TRACE
	Trace("Exit", text);
#endif
}

#ifdef REGDUMP
extern int nlines;
extern	struct regs reg_block;
reGdump()
{
#ifdef TRACE
	struct regs {
	unsigned int	reg_wa,
	unsigned int 	reg_wb,
	unsigned int 	reg_wc,
	unsigned int 	reg_xr,
	unsigned int 	reg_xl,
	unsigned int 	reg_cp,
	double 		reg_ra,
	unsigned int	reg_pc,
	unsigned int	reg_pp,
	unsigned int	reg_xs
	};
	
    fprintf(stderr, "mininal registers line %d\n",nlines);
  	struct regs *rp;  

	rp = &reg_block
	fprintf(stderr,"wa \ud\n",	rp->reg_wa);
#endif
}
#endif
