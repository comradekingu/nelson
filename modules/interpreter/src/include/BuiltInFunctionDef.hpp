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
#pragma once
//=============================================================================
#include "ArrayOf.hpp"
#include "Evaluator.hpp"
#include "FunctionDef.hpp"
#include "nlsInterpreter_exports.h"
//=============================================================================
namespace Nelson {
//=============================================================================
using BuiltInFuncPtr = ArrayOfVector (*)(Evaluator*, int, const ArrayOfVector&);
//=============================================================================
class NLSINTERPRETER_IMPEXP BuiltInFunctionDef : public FunctionDef
{
public:
    /**
     * Location of the function's defining dynamic library.
     */
    std::wstring fileName;
    /**
     * The number of return args for this function (-1 for variable).
     */
    int retCount;
    /** The number of input args for this function (-1 for variable).
     */
    int argCount;
    /**
     * The pointer to (address of) the function.
     */
    BuiltInFuncPtr fptr;
    /**
     * Default constructor.
     */
    BuiltInFunctionDef();
    /**
     * Default destructor.
     */
    ~BuiltInFunctionDef() override;
    /**
     * The type of the function is NLS_BUILT_IN_FUNCTION
     */
    const FunctionType
    type() override
    {
        return NLS_BUILT_IN_FUNCTION;
    }
    /** Print a description of the function
     */
    void
    printMe(Interface* /*io*/) override;
    /**
     * The number of inputs required by this function.
     */
    int
    inputArgCount() override
    {
        return argCount;
    }
    /**
     * The number of outputs returned by this function.
     */
    int
    outputArgCount() override
    {
        return retCount;
    }
    /**
     * Evaluate the function and return the values.
     */

    ArrayOfVector
    evaluateFunction(Evaluator* /*unused*/, ArrayOfVector& /*unused*/, int /*unused*/) override;
};
//=============================================================================
} // namespace Nelson
//=============================================================================
