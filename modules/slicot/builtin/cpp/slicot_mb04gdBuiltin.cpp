//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
// Generated by Nelson Interface Generator 1.0.0
//=============================================================================
#include "Error.hpp"
#include "slicot_mb04gdBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
extern int mb04gd_ ( int *M, int *N, double *A, int *LDA, int *JPVT, double *TAU, double *DWORK, int *INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [A_OUT, JPVT_OUT, TAU, INFO] = slicot_mb04gd(A_IN, JPVT_IN)
//=============================================================================
ArrayOfVector Nelson::SlicotGateway::slicot_mb04gdBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs > 4)
    {
        Error(eval, ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (argIn.size() != 2)
    {
        Error(eval, ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    // INPUT VARIABLES
    // IN/OUT VARIABLES
    ArrayOf A = argIn[0];
    Dimensions dimsA = A.getDimensions();
    A.promoteType(NLS_DOUBLE);
    ArrayOf A_output = A;
    A_output.ensureSingleOwner();
    double *A_output_ptr = (double*)A_output.getDataPointer();
    ArrayOf JPVT = argIn[1];
    Dimensions dimsJPVT = JPVT.getDimensions();
    JPVT.promoteType(NLS_INT32);
    ArrayOf JPVT_output = JPVT;
    JPVT_output.ensureSingleOwner();
    int *JPVT_output_ptr = (int*)JPVT_output.getDataPointer();
    // LOCAL VARIABLES
    ArrayOf M = ArrayOf::int32VectorConstructor(1);
    int* M_ptr = (int*)M.getDataPointer();
    M_ptr[0] = (int)A.getDimensions().getRows();
    ArrayOf N = ArrayOf::int32VectorConstructor(1);
    int* N_ptr = (int*)N.getDataPointer();
    N_ptr[0] = (int)A.getDimensions().getColumns();
    ArrayOf LDA = ArrayOf::int32VectorConstructor(1);
    int* LDA_ptr = (int*)LDA.getDataPointer();
    LDA_ptr[0] = std::max(1, (int)A.getDimensions().getRows());
    ArrayOf DWORK = ArrayOf::doubleMatrix2dConstructor(1 , 3 * (int)A.getDimensions().getRows());
    double * DWORK_ptr = (double*)DWORK.getDataPointer();
    // OUTPUT VARIABLES
    ArrayOf TAU_output = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)std::min((int)A.getDimensions().getRows(), (int)A.getDimensions().getColumns()));
    double *TAU_output_ptr = (double*)TAU_output.getDataPointer();
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int *INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // CHECK INPUT VARIABLES DIMENSIONS
    Dimensions dimsA_expected(std::max(1, (int)A.getDimensions().getRows()), std::max(1, (int)A.getDimensions().getColumns()));
    if (!dimsA.equals(dimsA_expected))
    {
        Error(eval, _("Input argument #1: wrong size.") + " " + dimsA_expected.toString() + " " + "expected" + ".");
    }
    Dimensions dimsJPVT_expected(1, std::max(1, (int)A.getDimensions().getRows()));
    if (!dimsJPVT.equals(dimsJPVT_expected))
    {
        Error(eval, _("Input argument #2: wrong size.") + " " + dimsJPVT_expected.toString() + " " + "expected" + ".");
    }
    // CALL EXTERN FUNCTION
    try
    {
        mb04gd_ ( M_ptr, N_ptr, A_output_ptr, LDA_ptr, JPVT_output_ptr, TAU_output_ptr, DWORK_ptr, INFO_output_ptr);
    }
    catch (std::runtime_error &e)
    {
        e.what();
        Error(eval, "mb04gd function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0)
    {
        retval.push_back(A_output);
    }
    if (nLhs > 1)
    {
        retval.push_back(JPVT_output);
    }
    if (nLhs > 2)
    {
        retval.push_back(TAU_output);
    }
    if (nLhs > 3)
    {
        retval.push_back(INFO_output);
    }
    return retval;
}
//=============================================================================