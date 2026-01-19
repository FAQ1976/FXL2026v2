cmake_minimum_required(VERSION 3.20)
project(FXLL2026v2 LANGUAGES CXX)

add_library(FXLL2026v2 SHARED fxlMain.cpp)
set_target_properties(FXLL2026v2 PROPERTIES SUFFIX ".xll")

# Link the Excel SDK
target_include_directories(FXLL2026v2 PRIVATE "${SDK_PATH}")
target_link_libraries(FXLL2026v2 PRIVATE "${SDK_PATH}/XLCALL32.LIB")

add_definitions(-D_UNICODE -DUNICODE)
