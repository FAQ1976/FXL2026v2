#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <wchar.h>  // Added to fix the 'swprintf' error

typedef struct _xloper12 {
    union {
        double num;
        wchar_t* str;
        short int err;
        short int w;
    } val;
    DWORD xltype;
} XLOPER12, *LPXLOPER12;

#define xltypeNum 0x0001
#define xltypeStr 0x0002
