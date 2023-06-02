cmake_minimum_required(VERSION 3.23)
project(Employee_management_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(employee_management_system employee_management_system.cpp workerManger.cpp workerManger.h worker.h employee.cpp employee.h manager.cpp manager.h boss.cpp boss.h)
