set (TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
configure_file (
	"config.h.in"
	"${CMAKE_CURRENT_BINARY_DIR}/config.h"
)
include_directories("${CMAKE_CURRENT_BINARY_DIR}")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(limited-executing-test 
        main.cpp

        ../main/executor/executor.cpp
        ../main/executor/executors_pool.cpp
        ../main/logxx/logxx.cpp
        ../main/server/server.cpp
        ../main/task/task.cpp
        ../main/task/tasks_pool.cpp
        ../main/threadxx/threadxx.cpp

        server/test_server.cpp
        task/test_task.cpp
        task/test_pool.cpp
        task/pool_realisation.cpp
        task/primitive_executor.cpp

)
