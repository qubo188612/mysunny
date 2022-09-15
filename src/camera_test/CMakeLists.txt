cmake_minimum_required(VERSION 3.8)
project(camera_test)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIB REQUIRED IMPORTED_TARGET libmodbus)

add_library(camera_test SHARED src/camera_test.cpp)

ament_target_dependencies(camera_test
  rclcpp
  rclcpp_components
  sensor_msgs
  OpenCV
)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} PkgConfig::LIB)

target_include_directories(camera_test
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

rclcpp_components_register_node(camera_test
  PLUGIN "camera_test::CameraTest"
  EXECUTABLE camera_test_node
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS camera_test EXPORT export_camera_test DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY bmp DESTINATION share/${PROJECT_NAME})
#install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})
#install(DIRECTORY config DESTINATION share/${PROJECT_NAME})

ament_export_targets(export_camera_test HAS_LIBRARY_TARGET)

ament_package()
