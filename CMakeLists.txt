cmake_minimum_required(VERSION 2.8)

# Extra CMake modules are here
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Debug build by default
set(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g -Wall -Wextra")


project(Audo)

include_directories(${CMAKE_SOURCE_DIR}/src)


set(AudoLib_SOURCES 
   ./src/controller/ActionController.cpp
   ./src/controller/FileNewController.cpp
   ./src/controller/FileOpenController.cpp
   ./src/gui/EditSubWindow.cpp
   ./src/gui/MainWindow.cpp
   ./src/gui/MDIArea.cpp
   ./src/input/AudioReader.cpp
   ./src/model/Buffer.cpp
   ./src/model/AudoTypeBase.cpp
   ./src/model/BufferPool.cpp
   ./src/model/EmptyBuffer.cpp
   ./src/model/SampleSource.cpp
   ./src/model/StandardBuffer.cpp
   ./src/output/JackOutput.cpp
   ./src/view/WaveDisplay.cpp
)

set(AudoLib_HEADERS 
   ./src/controller/ActionController.h
   ./src/controller/FileNewController.h
   ./src/controller/FileOpenController.h
   ./src/gui/EditSubWindow.h
   ./src/gui/MainWindow.h
   ./src/gui/MDIArea.h
   ./src/input/AudioReader.h
   ./src/model/AudoType.h
   ./src/model/AudoTypeBase.h
   ./src/model/Buffer.h
   ./src/model/BufferPool.h
   ./src/model/BufferRef.h
   ./src/model/EmptyBuffer.h
   ./src/model/Ref.h
   ./src/model/SampleSource.h
   ./src/model/StandardBuffer.h
   ./src/output/JackOutput.h
   ./src/output/Output.h
   ./src/util/AudoTypes.h
   ./src/util/log/Logger.h
   ./src/util/log/StreamLogger.h
   ./src/util/singleton.h
   ./src/view/WaveDisplay.h
)

# Boost

find_package(Boost)
include_directories(${Boost_INCLUDE_DIR})
add_definitions("-DHAS_BOOST")

# Qt4
find_package(Qt4 REQUIRED)
QT4_WRAP_CPP(AudoLib_HEADERS_MOC ${AudoLib_HEADERS})
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

# LibSndFile
find_package(LibSndFile REQUIRED)
include_directories(${LIBSNDFILE_INCLUDE_DIRS} ${JACK_INCLUDE_DIRS})

# Jack
find_package(Jack REQUIRED)
set(LIBS ${LIBS} ${LIBSNDFILE_LIBRARY} ${JACK_LIBRARIES} ${QT_LIBRARIES})

# Main Library

add_library(
   AudoLib STATIC 
   ${AudoLib_SOURCES}
   ${AudoLib_HEADERS_MOC}
)
target_link_libraries(AudoLib ${LIBS})

# Main Executable

set(Audo_SOURCES 
   ./src/gui/Audo.cpp
)

add_executable(Audo ${Audo_SOURCES})
target_link_libraries(Audo AudoLib)

#==============================
# Unit Tests
#==============================

# CppUnit

find_package(CppUnit REQUIRED)
set(AudoTests_LIBS ${AudoTest_LIBS} ${CPPUNIT_LIBRARY})

# Unit test executable

set(AudoTests_SOURCES
   ./src/tests/RefTest.cpp
)

set(AudoTests_HEADERS ${CPPUNIT_INCLUDE_DIR})

include_directories(${AudoTests_HEADERS})

add_executable(AudoTests ${AudoTests_SOURCES} ${AudoTests_HEADERS})
target_link_libraries(AudoTests ${AudoTests_LIBS})
target_link_libraries(AudoTests AudoLib)
