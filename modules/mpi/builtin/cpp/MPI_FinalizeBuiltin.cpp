//=============================================================================
// Copyright (c) 2016-2017 Allan CORNET (Nelson)
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
#include <mpi.h>
#include "MPI_FinalizeBuiltin.hpp"
#include "Error.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector Nelson::MpiGateway::MPI_FinalizeBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (argIn.size() != 0)
    {
        Error(eval, ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    if (nLhs > 1)
    {
        Error(eval, ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
	int flag = MPI_Finalize();
	retval.push_back(ArrayOf::logicalConstructor(flag));
	return retval;
}
//=============================================================================