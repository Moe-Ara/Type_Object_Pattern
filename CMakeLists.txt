cmake_minimum_required(VERSION 3.23)
project(TypeObject)

set(CMAKE_CXX_STANDARD 23)
find_package(Boost REQUIRED COMPONENTS)

include_directories(include/)
add_executable(TypeObject Demo.cpp src/Monster.cpp include/Monster.h src/Breed.cpp include/Breed.h cJson/cJSON.c)

if(Boost_FOUND)
    message("-- Boost Found: "  ${Boost_VERSION}v)
    include_directories(TypeObject ${Boost_INCLUDE_DIRS})
    target_link_libraries(TypeObject ${Boost_LIBRARIES})
endif()

