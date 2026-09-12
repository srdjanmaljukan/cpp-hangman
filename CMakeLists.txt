cmake_minimum_required(VERSION 3.15)

# Name of your project
project(MyCppProject LANGUAGES CXX)

# Force C++20 standard (or change to 17/23 as needed)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find all .cpp files inside your src folder automatically
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the executable using the files found in src
add_executable(MyExecutable ${SOURCES})

# Copy words.txt to the build output directory after each build
add_custom_command(TARGET MyExecutable POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/words.txt
        $<TARGET_FILE_DIR:MyExecutable>
)