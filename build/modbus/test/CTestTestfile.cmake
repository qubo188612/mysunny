# CMake generated Testfile for 
# Source directory: /home/qubo/mysunny/src/modbus/test
# Build directory: /home/qubo/mysunny/build/modbus/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(server_client "sh" "-c" "/home/qubo/mysunny/build/modbus/test/server& sleep 5; /home/qubo/mysunny/build/modbus/test/client; wait \$!")
set_tests_properties(server_client PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/home/qubo/mysunny/src/modbus/test/CMakeLists.txt;13;add_test;/home/qubo/mysunny/src/modbus/test/CMakeLists.txt;0;")
add_test(bandwidth "sh" "-c" "/home/qubo/mysunny/build/modbus/test/bandwidth-server& sleep 5; /home/qubo/mysunny/build/modbus/test/bandwidth-client; wait \$!")
set_tests_properties(bandwidth PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/home/qubo/mysunny/src/modbus/test/CMakeLists.txt;18;add_test;/home/qubo/mysunny/src/modbus/test/CMakeLists.txt;0;")
