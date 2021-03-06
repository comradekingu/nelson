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
#include "GetCurrentNFilename.hpp"
#include "characters_encoding.hpp"
//=============================================================================
namespace Nelson {
std::wstring
GetCurrentNFilenameW(Evaluator* eval)
{
    std::string callerName = eval->getCallerFunctionName();
    std::wstring fileName;
    if (callerName == "EvaluateScript") {
        fileName = eval->getCurrentEvaluateFilename();
    } else {
        if (callerName == "EvaluateString") {
            fileName = L"";
        } else {
            fileName = utf8_to_wstring(callerName);
        }
    }
    return fileName;
}
//=============================================================================
NLSCORE_IMPEXP std::string
GetCurrentNFilenameU(Evaluator* eval)
{
    return wstring_to_utf8(GetCurrentNFilenameW(eval));
}
//=============================================================================
} // namespace Nelson
//=============================================================================
