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
#include "Interface.hpp"
#include "nlsGui_exports.h"
#include <string>
//=============================================================================
using namespace Nelson;
//=============================================================================
class NLSGUI_IMPEXP GuiTerminal : public Interface
{
public:
    GuiTerminal(void* qtMainW);
    ~GuiTerminal() override;

    /**
     *  Get a line of input from the user with the
     *  given prompt.
     */
    std::string
    getLine(std::string prompt) override;
    std::wstring
    getLine(std::wstring prompt) override;
    std::wstring
    getInput(std::wstring prompt) override;

    /**
     *  Return the width of the current "terminal" in
     *  characters.
     */
    size_t
    getTerminalWidth() override;
    /**
     *  Output the following text message.
     */
    void
    outputMessage(std::string msg) override;
    void
    outputMessage(std::wstring msg) override;
    /**
     *  Output the following error message.
     */
    void
    errorMessage(std::string msg) override;
    void
    errorMessage(std::wstring msg) override;
    /**
     *  Output the following warning message.
     */
    void
    warningMessage(std::string msg) override;
    void
    warningMessage(std::wstring msg) override;

    void
    clearTerminal() override;

    void*
    getQtPointer();
    void
    banner();
    void
    insertHtml(std::wstring msg);
    int
    getBufferScreenLine();
    void
    setBufferScreenLine(int newMax);
    bool
    isAtPrompt() override;

private:
    std::wstring
    getTextLine(std::wstring prompt, bool bIsInput = false);
};
//=============================================================================
