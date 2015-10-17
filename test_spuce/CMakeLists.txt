CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
IF(NOT CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE "DEBUG")
ENDIF()
PROJECT("spuce tests")
message("Project spuce_tests")

FIND_PACKAGE(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_library(spuce_debug plot_fft.cpp cfft.cpp gen_iir_df)

SET(TARGETS chebyshev_iir chebyshev_iir_hpf elliptic_iir elliptic_iir_hpf butterworth_iir
  butterworth_iir_hpf iir iir_df iir_df2)

ADD_DEFINITIONS(" -fPIC  ")

#INCLUDE_DIRECTORIES(".." "/usr/local/include")
#LINK_DIRECTORIES("/usr/local/lib")

FOREACH(mod ${TARGETS})
	SET(SRC test_${mod}.cpp)
	ADD_EXECUTABLE(plot_${mod} ${SRC})
  TARGET_LINK_LIBRARIES(plot_${mod} spucelib spuce_debug ${PYTHON_LIBRARY})
ENDFOREACH(mod ${EXTS})

