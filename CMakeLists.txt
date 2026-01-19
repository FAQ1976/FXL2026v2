cmake_minimum_required(VERSION 3.20)
project(FXLL2026v2 LANGUAGES CXX)

# Create a shared library (DLL)
add_library(FXLL2026v2 SHARED fxlMain.cpp)

# Change the extension from .dll to .xll
set_target_properties(FXLL2026v2 PROPERTIES SUFFIX ".xll")

# Target Windows 10/11
add_definitions(-D_UNICODE -DUNICODE)