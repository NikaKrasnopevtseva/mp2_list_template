set(name "sample")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../include")

add_executable(${name} main_list.cpp)

target_link_libraries (${name} "src")
