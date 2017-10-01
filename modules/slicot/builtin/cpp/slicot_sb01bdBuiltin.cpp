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
#include "slicot_sb01bdBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
extern int sb01bd_ ( const char *DICO, int *N, int *M, int *NP, double *ALPHA, double *A, int *LDA, double *B, int *LDB, double *WR, double *WI, int *NFP, int *NAP, int *NUP, double *F, int *LDF, double *Z, int *LDZ, double *TOL, double *DWORK, int *LDWORK, int *IWARN, int *INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [A_OUT, B_OUT, WR_OUT, WI_OUT, NFP, NAP, NUP, F, Z, IWARN, INFO] = slicot_sb01bd(DICO, N, M, NP, ALPHA, A_IN, B_IN, WR_IN, WI_IN, TOL)
//=============================================================================
ArrayOfVector Nelson::SlicotGateway::slicot_sb01bdBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs > 11)
    {
        Error(eval, ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (argIn.size() != 10)
    {
        Error(eval, ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    // INPUT VARIABLES
    ArrayOf DICO = argIn[0];
    std::string DICO_string = DICO.getContentAsCString();
    const char* DICO_ptr = DICO_string.c_str();
    ArrayOf N = argIn[1];
    int *N_ptr = (int*)N.getDataPointer();
    ArrayOf M = argIn[2];
    int *M_ptr = (int*)M.getDataPointer();
    ArrayOf NP = argIn[3];
    int *NP_ptr = (int*)NP.getDataPointer();
    ArrayOf ALPHA = argIn[4];
    double *ALPHA_ptr = (double*)ALPHA.getDataPointer();
    ArrayOf TOL = argIn[5];
    double *TOL_ptr = (double*)TOL.getDataPointer();
    // IN/OUT VARIABLES
    ArrayOf A = argIn[6];
    A.promoteType(NLS_DOUBLE);
    ArrayOf A_output = A;
    A_output.ensureSingleOwner();
    double *A_output_ptr = (double*)A_output.getDataPointer();
    ArrayOf B = argIn[7];
    B.promoteType(NLS_DOUBLE);
    ArrayOf B_output = B;
    B_output.ensureSingleOwner();
    double *B_output_ptr = (double*)B_output.getDataPointer();
    ArrayOf WR = argIn[8];
    WR.promoteType(NLS_DOUBLE);
    ArrayOf WR_output = WR;
    WR_output.ensureSingleOwner();
    double *WR_output_ptr = (double*)WR_output.getDataPointer();
    ArrayOf WI = argIn[9];
    WI.promoteType(NLS_DOUBLE);
    ArrayOf WI_output = WI;
    WI_output.ensureSingleOwner();
    double *WI_output_ptr = (double*)WI_output.getDataPointer();
    // OUTPUT VARIABLES
    ArrayOf NFP_output = ArrayOf::int32VectorConstructor(1);
    int *NFP_output_ptr = (int*)NFP_output.getDataPointer();
    ArrayOf NAP_output = ArrayOf::int32VectorConstructor(1);
    int *NAP_output_ptr = (int*)NAP_output.getDataPointer();
    ArrayOf NUP_output = ArrayOf::int32VectorConstructor(1);
    int *NUP_output_ptr = (int*)NUP_output.getDataPointer();
    ArrayOf F_output = ArrayOf::doubleMatrix2dConstructor((indexType)std::max(1, M.getContentAsInteger32Scalar()), (indexType)N.getContentAsInteger32Scalar());
    double *F_output_ptr = (double*)F_output.getDataPointer();
    ArrayOf Z_output = ArrayOf::doubleMatrix2dConstructor((indexType)std::max(1, N.getContentAsInteger32Scalar()), (indexType)N.getContentAsInteger32Scalar());
    double *Z_output_ptr = (double*)Z_output.getDataPointer();
    ArrayOf IWARN_output = ArrayOf::int32VectorConstructor(1);
    int *IWARN_output_ptr = (int*)IWARN_output.getDataPointer();
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int *INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // LOCAL VARIABLES
    ArrayOf LDA_local = ArrayOf::int32VectorConstructor(1);
    int* LDA_local_ptr = (int*)LDA_local.getDataPointer();
    LDA_local_ptr[0] = std::max(1, N.getContentAsInteger32Scalar());
    ArrayOf LDB_local = ArrayOf::int32VectorConstructor(1);
    int* LDB_local_ptr = (int*)LDB_local.getDataPointer();
    LDB_local_ptr[0] = std::max(1, N.getContentAsInteger32Scalar());
    ArrayOf LDF_local = ArrayOf::int32VectorConstructor(1);
    int* LDF_local_ptr = (int*)LDF_local.getDataPointer();
    LDF_local_ptr[0] = std::max(1, M.getContentAsInteger32Scalar());
    ArrayOf LDZ_local = ArrayOf::int32VectorConstructor(1);
    int* LDZ_local_ptr = (int*)LDZ_local.getDataPointer();
    LDZ_local_ptr[0] = std::max(1, N.getContentAsInteger32Scalar());
    ArrayOf DWORK_local = ArrayOf::doubleMatrix2dConstructor(1 , std::max(std::max(std::max( 1,5 * M.getContentAsInteger32Scalar()), 5 * N.getContentAsInteger32Scalar()), 2 * N.getContentAsInteger32Scalar() + 4 * M.getContentAsInteger32Scalar()));
    double * DWORK_local_ptr = (double*)DWORK_local.getDataPointer();
    ArrayOf LDWORK_local = ArrayOf::int32VectorConstructor(1);
    int* LDWORK_local_ptr = (int*)LDWORK_local.getDataPointer();
    LDWORK_local_ptr[0] = std::max(std::max(std::max( 1,5 * M.getContentAsInteger32Scalar()), 5 * N.getContentAsInteger32Scalar()), 2 * N.getContentAsInteger32Scalar() + 4 * M.getContentAsInteger32Scalar());
    // CALL EXTERN FUNCTION
    try
    {
        sb01bd_ ( DICO_ptr, N_ptr, M_ptr, NP_ptr, ALPHA_ptr, A_output_ptr, LDA_local_ptr, B_output_ptr, LDB_local_ptr, WR_output_ptr, WI_output_ptr, NFP_output_ptr, NAP_output_ptr, NUP_output_ptr, F_output_ptr, LDF_local_ptr, Z_output_ptr, LDZ_local_ptr, TOL_ptr, DWORK_local_ptr, LDWORK_local_ptr, IWARN_output_ptr, INFO_output_ptr);
    }
    catch (std::runtime_error &e)
    {
        Error(eval, "sb01bd function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0)
    {
        retval.push_back(A_output);
    }
    if (nLhs > 1)
    {
        retval.push_back(B_output);
    }
    if (nLhs > 2)
    {
        retval.push_back(WR_output);
    }
    if (nLhs > 3)
    {
        retval.push_back(WI_output);
    }
    if (nLhs > 4)
    {
        retval.push_back(NFP_output);
    }
    if (nLhs > 5)
    {
        retval.push_back(NAP_output);
    }
    if (nLhs > 6)
    {
        retval.push_back(NUP_output);
    }
    if (nLhs > 7)
    {
        retval.push_back(F_output);
    }
    if (nLhs > 8)
    {
        retval.push_back(Z_output);
    }
    if (nLhs > 9)
    {
        retval.push_back(IWARN_output);
    }
    if (nLhs > 10)
    {
        retval.push_back(INFO_output);
    }
    return retval;
}
//=============================================================================
