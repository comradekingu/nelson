/* Translated by Nelson f2c (version 20170901).
   You must link the resulting object file with the libraries:
    -lnlsf2c -lm   (in that order)
*/

#include "nelson_f2c.h"

integer mc01sx_(lb, ub, e, mant) integer *lb, *ub, *e;
doublereal* mant;
{
    /* System generated locals */
    integer ret_val, i__1, i__2, i__3;
    /* Local variables */
    static integer mine, maxe, j;
    /*     SLICOT RELEASE 5.0. */
    /*     Copyright (c) 2002-2010 NICONET e.V. */
    /*     This program is free software: you can redistribute it and/or */
    /*     modify it under the terms of the GNU General Public License as */
    /*     published by the Free Software Foundation, either version 2 of */
    /*     the License, or (at your option) any later version. */
    /*     This program is distributed in the hope that it will be useful, */
    /*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
    /*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
    /*     GNU General Public License for more details. */
    /*     You should have received a copy of the GNU General Public License */
    /*     along with this program.  If not, see */
    /*     <http://www.gnu.org/licenses/>. */
    /*     PURPOSE */
    /*     To compute the variation V of the exponents of a series of */
    /*     non-zero floating-point numbers: a(j) = MANT(j) * beta**(E(j)), */
    /*     where beta is the base of the machine representation of */
    /*     floating-point numbers, i.e., */
    /*     V = max(E(j)) - min(E(j)), j = LB,...,UB and MANT(j) non-zero. */
    /*     CONTRIBUTOR */
    /*     Release 3.0: V. Sima, Katholieke Univ. Leuven, Belgium, Mar. 1997. */
    /*     Supersedes Release 2.0 routine MC01GX by A.J. Geurts. */
    /*     REVISIONS */
    /*     - */
    /*     ****************************************************************** */
    /*     .. Parameters .. */
    /*     .. Scalar Arguments .. */
    /*     .. Array Arguments .. */
    /*     .. Local Scalars .. */
    /*     .. Intrinsic Functions .. */
    /*     .. Executable Statements .. */
    /* Parameter adjustments */
    --mant;
    --e;
    /* Function Body */
    maxe = e[*lb];
    mine = maxe;
    i__1 = *ub;
    for (j = *lb + 1; j <= i__1; ++j) {
        if (mant[j] != 0.) {
            /* Computing MAX */
            i__2 = maxe, i__3 = e[j];
            maxe = max(i__2, i__3);
            /* Computing MIN */
            i__2 = mine, i__3 = e[j];
            mine = min(i__2, i__3);
        }
        /* L20: */
    }
    ret_val = maxe - mine;
    return ret_val;
    /* *** Last line of MC01SX *** */
} /* mc01sx_ */
