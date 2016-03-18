//-------------------------------------------------------------------------------------------------
// <copyright file="BAFunctions.h" company="Outercurve Foundation">
//   Copyright (c) 2004, Outercurve Foundation.
//   This software is released under Microsoft Reciprocal License (MS-RL).
//   The license and further copyright text can be found in the file
//   LICENSE.TXT at the root directory of the distribution.
// </copyright>
//-------------------------------------------------------------------------------------------------

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

enum BA_FUNCTIONS_MESSAGE
{
    BA_FUNCTIONS_MESSAGE_ONDETECTBEGIN = BOOTSTRAPPER_APPLICATION_MESSAGE_ONDETECTBEGIN,

    BA_FUNCTIONS_MESSAGE_ONTHEMELOADED = 1024,
};

struct BA_FUNCTIONS_CREATE_ARGS
{
    DWORD cbSize;
    DWORD64 qwBAFunctionsAPIVersion;
    BOOTSTRAPPER_CREATE_ARGS* pBootstrapperCreateArgs;
};

struct BA_FUNCTIONS_ONTHEMELOADED_ARGS
{
    DWORD cbSize;
    THEME* pTheme;
    WIX_LOCALIZATION* pWixLoc;
};

struct BA_FUNCTIONS_ONTHEMELOADED_RESULTS
{
    DWORD cbSize;
};

typedef HRESULT(WINAPI *PFN_BA_FUNCTIONS_PROC)(
    __in BA_FUNCTIONS_MESSAGE message,
    __in const LPVOID pvArgs,
    __inout LPVOID pvResults,
    __in_opt LPVOID pvContext
    );

typedef void (WINAPI *PFN_BA_FUNCTIONS_DESTROY)();

#ifdef __cplusplus
}
#endif
