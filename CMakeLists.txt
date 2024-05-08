
cmake_minimum_required (VERSION 3.8)

project (JTTYServer)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BOOST_ROOT "G:/_libs/boost-1.84.0")
set(OpenSSL_DIRECTORY "G:/_libs/OpenSSL-Win64")

set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(boost 1.84.0 REQUIRED COMPONENTS asio)

add_compile_definitions(
    OPENSSL_USE_STATIC_LIBS
    BOOST_ALL_NO_LIB
)

add_executable(JTTYServer main.cpp  )

target_compile_options(JTTYServer PUBLIC
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror -Wno-c++98-compat>
)

target_include_directories(JTTYServer PUBLIC
    ${CMAKE_SOURCE_DIR}/sources
    ${OpenSSL_DIRECTORY}/include
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(JTTYServer PUBLIC
    ${OpenSSL_DIRECTORY}/lib/libcrypto.lib
    ${OpenSSL_DIRECTORY}/lib/libssl.lib
    ${Boost_LIBRARIES}
)

add_compile_definitions(
    OPENSSL_USE_STATIC_LIBS
    BOOST_ALL_NO_LIB
)
