/* Translated by Nelson f2c (version 20170901).
   You must link the resulting object file with the libraries:
    -lnlsf2c -lm   (in that order)
*/

#include "nelson_f2c.h"

EXPORTSYMBOL /* Subroutine */ int dg01ny_(indi, n, xr, xi, indi_len) char* indi;
integer* n;
doublereal *xr, *xi;
ftnlen indi_len;
{
    /* System generated locals */
    integer i__1;
    /* Builtin functions */
    double atan(), sin();
    /* Local variables */
    static integer i__, j;
    static logical lindi;
    static doublereal helpi;
    extern logical lsame_();
    static doublereal helpr, whelp;
    static integer n2;
    static doublereal wstpi, wstpr, ai, bi, ar, br, wi, wr, pi2;
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
    /*     For efficiency, no tests of the input scalar parameters are */
    /*     performed. */
    /*     .. Parameters .. */
    /*     .. Scalar Arguments .. */
    /*     .. Array Arguments .. */
    /*     .. Local Scalars .. */
    /*     .. External Functions .. */
    /*     .. Intrinsic Functions .. */
    /*     .. Executable Statements .. */
    /* Parameter adjustments */
    --xi;
    --xr;
    /* Function Body */
    lindi = lsame_(indi, "D", 1L, 1L);
    /*     Initialisation. */
    pi2 = atan(1.) * 8.;
    if (lindi) {
        pi2 = -pi2;
    }
    whelp = pi2 / (doublereal)(*n << 1);
    wstpi = sin(whelp);
    whelp = sin(whelp * .5);
    wstpr = whelp * -2. * whelp;
    wi = 0.;
    if (lindi) {
        wr = 1.;
        xr[*n + 1] = xr[1];
        xi[*n + 1] = xi[1];
    } else {
        wr = -1.;
    }
    /*     Recursion. */
    n2 = *n / 2 + 1;
    i__1 = n2;
    for (i__ = 1; i__ <= i__1; ++i__) {
        j = *n + 2 - i__;
        ar = xr[i__] + xr[j];
        ai = xi[i__] - xi[j];
        br = xi[i__] + xi[j];
        bi = xr[j] - xr[i__];
        if (lindi) {
            ar *= .5;
            ai *= .5;
            br *= .5;
            bi *= .5;
        }
        helpr = wr * br - wi * bi;
        helpi = wr * bi + wi * br;
        xr[i__] = ar + helpr;
        xi[i__] = ai + helpi;
        xr[j] = ar - helpr;
        xi[j] = helpi - ai;
        whelp = wr;
        wr = wr + wr * wstpr - wi * wstpi;
        wi = wi + wi * wstpr + whelp * wstpi;
        /* L10: */
    }
    return 0;
    /* *** Last line of DG01NY *** */
} /* dg01ny_ */
