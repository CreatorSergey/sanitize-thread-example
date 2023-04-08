project(test)

add_compile_options(-fsanitize=thread)
add_link_options(-fsanitize=thread)

add_executable(test main.cpp)

target_link_libraries(test pthread)