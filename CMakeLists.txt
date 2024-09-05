
cmake_minimum_required (VERSION 3.8)

project (JTTYServer)

if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()

cmake_policy(SET CMP0144 NEW)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_DEBUG_LIBS OFF)
set(Boost_USE_RELEASE_LIBS ON)
set(Boost_USE_MULTITHREADED ON)

find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenSSL REQUIRED)

add_compile_definitions(
    OPENSSL_USE_STATIC_LIBS
    BOOST_ALL_NO_LIB
)

add_executable(JTTYServer "src/main.cpp")

target_compile_options(JTTYServer PUBLIC
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror -Wno-c++98-compat>
)

target_include_directories(JTTYServer PUBLIC
    ${OpenSSL_DIRECTORY}/include
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(JTTYServer PUBLIC
    OpenSSL::Crypto
    OpenSSL::SSL
    ${Boost_LIBRARIES}
)
