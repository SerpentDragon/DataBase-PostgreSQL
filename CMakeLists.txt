cmake_minimum_required(VERSION 3.10)

project(DataBaseProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

set(SOURCES
	main.cpp
	Controller.cpp
	DBConnector.cpp
	Employee.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PQXX_LINK_LIBRARIES})
