# CMake generated Testfile for 
# Source directory: /home/chotu/Beginner_Tutorials_Ros2/src/serverpublisher
# Build directory: /home/chotu/Beginner_Tutorials_Ros2/build/serverpublisher
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(pep257 "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/chotu/Beginner_Tutorials_Ros2/build/serverpublisher/test_results/serverpublisher/pep257.xunit.xml" "--package-name" "serverpublisher" "--output-file" "/home/chotu/Beginner_Tutorials_Ros2/build/serverpublisher/ament_pep257/pep257.txt" "--command" "/opt/ros/humble/bin/ament_pep257" "--xunit-file" "/home/chotu/Beginner_Tutorials_Ros2/build/serverpublisher/test_results/serverpublisher/pep257.xunit.xml")
set_tests_properties(pep257 PROPERTIES  LABELS "pep257;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/chotu/Beginner_Tutorials_Ros2/src/serverpublisher" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_pep257/cmake/ament_pep257.cmake;41;ament_add_test;/opt/ros/humble/share/ament_cmake_pep257/cmake/ament_cmake_pep257_lint_hook.cmake;18;ament_pep257;/opt/ros/humble/share/ament_cmake_pep257/cmake/ament_cmake_pep257_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/chotu/Beginner_Tutorials_Ros2/src/serverpublisher/CMakeLists.txt;75;ament_package;/home/chotu/Beginner_Tutorials_Ros2/src/serverpublisher/CMakeLists.txt;0;")
add_test(clang_format "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/chotu/Beginner_Tutorials_Ros2/build/serverpublisher/test_results/serverpublisher/clang_format.xunit.xml" "--package-name" "serverpublisher" "--output-file" "/home/chotu/Beginner_Tutorials_Ros2/build/serverpublisher/ament_clang_format/clang_format.txt" "--command" "/opt/ros/humble/bin/ament_clang_format" "--xunit-file" "/home/chotu/Beginner_Tutorials_Ros2/build/serverpublisher/test_results/serverpublisher/clang_format.xunit.xml")
set_tests_properties(clang_format PROPERTIES  LABELS "clang_format;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/chotu/Beginner_Tutorials_Ros2/src/serverpublisher" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_clang_format/cmake/ament_clang_format.cmake;57;ament_add_test;/opt/ros/humble/share/ament_cmake_clang_format/cmake/ament_cmake_clang_format_lint_hook.cmake;27;ament_clang_format;/opt/ros/humble/share/ament_cmake_clang_format/cmake/ament_cmake_clang_format_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/chotu/Beginner_Tutorials_Ros2/src/serverpublisher/CMakeLists.txt;75;ament_package;/home/chotu/Beginner_Tutorials_Ros2/src/serverpublisher/CMakeLists.txt;0;")