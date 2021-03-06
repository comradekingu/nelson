/* Translated by Nelson f2c (version 20170901).
   You must link the resulting object file with the libraries:
    -lnlsf2c -lm   (in that order)
*/

#include "nelson_f2c.h"

/* Table of constant values */

static doublereal c_b7 = 0.;
static integer c__0 = 0;
static integer c__1 = 1;
static doublereal c_b14 = 1.;

EXPORTSYMBOL /* Subroutine */ int nf01bv_(stor, uplo, n, ipar, lipar, dpar, ldpar, j, ldj, jtj,
    ldjtj, dwork, ldwork, info, stor_len, uplo_len) char *stor,
    *uplo;
integer *n, *ipar, *lipar;
doublereal* dpar;
integer* ldpar;
doublereal* j;
integer* ldj;
doublereal* jtj;
integer* ldjtj;
doublereal* dwork;
integer *ldwork, *info;
ftnlen stor_len;
ftnlen uplo_len;
{
    /* System generated locals */
    integer j_dim1, j_offset, i__1;
    /* Local variables */
    static logical full;
    static doublereal c__;
    static integer i__, m;
    extern logical lsame_();
    extern /* Subroutine */ int dgemv_(), dcopy_();
    static logical upper;
    extern /* Subroutine */ int dsyrk_();
    static integer ii;
    extern /* Subroutine */ int dlaset_(), xerbla_();
    static doublereal dum[1];
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
    /*     To compute the matrix J'*J + c*I, for the Jacobian J as received */
    /*     from SLICOT Library routine NF01BY, for one output variable. */
    /*     NOTE: this routine must have the same arguments as SLICOT Library */
    /*     routine NF01BU. */
    /*     ARGUMENTS */
    /*     Mode Parameters */
    /*     STOR    CHARACTER*1 */
    /*             Specifies the storage scheme for the symmetric */
    /*             matrix J'*J + c*I, as follows: */
    /*             = 'F' :  full storage is used; */
    /*             = 'P' :  packed storage is used. */
    /*     UPLO    CHARACTER*1 */
    /*             Specifies which part of the matrix J'*J + c*I is stored, */
    /*             as follows: */
    /*             = 'U' :  the upper triagular part is stored; */
    /*             = 'L' :  the lower triagular part is stored. */
    /*     Input/Output Parameters */
    /*     N       (input) INTEGER */
    /*             The number of columns of the Jacobian matrix J.  N >= 0. */
    /*     IPAR    (input) INTEGER array, dimension (LIPAR) */
    /*             The integer parameters describing the structure of the */
    /*             matrix J, as follows: */
    /*             IPAR(1) must contain the number of rows M of the Jacobian */
    /*                     matrix J.  M >= 0. */
    /*             IPAR is provided for compatibility with SLICOT Library */
    /*             routine MD03AD. */
    /*     LIPAR   (input) INTEGER */
    /*             The length of the array IPAR.  LIPAR >= 1. */
    /*     DPAR    (input) DOUBLE PRECISION array, dimension (LDPAR) */
    /*             The real parameters needed for solving the problem. */
    /*             The entry DPAR(1) must contain the real scalar c. */
    /*     LDPAR   (input) INTEGER */
    /*             The length of the array DPAR.  LDPAR >= 1. */
    /*     J       (input) DOUBLE PRECISION array, dimension (LDJ,N) */
    /*             The leading M-by-N part of this array must contain the */
    /*             Jacobian matrix J. */
    /*     LDJ     INTEGER */
    /*             The leading dimension of the array J.  LDJ >= MAX(1,M). */
    /*     JTJ     (output) DOUBLE PRECISION array, */
    /*                      dimension (LDJTJ,N),    if STOR = 'F', */
    /*                      dimension (N*(N+1)/2),  if STOR = 'P'. */
    /*             The leading N-by-N (if STOR = 'F'), or N*(N+1)/2 (if */
    /*             STOR = 'P') part of this array contains the upper or */
    /*             lower triangle of the matrix J'*J + c*I, depending on */
    /*             UPLO = 'U', or UPLO = 'L', respectively, stored either as */
    /*             a two-dimensional, or one-dimensional array, depending */
    /*             on STOR. */
    /*     LDJTJ   INTEGER */
    /*             The leading dimension of the array JTJ. */
    /*             LDJTJ >= MAX(1,N), if STOR = 'F'. */
    /*             LDJTJ >= 1,        if STOR = 'P'. */
    /*     Workspace */
    /*     DWORK   DOUBLE PRECISION array, dimension (LDWORK) */
    /*             Currently, this array is not used. */
    /*     LDWORK  INTEGER */
    /*             The length of the array DWORK.  LDWORK >= 0. */
    /*     Error Indicator */
    /*     INFO    INTEGER */
    /*             = 0:  successful exit; */
    /*             < 0:  if INFO = -i, the i-th argument had an illegal */
    /*                   value. */
    /*     METHOD */
    /*     The matrix product is computed columnn-wise, exploiting the */
    /*     symmetry. BLAS 3 routine DSYRK is used if STOR = 'F', and BLAS 2 */
    /*     routine DGEMV is used if STOR = 'P'. */
    /*     CONTRIBUTORS */
    /*     V. Sima, Research Institute for Informatics, Bucharest, Apr. 2001. */
    /*     REVISIONS */
    /*     V. Sima, March 2002. */
    /*     KEYWORDS */
    /*     Elementary matrix operations, matrix algebra, matrix operations, */
    /*     Wiener system. */
    /*     ****************************************************************** */
    /*     .. Parameters .. */
    /*     .. Scalar Arguments .. */
    /*     .. Array Arguments .. */
    /*     .. Local Scalars .. */
    /*     .. Local Arrays .. */
    /*     .. External Functions .. */
    /*     .. External Subroutines .. */
    /*     .. Intrinsic Functions .. */
    /*     .. */
    /*     .. Executable Statements .. */
    /* Parameter adjustments */
    --ipar;
    --dpar;
    j_dim1 = *ldj;
    j_offset = j_dim1 + 1;
    j -= j_offset;
    --jtj;
    --dwork;
    /* Function Body */
    *info = 0;
    full = lsame_(stor, "F", 1L, 1L);
    upper = lsame_(uplo, "U", 1L, 1L);
    if (!(full || lsame_(stor, "P", 1L, 1L))) {
        *info = -1;
    } else if (!(upper || lsame_(uplo, "L", 1L, 1L))) {
        *info = -2;
    } else if (*n < 0) {
        *info = -3;
    } else if (*lipar < 1) {
        *info = -5;
    } else if (*ldpar < 1) {
        *info = -7;
    } else if (*ldjtj < 1 || full && *ldjtj < *n) {
        *info = -11;
    } else if (*ldwork < 0) {
        *info = -13;
    } else {
        m = ipar[1];
        if (m < 0) {
            *info = -4;
        } else if (*ldj < max(1, m)) {
            *info = -9;
        }
    }
    /*     Return if there are illegal arguments. */
    if (*info != 0) {
        i__1 = -(*info);
        xerbla_("NF01BV", &i__1, 6L);
        return 0;
    }
    /*     Quick return if possible. */
    c__ = dpar[1];
    if (*n == 0) {
        return 0;
    } else if (m == 0) {
        if (full) {
            dlaset_(uplo, n, n, &c_b7, &c__, &jtj[1], ldjtj, 1L);
        } else {
            dum[0] = 0.;
            i__1 = *n * (*n + 1) / 2;
            dcopy_(&i__1, dum, &c__0, &jtj[1], &c__1);
            if (upper) {
                ii = 0;
                i__1 = *n;
                for (i__ = 1; i__ <= i__1; ++i__) {
                    ii += i__;
                    jtj[ii] = c__;
                    /* L10: */
                }
            } else {
                ii = 1;
                for (i__ = *n; i__ >= 1; --i__) {
                    jtj[ii] = c__;
                    ii += i__;
                    /* L20: */
                }
            }
        }
        return 0;
    }
    /*     Build a triangle of the matrix J'*J + c*I. */
    if (full) {
        dlaset_(uplo, n, n, &c_b7, &c__, &jtj[1], ldjtj, 1L);
        dsyrk_(uplo, "Transpose", n, &m, &c_b14, &j[j_offset], ldj, &c_b14, &jtj[1], ldjtj, 1L, 9L);
    } else if (upper) {
        ii = 0;
        i__1 = *n;
        for (i__ = 1; i__ <= i__1; ++i__) {
            dgemv_("Transpose", &m, &i__, &c_b14, &j[j_offset], ldj, &j[i__ * j_dim1 + 1], &c__1,
                &c_b7, &jtj[ii + 1], &c__1, 9L);
            ii += i__;
            jtj[ii] += c__;
            /* L30: */
        }
    } else {
        ii = 1;
        for (i__ = *n; i__ >= 1; --i__) {
            dgemv_("Transpose", &m, &i__, &c_b14, &j[(*n - i__ + 1) * j_dim1 + 1], ldj,
                &j[(*n - i__ + 1) * j_dim1 + 1], &c__1, &c_b7, &jtj[ii], &c__1, 9L);
            jtj[ii] += c__;
            ii += i__;
            /* L40: */
        }
    }
    return 0;
    /* *** Last line of NF01BV *** */
} /* nf01bv_ */
