/* Translated by Nelson f2c (version 20170901).
   You must link the resulting object file with the libraries:
    -lnlsf2c -lm   (in that order)
*/

#include "nelson_f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b3 = -1.;

EXPORTSYMBOL /* Subroutine */ int nf01ba_(iflag, nsmp, n, ipar, lipar, z__, ldz, y, ldy, x, nfevl,
    e, j, ldj, jte, dwork, ldwork, info) integer *iflag,
    *nsmp, *n, *ipar, *lipar;
doublereal* z__;
integer* ldz;
doublereal* y;
integer* ldy;
doublereal* x;
integer* nfevl;
doublereal *e, *j;
integer* ldj;
doublereal *jte, *dwork;
integer *ldwork, *info;
{
    /* System generated locals */
    integer j_dim1, j_offset, y_dim1, y_offset, z_dim1, z_offset, i__1;
    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();
    /* Local variables */
    extern doublereal dnrm2_();
    extern /* Subroutine */ int nf01ay_(), nf01by_(), daxpy_();
    static doublereal err;
    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 6, 0, "(' Norm of current error = ', D15.6)", 0 };
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
    /*     This is the FCN routine for optimizing the parameters of the */
    /*     nonlinear part of a Wiener system (initialization phase), using */
    /*     SLICOT Library routine MD03AD. See the argument FCN in the */
    /*     routine MD03AD for the description of parameters. Note that */
    /*     NF01BA is called for each output of the Wiener system. */
    /*     ****************************************************************** */
    /*     .. Parameters .. */
    /*     .. CJTE is initialized to activate the calculation of J'*e .. */
    /*     .. NOUT is the unit number for printing intermediate results .. */
    /*     .. Scalar Arguments .. */
    /*     .. Array Arguments .. */
    /*     .. Local Scalars .. */
    /*     .. External Functions .. */
    /*     .. External Subroutines .. */
    /*     .. Executable Statements .. */
    /* Parameter adjustments */
    --ipar;
    z_dim1 = *ldz;
    z_offset = z_dim1 + 1;
    z__ -= z_offset;
    y_dim1 = *ldy;
    y_offset = y_dim1 + 1;
    y -= y_offset;
    --x;
    --e;
    j_dim1 = *ldj;
    j_offset = j_dim1 + 1;
    j -= j_offset;
    --jte;
    --dwork;
    /* Function Body */
    *info = 0;
    if (*iflag == 1) {
        /*        Call NF01AY to compute the output y of the Wiener system (in E) */
        /*        and then the error functions (also in E). The array Z must */
        /*        contain the output of the linear part of the Wiener system, and */
        /*        Y must contain the original output Y of the Wiener system. */
        /*        IPAR(2) must contain the number of outputs. */
        /*        Workspace: need:    2*NN, NN = IPAR(3) (number of neurons); */
        /*                   prefer:  larger. */
        i__1 = *lipar - 2;
        nf01ay_(nsmp, &ipar[2], &c__1, &ipar[3], &i__1, &x[1], n, &z__[z_offset], ldz, &e[1], nsmp,
            &dwork[1], ldwork, info);
        daxpy_(nsmp, &c_b3, &y[y_offset], &c__1, &e[1], &c__1);
        dwork[1] = (doublereal)(ipar[3] << 1);
    } else if (*iflag == 2) {
        /*        Call NF01BY to compute the Jacobian in a compressed form. */
        /*        IPAR(2), IPAR(3) must have the same content as for IFLAG = 1. */
        /*        Workspace: need:    0. */
        i__1 = *lipar - 2;
        nf01by_("C", nsmp, &ipar[2], &c__1, &ipar[3], &i__1, &x[1], n, &z__[z_offset], ldz, &e[1],
            &j[j_offset], ldj, &jte[1], &dwork[1], ldwork, info, 1L);
        *nfevl = 0;
        dwork[1] = 0.;
    } else if (*iflag == 3) {
        /*        Set the parameter LDJ, the length of the array J, and the sizes */
        /*        of the workspace for FCN (IFLAG = 1 or 2), and JPJ. */
        *ldj = *nsmp;
        ipar[1] = *nsmp * *n;
        ipar[2] = ipar[3] << 1;
        ipar[3] = 0;
        ipar[4] = *nsmp;
    } else if (*iflag == 0) {
        /*        Special call for printing intermediate results. */
        err = dnrm2_(nsmp, &e[1], &c__1);
        s_wsfe(&io___2);
        do_fio(&c__1, (char*)&err, (ftnlen)sizeof(doublereal));
        e_wsfe();
    }
    return 0;
    /* *** Last line of NF01BA *** */
} /* nf01ba_ */
