set(target_src "src")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../include")

file(GLOB src "list.cpp")

add_library(${target_src} STATIC ${src})