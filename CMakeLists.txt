cmake_minimum_required(VERSION 3.12)

project(SFMLGame LANGUAGES CXX)

set(SRC_DIR src)
set(INCLUDE_DIR include)
set(BUILD_DIR build)

set(CMAKE_BUILD_TYPE Debug)

find_package(SFML COMPONENTS graphics window system)

file(GLOB SOURCES ${SRC_DIR}/*.cpp)
file(GLOB INCLUDES ${INCLUDE_DIR}/*.hpp)

include_directories(${SFML_INCLUDE} ${INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-main sfml-graphics sfml-window sfml-system)

add_custom_target(debug
    COMMAND ${CMAKE_CXX_COMPILER} ${CMAKE_CXX_FLAGS} ${SRCS} -I${SFML_INCLUDE} -I${INCLUDE_DIR} -L${SFML_LIB} -lsfml-main -lsfml-graphics -lsfml-window -lsfml-system -D__DEBUG__ -o ${BUILD_DIR}/debug.exe
    DEPENDS ${SRCS}
)

add_custom_target(run_clean
    COMMAND ${CMAKE_MAKE_PROGRAM} run
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
)

add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
)

# add_custom_target(clean
#     COMMAND PowerShell -Command "Remove-Item -Path ${EXE} -Force"
# )
