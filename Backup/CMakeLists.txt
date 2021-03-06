###
### Rhoban Input Output Libray
### Rhoban 2015
###

cmake_minimum_required(VERSION 2.8)
project(RhIO)

find_package(catkin REQUIRED COMPONENTS
  jsoncpp
  ZeroMQ
  )

# What is published by the 'RhIO package'
catkin_package(
  INCLUDE_DIRS .
  LIBRARIES RhIO RhIOClient
  CATKIN_DEPENDS jsoncpp ZeroMQ
)


#Option for compiling Tests
option(BUILD_RHIO_TESTS "Build RhIO Tests" OFF)

#Option for compiling Examples
option(BUILD_RHIO_EXAMPLES "Build RhIO Examples" OFF)

#Include sources directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${catkin_INCLUDE_DIRS})

#Sources files
set(SOURCES_FILES_SERVER
    Server/Bind.cpp
    Server/CommandNode.cpp
    Server/IONode.cpp
    Server/Filesystem.cpp
    Server/RhIO.cpp
    Server/ServerPub.cpp
    Server/ServerRep.cpp
    Server/Stream.cpp
    Server/StreamNode.cpp
    Server/FrameNode.cpp
    Server/ValueNode.cpp
)
set(SOURCES_FILES_COMMON
    Common/DataBuffer.cpp
)
set(SOURCES_FILES_CLIENT
    Client/ClientReq.cpp
    Client/ClientSub.cpp
)

#Needed Libraries
set(RHIO_LIBRARIES
    pthread
    ${catkin_LIBRARIES}
)

#Enable C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#Enable compiler Warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")

#Build Server and Client as shared library
add_library(RhIO SHARED ${SOURCES_FILES_SERVER} ${SOURCES_FILES_COMMON})
target_link_libraries(RhIO ${RHIO_LIBRARIES})
add_library(RhIOClient SHARED ${SOURCES_FILES_CLIENT} ${SOURCES_FILES_COMMON})
target_link_libraries(RhIOClient ${RHIO_LIBRARIES})

#Build Tests
if (BUILD_RHIO_TESTS)
    add_executable(testTree Tests/testTree.cpp)
    target_link_libraries(testTree RhIO)
    
    add_executable(testValue Tests/testValue.cpp)
    target_link_libraries(testValue RhIO)
    
    add_executable(testThreadSafeTree Tests/testThreadSafeTree.cpp)
    target_link_libraries(testThreadSafeTree RhIO)
    add_executable(testThreadSafeValue Tests/testThreadSafeValue.cpp)
    target_link_libraries(testThreadSafeValue RhIO)
    add_executable(testThreadSafeValueUpdate Tests/testThreadSafeValueUpdate.cpp)
    target_link_libraries(testThreadSafeValueUpdate RhIO)
    
    add_executable(testPersistSave Tests/testPersistSave.cpp)
    target_link_libraries(testPersistSave RhIO)
    add_executable(testPersistLoad Tests/testPersistLoad.cpp)
    target_link_libraries(testPersistLoad RhIO)
    
    add_executable(testServerRep Tests/testServerRep.cpp)
    target_link_libraries(testServerRep RhIO)
    add_executable(testClientReq Tests/testClientReq.cpp)
    target_link_libraries(testClientReq RhIOClient)
    
    add_executable(testServerPub Tests/testServerPub.cpp)
    target_link_libraries(testServerPub RhIO)
    add_executable(testClientSub Tests/testClientSub.cpp)
    target_link_libraries(testClientSub RhIOClient)
    
    add_executable(testServer Tests/testServer.cpp)
    target_link_libraries(testServer RhIO)
    
    add_executable(testServerStress Tests/testServerStress.cpp)
    target_link_libraries(testServerStress RhIO)
    
    add_executable(testCommands Tests/testCommands.cpp)
    target_link_libraries(testCommands RhIO)
    
    add_executable(testBind Tests/testBind.cpp)
    target_link_libraries(testBind RhIO)
    
    add_executable(testImgs Tests/testImgs.cpp)
    target_link_libraries(testImgs RhIO)
endif (BUILD_RHIO_TESTS)

#Build Examples
if (BUILD_RHIO_EXAMPLES)
    add_executable(exampleIntro Examples/exampleIntro.cpp)
    target_link_libraries(exampleIntro RhIO)
    
    add_executable(exampleValues Examples/exampleValues.cpp)
    target_link_libraries(exampleValues RhIO)
    
    add_executable(exampleStreamsAndCommands Examples/exampleStreamsAndCommands.cpp)
    target_link_libraries(exampleStreamsAndCommands RhIO)
    
    add_executable(exampleFrames Examples/exampleFrames.cpp)
    target_link_libraries(exampleFrames RhIO)
    
    add_executable(exampleBind Examples/exampleBind.cpp)
    target_link_libraries(exampleBind RhIO)
endif (BUILD_RHIO_EXAMPLES)

