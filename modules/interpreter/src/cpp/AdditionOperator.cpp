//=============================================================================
// Copyright (c) 2016-2018 Allan CORNET (Nelson)
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
#include "Addition.hpp"
#include "StringArrayAddition.hpp"
#include "Evaluator.hpp"
#include "OverloadBinaryOperator.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
ArrayOf
Evaluator::additionOperator(ASTPtr t)
{
    pushID(t->context());
    ArrayOf retval = this->additionOperator(expression(t->down), expression(t->down->right));
    popID();
    return retval;
}
//=============================================================================
ArrayOf
Evaluator::additionOperator(ArrayOf A, ArrayOf B)
{
    ArrayOf res;
    bool bSuccess = false;
    if (overloadOnBasicTypes) {
        res = OverloadBinaryOperator(this, A, B, "plus", bSuccess);
    }
    if (!bSuccess) {
        if (A.isStringArray() || B.isStringArray()) {
            bool needToOverload = false;
            A = ArrayOf::toStringArray(A, needToOverload);
            if (needToOverload) {
                return OverloadBinaryOperator(this, A, B, "plus");
            }
            B = ArrayOf::toStringArray(B, needToOverload);
            if (needToOverload) {
                return OverloadBinaryOperator(this, A, B, "plus");
            }
            return stringArray_plus_stringArray(A, B);
        }
        bool isDoubleA = (A.isDoubleType() || A.isNdArrayDoubleType());
        bool isDoubleB = (B.isDoubleType() || B.isNdArrayDoubleType());
        bool isSingleA = (A.isSingleType() || A.isNdArraySingleType());
        bool isSingleB = (B.isSingleType() || B.isNdArraySingleType());
        if ((isDoubleA || isSingleA) && (isDoubleB || isSingleB)) {
            if (isDoubleA && isDoubleB) {
                res = double_plus_double(A, B);
            } else if (isSingleA && isSingleB) {
                res = single_plus_single(A, B);
            } else {
                if (A.getDataClass() == NLS_DOUBLE) {
                    A.promoteType(NLS_SINGLE);
                } else {
                    A.promoteType(NLS_SCOMPLEX);
                }
                if (B.getDataClass() == NLS_DOUBLE) {
                    B.promoteType(NLS_SINGLE);
                } else {
                    B.promoteType(NLS_SCOMPLEX);
                }
                res = single_plus_single(A, B);
            }
        } else {
            bool isIntegerA = A.isIntegerType() || A.isNdArrayIntegerType();
            bool isIntegerB = B.isIntegerType() || B.isNdArrayIntegerType();
            if (isIntegerA && isIntegerB) {
                if (A.getDataClass() == B.getDataClass()) {
                    res = integer_plus_integer(A, B);
                } else {
                    Error(_W("Integers of the same class expected."));
                }
            } else {
                if (isIntegerA && isDoubleB && B.isScalar()) {
                    Class classA = A.getDataClass();
                    B.promoteType(classA);
                    res = integer_plus_integer(A, B);
                } else if (isIntegerB && isDoubleA && A.isScalar()) {
                    Class classB = B.getDataClass();
                    A.promoteType(classB);
                    res = integer_plus_integer(A, B);
                } else {
                    res = OverloadBinaryOperator(this, A, B, "plus");
                }
            }
        }
    }
    return res;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
