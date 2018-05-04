cmake_minimum_required(VERSION 2.8.3)
project(class_example)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  mg_msgs
  roscpp
  std_msgs
)

catkin_package(

)

###########
## Build ##
###########
include_directories(
include
  ${catkin_INCLUDE_DIRS}
)

add_executable(class_example 
               src/class_example.cpp)
target_link_libraries(class_example ${catkin_LIBRARIES})
add_dependencies(class_example ${catkin_EXPORTED_TARGETS})
add_dependencies(class_example mg_msgs_generate_messages_cpp)

install(TARGETS class_example
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(callback_example 
               src/callback_example.cpp)
target_link_libraries(callback_example ${catkin_LIBRARIES})
add_dependencies(callback_example ${catkin_EXPORTED_TARGETS})
add_dependencies(callback_example mg_msgs_generate_messages_cpp)

install(TARGETS callback_example
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})