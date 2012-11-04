cmake_minimum_required(VERSION 2.8)

# Extra CMake modules are here
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Debug build by default
set(CMAKE_BUILD_TYPE Debug)


project(Audo)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(Audo_SOURCES 
   src/controller/ActionController.cpp
   src/controller/FileNewController.cpp
   src/controller/FileOpenController.cpp
   src/gui/Audo.cpp
   src/gui/EditSubWindow.cpp
   src/gui/MainWindow.cpp
   src/gui/MDIArea.cpp
   src/input/AudioReader.cpp
   src/model/Buffer.cpp
   src/model/BufferPool.cpp
   src/model/StandardBuffer.cpp
   src/output/JackOutput.cpp
   #src/tests/RefTest.cpp TODO tests
   src/view/WaveDisplay.cpp
)

set(Audo_HEADERS 
   src/controller/ActionController.h
   src/controller/FileNewController.h
   src/controller/FileOpenController.h
   src/gui/EditSubWindow.h
   src/gui/MainWindow.h
   src/gui/MDIArea.h
   src/input/AudioReader.h
   src/model/Buffer.h
   src/model/BufferPool.h
   src/model/BufferRef.h
   src/model/Ref.h
   src/model/StandardBuffer.h
   src/output/JackOutput.h
   src/output/Output.h
   src/util/AudoTypes.h
   src/util/log/Logger.h
   src/util/log/StreamLogger.h
   src/util/singleton.h
   src/view/WaveDisplay.h
)

# Qt4
find_package(Qt4 REQUIRED)
QT4_WRAP_CPP(Audo_HEADERS_MOC ${Audo_HEADERS})
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

# LibSndFile
find_package(LibSndFile REQUIRED)
include_directories(${LIBSNDFILE_INCLUDE_DIRS} ${JACK_INCLUDE_DIRS})

# Jack
find_package(Jack REQUIRED)
set(LIBS ${LIBS} ${LIBSNDFILE_LIBRARY} ${JACK_LIBRARIES})


add_executable(Audo ${Audo_SOURCES} ${Audo_HEADERS_MOC})
target_link_libraries(Audo ${LIBS} ${QT_LIBRARIES} )

