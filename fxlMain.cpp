#include "framework.h"

// This is the actual function Excel will call.
// It takes a string (LPWSTR) and returns a pointer to an XLOPER12.
extern "C" __declspec(dllexport) LPXLOPER12 Greeting(wchar_t* name) {
    static XLOPER12 xResult;
    static wchar_t buffer[256];

    // Create the greeting string
    swprintf(buffer, 256, L"Hello, %s! (Build 2026)", name);

    // Set up the return object for Excel
    xResult.xltype = xltypeStr;
    xResult.val.str = buffer;
    
    // Note: In a real XLL, the first character of a string 
    // must be the length of the string (Pascal string style).
    // For this simple example, we'll keep it basic.
    
    return &xResult;
}

// This function is called by Excel when the XLL is loaded.
// It is used to register the UDFs.
extern "C" __declspec(dllexport) int xlAutoOpen(void) {
    // In a full implementation, we would call xlcRegister here.
    // For this minimal "build check," we just return 1 (Success).
    return 1;
}
