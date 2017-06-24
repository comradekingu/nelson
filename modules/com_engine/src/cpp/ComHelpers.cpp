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
#include "ComHelpers.hpp"
//=============================================================================
namespace Nelson {
	//=============================================================================
	bool isMethodCom(IDispatch *pDisp, std::wstring methodToSearch)
	{
		ITypeInfo *ti;
		unsigned int tiCount;
		HRESULT hr;

		if ((hr = pDisp->GetTypeInfoCount(&tiCount)) == S_OK && tiCount == 1)
		{
			TYPEATTR *pAttr;

			hr = pDisp->GetTypeInfo(0, LOCALE_USER_DEFAULT, &ti);
			hr = ti->GetTypeAttr(&pAttr);
			for (int k = 0; k<pAttr->cFuncs; k++)
			{
				FUNCDESC *pFuncDesc;
				BSTR name;
				hr = ti->GetFuncDesc(k, &pFuncDesc);
				hr = ti->GetDocumentation(pFuncDesc->memid, &name, NULL, NULL, NULL);
				if (pFuncDesc->invkind & (DISPATCH_METHOD))
				{
					std::wstring method = std::wstring(name);
					if (method == methodToSearch)
					{
						return true;
					}
				}
				SysFreeString(name);
				ti->ReleaseFuncDesc(pFuncDesc);
			}
			ti->ReleaseTypeAttr(pAttr);
		}
		return false;
	}
	//=============================================================================
	bool isPropertyGetCom(IDispatch *pDisp, std::wstring propertyToSearch)
	{
		ITypeInfo *ti;
		unsigned int tiCount;
		HRESULT hr;

		if ((hr = pDisp->GetTypeInfoCount(&tiCount)) == S_OK && tiCount == 1)
		{
			TYPEATTR *pAttr;

			hr = pDisp->GetTypeInfo(0, LOCALE_USER_DEFAULT, &ti);
			hr = ti->GetTypeAttr(&pAttr);
			for (int k = 0; k<pAttr->cFuncs; k++)
			{
				FUNCDESC *pFuncDesc;
				BSTR name;
				hr = ti->GetFuncDesc(k, &pFuncDesc);
				hr = ti->GetDocumentation(pFuncDesc->memid, &name, NULL, NULL, NULL);
				if (pFuncDesc->invkind & (DISPATCH_PROPERTYGET))
				{
					std::wstring method = std::wstring(name);
					if (method == propertyToSearch)
					{
						return true;
					}
				}
				SysFreeString(name);
				ti->ReleaseFuncDesc(pFuncDesc);
			}
			ti->ReleaseTypeAttr(pAttr);
		}
		return false;
	}
	//=============================================================================
	bool isPropertyPutCom(IDispatch *pDisp, std::wstring propertyToSearch)
	{
		ITypeInfo *ti;
		unsigned int tiCount;
		HRESULT hr;

		if ((hr = pDisp->GetTypeInfoCount(&tiCount)) == S_OK && tiCount == 1)
		{
			TYPEATTR *pAttr;

			hr = pDisp->GetTypeInfo(0, LOCALE_USER_DEFAULT, &ti);
			hr = ti->GetTypeAttr(&pAttr);
			for (int k = 0; k<pAttr->cFuncs; k++)
			{
				FUNCDESC *pFuncDesc;
				BSTR name;
				hr = ti->GetFuncDesc(k, &pFuncDesc);
				hr = ti->GetDocumentation(pFuncDesc->memid, &name, NULL, NULL, NULL);
				if (pFuncDesc->invkind & (DISPATCH_PROPERTYPUT))
				{
					std::wstring method = std::wstring(name);
					if (method == propertyToSearch)
					{
						return true;
					}
				}
				SysFreeString(name);
				ti->ReleaseFuncDesc(pFuncDesc);
			}
			ti->ReleaseTypeAttr(pAttr);
		}
		return false;
	}
	//=============================================================================
}
//=============================================================================
