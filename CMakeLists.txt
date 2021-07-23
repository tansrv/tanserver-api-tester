cmake_minimum_required(VERSION 2.8)

set(PROJ TanTester)
set(TARGET tanserver_tester)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)
set(INSTALL_PATH ${CMAKE_CURRENT_BINARY_DIR}/../bin/)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${INSTALL_PATH})

aux_source_directory(. SRC)

project(${PROJ})

add_executable(${TARGET} ${SRC})

target_link_libraries(${TARGET} ssl crypto)

file(REMOVE ${CMAKE_CURRENT_BINARY_DIR}/null.c ${INSTALL_PATH}/null.c)

