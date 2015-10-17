########################################################################
# Project setup
########################################################################
cmake_minimum_required(VERSION 2.8)
project(SpucIIR)
enable_language(CXX)

find_package(Pothos CONFIG REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

SET(FILT_SRCS  
	spuce/filters/butterworth_iir.cpp
	spuce/filters/chebyshev_iir.cpp
	spuce/filters/elliptic_iir.cpp
	spuce/filters/find_roots.cpp
	spuce/filters/fir_coeff.cpp
	spuce/filters/iir_coeff.cpp
)

add_library(spucelib ${FILT_SRCS})

add_subdirectory(test_spuce)

########################################################################
# Module setup
########################################################################
POTHOS_MODULE_UTIL(
    TARGET NewIIR
    SOURCES  IIRDesigner.cpp IIRFilter.cpp TestIIRFilter.cpp
    DESTINATION CustomBlocks
		LIBRARIES spucelib
    ENABLE_DOCS
		)
	
