########################################################################
# Project setup
########################################################################
cmake_minimum_required(VERSION 2.8)
project(SpucIIR)
enable_language(CXX)

find_package(Pothos CONFIG REQUIRED)

########################################################################
# Module setup
########################################################################
POTHOS_MODULE_UTIL(
    TARGET IIR
    SOURCES  IIRDesigner.cpp 
    DESTINATION CustomBlocks
    ENABLE_DOCS
		)
	
