/* Translated by Nelson f2c (version 20170901).
   You must link the resulting object file with the libraries:
	-lnlsf2c -lm   (in that order)
*/

#include "nelson_f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c_n1 = -1;

EXPORTSYMBOL /* Subroutine */ int mb04iz_(n, m, p, l, a, lda, b, ldb, tau, zwork, lzwork, info)
integer *n, *m, *p, *l;
doublecomplex *a;
integer *lda;
doublecomplex *b;
integer *ldb;
doublecomplex *tau, *zwork;
integer *lzwork, *info;
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, i__1, i__2, i__3, i__4;
    doublecomplex z__1;
    /* Builtin functions */
    void d_cnjg();
    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int zlarf_();
    static doublecomplex first;
    static integer nb;
    extern /* Subroutine */ int xerbla_();
    extern integer ilaenv_();
    extern /* Subroutine */ int zlarfg_(), zgeqrf_();
    static logical lquery;
    static integer wrkopt;
    extern /* Subroutine */ int zunmqr_();
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
    /*     To compute a QR factorization of an n-by-m matrix A (A = Q * R), */
    /*     having a p-by-min(p,m) zero triangle in the lower left-hand side */
    /*     corner, as shown below, for n = 8, m = 7, and p = 2: */
    /*            [ x x x x x x x ] */
    /*            [ x x x x x x x ] */
    /*            [ x x x x x x x ] */
    /*            [ x x x x x x x ] */
    /*        A = [ x x x x x x x ], */
    /*            [ x x x x x x x ] */
    /*            [ 0 x x x x x x ] */
    /*            [ 0 0 x x x x x ] */
    /*     and optionally apply the transformations to an n-by-l matrix B */
    /*     (from the left). The problem structure is exploited. This */
    /*     computation is useful, for instance, in combined measurement and */
    /*     time update of one iteration of the time-invariant Kalman filter */
    /*     (square root information filter). */
    /*     ARGUMENTS */
    /*     Input/Output Parameters */
    /*     N       (input) INTEGER */
    /*             The number of rows of the matrix A.  N >= 0. */
    /*     M       (input) INTEGER */
    /*             The number of columns of the matrix A.  M >= 0. */
    /*     P       (input) INTEGER */
    /*             The order of the zero triagle.  P >= 0. */
    /*     L       (input) INTEGER */
    /*             The number of columns of the matrix B.  L >= 0. */
    /*     A       (input/output) COMPLEX*16 array, dimension (LDA,M) */
    /*             On entry, the leading N-by-M part of this array must */
    /*             contain the matrix A. The elements corresponding to the */
    /*             zero P-by-MIN(P,M) lower trapezoidal/triangular part */
    /*             (if P > 0) are not referenced. */
    /*             On exit, the elements on and above the diagonal of this */
    /*             array contain the MIN(N,M)-by-M upper trapezoidal matrix */
    /*             R (R is upper triangular, if N >= M) of the QR */
    /*             factorization, and the relevant elements below the */
    /*             diagonal contain the trailing components (the vectors v, */
    /*             see Method) of the elementary reflectors used in the */
    /*             factorization. */
    /*     LDA     INTEGER */
    /*             The leading dimension of array A.  LDA >= MAX(1,N). */
    /*     B       (input/output) COMPLEX*16 array, dimension (LDB,L) */
    /*             On entry, the leading N-by-L part of this array must */
    /*             contain the matrix B. */
    /*             On exit, the leading N-by-L part of this array contains */
    /*             the updated matrix B. */
    /*             If L = 0, this array is not referenced. */
    /*     LDB     INTEGER */
    /*             The leading dimension of array B. */
    /*             LDB >= MAX(1,N) if L > 0; */
    /*             LDB >= 1        if L = 0. */
    /*     TAU     (output) COMPLEX*16 array, dimension MIN(N,M) */
    /*             The scalar factors of the elementary reflectors used. */
    /*     Workspace */
    /*     ZWORK   COMPLEX*16 array, dimension (LZWORK) */
    /*             On exit, if INFO = 0, ZWORK(1) returns the optimal value */
    /*             of LZWORK. */
    /*     LZWORK  The length of the array ZWORK. */
    /*             LZWORK >= MAX(1,M-1,M-P,L). */
    /*             For optimum performance LZWORK should be larger. */
    /*             If LZWORK = -1, then a workspace query is assumed; */
    /*             the routine only calculates the optimal size of the */
    /*             ZWORK array, returns this value as the first entry of */
    /*             the ZWORK array, and no error message related to LZWORK */
    /*             is issued by XERBLA. */
    /*     Error Indicator */
    /*     INFO    INTEGER */
    /*             = 0:  successful exit; */
    /*             < 0:  if INFO = -i, the i-th argument had an illegal */
    /*                   value. */
    /*     METHOD */
    /*     The routine uses min(N,M) Householder transformations exploiting */
    /*     the zero pattern of the matrix.  A Householder matrix has the form */
    /*                                     ( 1 ), */
    /*        H  = I - tau *u *u',    u  = ( v ) */
    /*         i          i  i  i      i   (  i) */
    /*     where v  is an (N-P+I-2)-vector.  The components of v  are stored */
    /*            i                                             i */
    /*     in the i-th column of A, beginning from the location i+1, and */
    /*     tau  is stored in TAU(i). */
    /*        i */
    /*     NUMERICAL ASPECTS */
    /*     The algorithm is backward stable. */
    /*     CONTRIBUTORS */
    /*     V. Sima, Katholieke Univ. Leuven, Belgium, Feb. 1997. */
    /*     Complex version: V. Sima, Research Institute for Informatics, */
    /*     Bucharest, Nov. 2008. */
    /*     REVISIONS */
    /*     V. Sima, Research Institute for Informatics, Bucharest, Apr. 2009. */
    /*     KEYWORDS */
    /*     Elementary reflector, QR factorization, unitary transformation. */
    /*     ****************************************************************** */
    /*     .. Parameters .. */
    /*     .. Scalar Arguments .. */
    /*     .. Array Arguments .. */
    /*     .. Local Scalars .. */
    /*     .. External Functions .. */
    /*     .. External Subroutines .. */
    /*     .. Intrinsic Functions .. */
    /*     .. Executable Statements .. */
    /*     Test the input scalar arguments. */
    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = a_dim1 + 1;
    a -= a_offset;
    b_dim1 = *ldb;
    b_offset = b_dim1 + 1;
    b -= b_offset;
    --tau;
    --zwork;
    /* Function Body */
    *info = 0;
    lquery = *lzwork == -1;
    if (*n < 0)
    {
        *info = -1;
    }
    else if (*m < 0)
    {
        *info = -2;
    }
    else if (*p < 0)
    {
        *info = -3;
    }
    else if (*l < 0)
    {
        *info = -4;
    }
    else if (*lda < max(1,*n))
    {
        *info = -6;
    }
    else if (*ldb < 1 || *l > 0 && *ldb < *n)
    {
        *info = -8;
    }
    else
    {
        /* Computing MAX */
        i__1 = 1, i__2 = *m - 1, i__1 = max(i__1,i__2), i__2 = *m - *p, i__1 = max(i__1,i__2);
        i__ = max(i__1,*l);
        if (lquery)
        {
            if (*m > *p)
            {
                i__1 = *n - *p;
                i__2 = *m - *p;
                nb = ilaenv_(&c__1, "ZGEQRF", " ", &i__1, &i__2, &c_n1, &c_n1, 6L, 1L);
                /* Computing MAX */
                i__1 = i__, i__2 = (*m - *p) * nb;
                wrkopt = max(i__1,i__2);
                if (*l > 0)
                {
                    /* Computing MIN */
                    i__3 = *n - *p;
                    i__4 = min(*n,*m) - *p;
                    i__1 = 64, i__2 = ilaenv_(&c__1, "ZUNMQR", "LC", &i__3, l, &i__4, &c_n1, 6L, 2L);
                    nb = min(i__1,i__2);
                    /* Computing MAX */
                    i__1 = wrkopt, i__2 = max(1,*l) * nb;
                    wrkopt = max(i__1,i__2);
                }
            }
        }
        else if (*lzwork < i__)
        {
            *info = -11;
        }
    }
    if (*info != 0)
    {
        /*        Error return. */
        i__1 = -(*info);
        xerbla_("MB04IZ", &i__1, 6L);
        return 0;
    }
    else if (lquery)
    {
        zwork[1].r = (doublereal) wrkopt, zwork[1].i = 0.;
        return 0;
    }
    /*     Quick return if possible. */
    if (min(*m,*n) == 0)
    {
        zwork[1].r = 1., zwork[1].i = 0.;
        return 0;
    }
    else if (*n <= *p + 1)
    {
        i__1 = min(*n,*m);
        for (i__ = 1; i__ <= i__1; ++i__)
        {
            i__2 = i__;
            tau[i__2].r = 0., tau[i__2].i = 0.;
            /* L5: */
        }
        zwork[1].r = 1., zwork[1].i = 0.;
        return 0;
    }
    /*     Annihilate the subdiagonal elements of A and apply the */
    /*     transformations to B, if L > 0. */
    /*     Workspace: need MAX(M-1,L). */
    /*     (Note: Comments in the code beginning "Workspace:" describe the */
    /*     minimal amount of complex workspace needed at that point in the */
    /*     code, as well as the preferred amount for good performance. */
    /*     NB refers to the optimal block size for the immediately */
    /*     following subroutine, as returned by ILAENV.) */
    i__1 = min(*p,*m);
    for (i__ = 1; i__ <= i__1; ++i__)
    {
        /*        Exploit the structure of the I-th column of A. */
        i__2 = *n - *p;
        zlarfg_(&i__2, &a[i__ + i__ * a_dim1], &a[i__ + 1 + i__ * a_dim1], &c__1, &tau[i__]);
        i__2 = i__;
        if (tau[i__2].r != 0. || tau[i__2].i != 0.)
        {
            i__2 = i__ + i__ * a_dim1;
            first.r = a[i__2].r, first.i = a[i__2].i;
            i__2 = i__ + i__ * a_dim1;
            a[i__2].r = 1., a[i__2].i = 0.;
            if (i__ < *m)
            {
                i__2 = *n - *p;
                i__3 = *m - i__;
                d_cnjg(&z__1, &tau[i__]);
                zlarf_("Left", &i__2, &i__3, &a[i__ + i__ * a_dim1], &c__1, &z__1, &a[i__ + (i__ + 1) * a_dim1], lda, &zwork[1], 4L);
            }
            if (*l > 0)
            {
                i__2 = *n - *p;
                d_cnjg(&z__1, &tau[i__]);
                zlarf_("Left", &i__2, l, &a[i__ + i__ * a_dim1], &c__1, &z__1, &b[i__ + b_dim1], ldb, &zwork[1], 4L);
            }
            i__2 = i__ + i__ * a_dim1;
            a[i__2].r = first.r, a[i__2].i = first.i;
        }
        /* L10: */
    }
    /* Computing MAX */
    i__1 = 1, i__2 = *m - 1, i__1 = max(i__1,i__2);
    wrkopt = max(i__1,*l);
    /*     Fast QR factorization of the remaining right submatrix, if any. */
    /*     Workspace: need M-P;  prefer (M-P)*NB. */
    if (*m > *p)
    {
        i__1 = *n - *p;
        i__2 = *m - *p;
        zgeqrf_(&i__1, &i__2, &a[*p + 1 + (*p + 1) * a_dim1], lda, &tau[*p + 1], &zwork[1], lzwork, info);
        /* Computing MAX */
        i__1 = wrkopt, i__2 = (integer) zwork[1].r;
        wrkopt = max(i__1,i__2);
        if (*l > 0)
        {
            /*           Apply the transformations to B. */
            /*           Workspace: need L;  prefer L*NB. */
            i__1 = *n - *p;
            i__2 = min(*n,*m) - *p;
            zunmqr_("Left", "Conjugate", &i__1, l, &i__2, &a[*p + 1 + (*p + 1) * a_dim1], lda, &tau[*p + 1], &b[*p + 1 + b_dim1], ldb, &zwork[1], lzwork, info, 4L, 9L);
            /* Computing MAX */
            i__1 = wrkopt, i__2 = (integer) zwork[1].r;
            wrkopt = max(i__1,i__2);
        }
    }
    zwork[1].r = (doublereal) wrkopt, zwork[1].i = 0.;
    return 0;
    /* *** Last line of MB04IZ *** */
} /* mb04iz_ */

