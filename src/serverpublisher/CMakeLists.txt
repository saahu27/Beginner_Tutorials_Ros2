cmake_minimum_required(VERSION 3.8)
project(serverpublisher)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tutorial_interfaces REQUIRED) 

add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp tutorial_interfaces)

add_executable(talkerandlistner src/pub_sub_node.cpp)
ament_target_dependencies(talkerandlistner rclcpp tutorial_interfaces)

add_executable(server src/add_two_ints_server.cpp)
ament_target_dependencies(server rclcpp tutorial_interfaces)

add_executable(stringserver src/change_string_server.cpp)
ament_target_dependencies(stringserver rclcpp std_msgs tutorial_interfaces)

add_executable(static_transform_publisher src/static_transform_publisher.cpp)
ament_target_dependencies(static_transform_publisher geometry_msgs rclcpp std_msgs tf2 tf2_ros tutorial_interfaces)

add_executable(client_string src/client_change_string.cpp)
ament_target_dependencies(client_string rclcpp std_msgs tutorial_interfaces)

install(TARGETS
  talker
  talkerandlistner
  server
  stringserver
  static_transform_publisher
  client_string
  DESTINATION lib/${PROJECT_NAME})


install(
    DIRECTORY launch
    DESTINATION share/${PROJECT_NAME})
    
if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ament_lint_auto REQUIRED)

    # the following lines skip linters
  set(ament_cmake_cppcheck_FOUND TRUE)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  set(ament_cmake_flake8_FOUND TRUE)
  set(ament_cmake_uncrustify_FOUND TRUE)
  set(ament_cmake_xmllint_FOUND TRUE)
  set(ament_cmake_lint_cmake_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()

  # # Add gtests
  # ament_add_gtest(server_test test/test_server.cpp)
  # ament_target_dependencies(server_test rclcpp rclcpp_action std_msgs)
  # # rosidl_target_interfaces(server_test ${PROJECT_NAME} "rosidl_typesupport_cpp")
  # rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
  # target_link_libraries(server_test "${cpp_typesupport_target}")

endif()

ament_package()
