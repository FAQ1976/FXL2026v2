#include "framework.h"
#include <XLCALL.H>

// The UDF Function
extern "C" __declspec(dllexport) LPXLOPER12 Greeting(wchar_t* name) {
    static XLOPER12 xResult;
    static wchar_t buffer[256];
    
    // Excel strings require the first character to be the length (Pascal style)
    int len = swprintf(buffer + 1, 255, L"Hello, %s! (2026 Build)", name);
    buffer[0] = (wchar_t)len; 

    xResult.xltype = xltypeStr;
    xResult.val.str = buffer;
    return &xResult;
}

// The Registration Function
extern "C" __declspec(dllexport) int xlAutoOpen(void) {
    static XLOPER12 xDll;
    
    // 1. Get the name of this XLL file
    Excel12(xlfGetName, &xDll, 0);

    // 2. Register 'Greeting'
    // "Q" = returns a pointer to XLOPER12, "C%" = takes a wide string
    Excel12(xlcRegister, 0, 4, &xDll, 
            (LPXLOPER12)L"\x08Greeting", // Function name
            (LPXLOPER12)L"\x02QC",       // Type signature
            (LPXLOPER12)L"\x08Greeting"  // Formula name
    );

    return 1;
}
