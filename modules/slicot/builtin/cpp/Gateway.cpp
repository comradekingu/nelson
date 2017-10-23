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
#include "NelsonGateway.hpp"
#include "slicot_mb03rdBuiltin.hpp"
#include "slicot_mb03pdBuiltin.hpp"
#include "slicot_ab01odBuiltin.hpp"
#include "slicot_ab04mdBuiltin.hpp"
#include "slicot_ab08ndBuiltin.hpp"
#include "slicot_sb01bdBuiltin.hpp"
#include "slicot_sb03odBuiltin.hpp"
#include "slicot_sb03mdBuiltin.hpp"
#include "slicot_sb02odBuiltin.hpp"
#include "slicot_mb04mdBuiltin.hpp"
#include "slicot_ab07ndBuiltin.hpp"
#include "slicot_ab07ndBuiltin.hpp"
#include "slicot_ag08bdBuiltin.hpp"
#include "slicot_tg01adBuiltin.hpp"
#include "slicot_mc01tdBuiltin.hpp"
#include "slicot_mb04gdBuiltin.hpp"
#include "slicot_mb05odBuiltin.hpp"
#include "slicot_tb01idBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"slicot";
//=============================================================================
static const nlsGateway gateway[] =
{
    { "slicot_mb03rd", Nelson::SlicotGateway::slicot_mb03rdBuiltin, 7, 6},
    { "slicot_mb03pd", Nelson::SlicotGateway::slicot_mb03pdBuiltin, 6, 5},
    { "slicot_ab01od", Nelson::SlicotGateway::slicot_ab01odBuiltin, 8, 10},
    { "slicot_ab04md", Nelson::SlicotGateway::slicot_ab04mdBuiltin, 5, 7},
    { "slicot_ab08nd", Nelson::SlicotGateway::slicot_ab08ndBuiltin, 11, 9},
    { "slicot_sb01bd", Nelson::SlicotGateway::slicot_sb01bdBuiltin, 10, 7},
    { "slicot_sb03od", Nelson::SlicotGateway::slicot_sb03odBuiltin, 6, 6},
    { "slicot_sb03md", Nelson::SlicotGateway::slicot_sb03mdBuiltin, 8, 7},
    { "slicot_sb02od", Nelson::SlicotGateway::slicot_sb02odBuiltin, 9, 13},
    { "slicot_mb04md", Nelson::SlicotGateway::slicot_mb04mdBuiltin, 4, 2},
    { "slicot_ab07nd", Nelson::SlicotGateway::slicot_ab07ndBuiltin, 6, 4},
    { "slicot_ab07nd", Nelson::SlicotGateway::slicot_ab07ndBuiltin, 6, 4},
    { "slicot_ag08bd", Nelson::SlicotGateway::slicot_ag08bdBuiltin, 14, 9},
    { "slicot_tg01ad", Nelson::SlicotGateway::slicot_tg01adBuiltin, 7, 6},
    { "slicot_mc01td", Nelson::SlicotGateway::slicot_mc01tdBuiltin, 5, 3},
    { "slicot_mb04gd", Nelson::SlicotGateway::slicot_mb04gdBuiltin, 4, 2},
    { "slicot_mb05od", Nelson::SlicotGateway::slicot_mb05odBuiltin, 5, 4},
    { "slicot_tb01id", Nelson::SlicotGateway::slicot_tb01idBuiltin, 6, 5},
};
//=============================================================================
NLSGATEWAYFUNC(gateway)
//=============================================================================
NLSGATEWAYINFO(gateway)
//=============================================================================
NLSGATEWAYREMOVE(gateway)
//=============================================================================
NLSGATEWAYNAME()
//=============================================================================
