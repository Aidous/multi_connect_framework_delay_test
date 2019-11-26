cmake_minimum_required(VERSION 2.8.3)
project(connect_delay_test)

set(CMAKE_CXX_FLAGS "-W -std=c++11 ${CMAKE_CXX_FLAGS}")

## find ros packages and combine them with catkin
set(catkin_deps
	roscpp
	nav_msgs
	)
find_package(catkin REQUIRED COMPONENTS
			 ${catkin_deps}
			 )

set(CMAKE_BUILD_TYPE "Release")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
					cyber/deps/cyber/include
					${catkin_INCLUDE_DIRS})

link_directories(cyber/deps/cyber/lib)

add_subdirectory(cyber)

add_executable(ros_listener ros/ros_listener.cc)
target_link_libraries(ros_listener cyber_connector
					  ${catkin_LIBRARIES})

add_executable(ros_talker ros/ros_talker.cc)
target_link_libraries(ros_talker cyber_connector
					  ${catkin_LIBRARIES})

add_executable(lcm_listener lcm/lcm_listener.cc)
target_link_libraries(lcm_listener cyber_connector
					  lcm)

add_executable(lcm_talker lcm/lcm_talker.cc)
target_link_libraries(lcm_talker cyber_connector
					  lcm
					  ${catkin_LIBRARIES})