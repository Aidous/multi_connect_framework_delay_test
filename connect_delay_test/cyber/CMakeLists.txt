cmake_minimum_required(VERSION 2.8.3)
project(cyber_connector)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

ENABLE_LANGUAGE(ASM)

find_package(UUID REQUIRED)
find_package(PROTOBUF REQUIRED)
find_package(gflags REQUIRED)
find_package(qpOASES REQUIRED)
find_package(osqp REQUIRED)
find_package(GLOG REQUIRED)
find_package(curlpp REQUIRED)
find_package(TINYXML2 REQUIRED)
find_package(PROJ4 REQUIRED)
find_package(IPOPT REQUIRED)
find_package(ADOLC REQUIRED)
find_package(Eigen3 QUIET)
find_package(OpenMP)
find_package(Poco REQUIRED)
find_package(UUID REQUIRED)

if (OPENMP_FOUND)
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
	set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

find_package(Eigen3 QUIET)
if(NOT EIGEN3_FOUND)
	find_package(PkgConfig REQUIRED)
	pkg_check_modules(EIGEN3 REQUIRED eigen3)
	set(EIGEN3_INCLUDE_DIR ${EIGEN3_INCLUDE_DIRS})
endif()
add_definitions(${EIGEN_DEFINITIONS})

find_package(FastRTPS REQUIRED)

include_directories(
		deps/cyber/include
		${GLOG_INCLUDE_DIRS}
		${GFLAGS_INCLUDE_DIRS}
		${OpenCV_INCLUDE_DIRS}
		${EIGEN3_INCLUDE_DIRS}
		${PROTOBUF_INCLUDE_DIRS}
		${qpOASES_INCLUDE_DIRS}
		${osqp_INCLUDE_DIRS}
		${TINYXML2_INCLUDE_DIRS}
		${IPOPT_INCLUDE_DIRS}
		${PROJ4_INCLUDE_DIRS}
		${ADOLC_INCLUDE_DIRS}
		${UUID_INCLUDE_DIR}
		${FastRTPS_INCLUDE_DIR}
		${Poco_INCLUDE_DIRS}
		${UUID_INCLUDE_DIR}
)

add_library(${PROJECT_NAME} "")
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${PROJECT_NAME} cyber
					  boost_system
					  boost_thread
					  atomic
					  gflags
					  ${PROTOBUF_LIBRARIES}
					  ${GLOG_LIBRARIES}
					  ${OpenCV_LIBRARIES}
					  ${EIGEN3_LIBRARIES}
					  ${qpOASES_LIBRARIES}
					  ${osqp_LIBRARIES}
					  ${TINYXML2_LIBRARIES}
					  ${IPOPT_LIBRARIES}
					  ${PROJ4_LIBRARIES}
					  ${ADOLC_LIBRARIES}
					  ${FastRTPS_LIBRARIES}
					  ${FastCDR_LIBRARIES}
					  ${Poco_LIBRARIES}
					  ${UUID_LIBRARY})

add_executable(cyber_listener
			   performance_listener.cc)
target_link_libraries(cyber_listener ${PROJECT_NAME})

add_executable(cyber_talker
			   performance_talker.cc)
target_link_libraries(cyber_talker ${PROJECT_NAME}
					  )