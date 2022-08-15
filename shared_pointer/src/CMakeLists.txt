add_executable(shared_ptr main.cpp)

target_include_directories(shared_ptr PUBLIC ${MY_INCLUDE_DIR})

add_library(my_lib ${MY_INCLUDE_DIR}/dogtoy.h template.cpp
        ${MY_INCLUDE_DIR}/shared_ptr_toy.h shared_ptr_toy.cpp)

target_include_directories(my_lib PUBLIC ${MY_INCLUDE_DIR})

target_link_libraries(shared_ptr PRIVATE my_lib)
        
