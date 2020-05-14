cmake_minimum_required (VERSION 3.0)

PROJECT(GAME_GL)

SET(include_dir	${CMAKE_CURRENT_SOURCE_DIR}/include)
SET(bin_dir ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)


#local includes
INCLUDE_DIRECTORIES(${include_dir})

#glutLibraries (must be in include folder)
LINK_DIRECTORIES(${include_dir})


#bin output
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${bin_dir})

ADD_EXECUTABLE(boardgame 
${src_dir}/game.cpp
${src_dir}/boardgl.cpp
${src_dir}/gltools.cpp
)

TARGET_LINK_LIBRARIES(boardgame glut64)













