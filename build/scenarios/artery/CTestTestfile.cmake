# CMake generated Testfile for 
# Source directory: /home/llagus/artery/scenarios/artery
# Build directory: /home/llagus/artery/build/scenarios/artery
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(example-inet "/home/llagus/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/llagus/artery/src/artery:/home/llagus/artery/src/traci:/home/llagus/artery/extern/veins/examples/veins:/home/llagus/artery/extern/veins/src/veins:/home/llagus/artery/extern/inet/src:/home/llagus/artery/extern/inet/examples:/home/llagus/artery/extern/inet/tutorials:/home/llagus/artery/extern/inet/showcases" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/llagus/artery/build/extern/libINET.so" "-l" "/home/llagus/artery/build/extern/libveins.so" "-l" "/home/llagus/artery/build/src/traci/libtraci.so" "-l" "/home/llagus/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cinet" "--sim-time-limit=20s")
set_tests_properties(example-inet PROPERTIES  WORKING_DIRECTORY "/home/llagus/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/llagus/artery/cmake/AddOppRun.cmake;169;add_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;2;add_opp_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-security "/home/llagus/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/llagus/artery/src/artery:/home/llagus/artery/src/traci:/home/llagus/artery/extern/veins/examples/veins:/home/llagus/artery/extern/veins/src/veins:/home/llagus/artery/extern/inet/src:/home/llagus/artery/extern/inet/examples:/home/llagus/artery/extern/inet/tutorials:/home/llagus/artery/extern/inet/showcases" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/llagus/artery/build/extern/libINET.so" "-l" "/home/llagus/artery/build/extern/libveins.so" "-l" "/home/llagus/artery/build/src/traci/libtraci.so" "-l" "/home/llagus/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cinet_security" "--sim-time-limit=20s")
set_tests_properties(example-security PROPERTIES  WORKING_DIRECTORY "/home/llagus/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/llagus/artery/cmake/AddOppRun.cmake;169;add_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;3;add_opp_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-inet-mco "/home/llagus/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/llagus/artery/src/artery:/home/llagus/artery/src/traci:/home/llagus/artery/extern/veins/examples/veins:/home/llagus/artery/extern/veins/src/veins:/home/llagus/artery/extern/inet/src:/home/llagus/artery/extern/inet/examples:/home/llagus/artery/extern/inet/tutorials:/home/llagus/artery/extern/inet/showcases" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/llagus/artery/build/extern/libINET.so" "-l" "/home/llagus/artery/build/extern/libveins.so" "-l" "/home/llagus/artery/build/src/traci/libtraci.so" "-l" "/home/llagus/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cinet_mco" "--sim-time-limit=20s")
set_tests_properties(example-inet-mco PROPERTIES  WORKING_DIRECTORY "/home/llagus/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/llagus/artery/cmake/AddOppRun.cmake;169;add_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;4;add_opp_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-inet-mixed-vehicles "/home/llagus/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/llagus/artery/src/artery:/home/llagus/artery/src/traci:/home/llagus/artery/extern/veins/examples/veins:/home/llagus/artery/extern/veins/src/veins:/home/llagus/artery/extern/inet/src:/home/llagus/artery/extern/inet/examples:/home/llagus/artery/extern/inet/tutorials:/home/llagus/artery/extern/inet/showcases" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/llagus/artery/build/extern/libINET.so" "-l" "/home/llagus/artery/build/extern/libveins.so" "-l" "/home/llagus/artery/build/src/traci/libtraci.so" "-l" "/home/llagus/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cinet_multiple_vehicle_types" "--sim-time-limit=20s")
set_tests_properties(example-inet-mixed-vehicles PROPERTIES  WORKING_DIRECTORY "/home/llagus/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/llagus/artery/cmake/AddOppRun.cmake;169;add_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;5;add_opp_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-inet-nakagami "/home/llagus/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/llagus/artery/src/artery:/home/llagus/artery/src/traci:/home/llagus/artery/extern/veins/examples/veins:/home/llagus/artery/extern/veins/src/veins:/home/llagus/artery/extern/inet/src:/home/llagus/artery/extern/inet/examples:/home/llagus/artery/extern/inet/tutorials:/home/llagus/artery/extern/inet/showcases" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/llagus/artery/build/extern/libINET.so" "-l" "/home/llagus/artery/build/extern/libveins.so" "-l" "/home/llagus/artery/build/src/traci/libtraci.so" "-l" "/home/llagus/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cinet_nakagami" "--sim-time-limit=20s")
set_tests_properties(example-inet-nakagami PROPERTIES  WORKING_DIRECTORY "/home/llagus/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/llagus/artery/cmake/AddOppRun.cmake;169;add_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;6;add_opp_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-inet-rsu "/home/llagus/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/llagus/artery/src/artery:/home/llagus/artery/src/traci:/home/llagus/artery/extern/veins/examples/veins:/home/llagus/artery/extern/veins/src/veins:/home/llagus/artery/extern/inet/src:/home/llagus/artery/extern/inet/examples:/home/llagus/artery/extern/inet/tutorials:/home/llagus/artery/extern/inet/showcases" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/llagus/artery/build/extern/libINET.so" "-l" "/home/llagus/artery/build/extern/libveins.so" "-l" "/home/llagus/artery/build/src/traci/libtraci.so" "-l" "/home/llagus/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cinet_rsu" "--sim-time-limit=20s")
set_tests_properties(example-inet-rsu PROPERTIES  WORKING_DIRECTORY "/home/llagus/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/llagus/artery/cmake/AddOppRun.cmake;169;add_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;7;add_opp_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-veins "/home/llagus/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/llagus/artery/src/artery:/home/llagus/artery/src/traci:/home/llagus/artery/extern/veins/examples/veins:/home/llagus/artery/extern/veins/src/veins:/home/llagus/artery/extern/inet/src:/home/llagus/artery/extern/inet/examples:/home/llagus/artery/extern/inet/tutorials:/home/llagus/artery/extern/inet/showcases" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/llagus/artery/build/extern/libINET.so" "-l" "/home/llagus/artery/build/extern/libveins.so" "-l" "/home/llagus/artery/build/src/traci/libtraci.so" "-l" "/home/llagus/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cveins" "--sim-time-limit=20s")
set_tests_properties(example-veins PROPERTIES  WORKING_DIRECTORY "/home/llagus/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/llagus/artery/cmake/AddOppRun.cmake;169;add_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;8;add_opp_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-veins-rsu "/home/llagus/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/llagus/artery/src/artery:/home/llagus/artery/src/traci:/home/llagus/artery/extern/veins/examples/veins:/home/llagus/artery/extern/veins/src/veins:/home/llagus/artery/extern/inet/src:/home/llagus/artery/extern/inet/examples:/home/llagus/artery/extern/inet/tutorials:/home/llagus/artery/extern/inet/showcases" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/llagus/artery/build/extern/libINET.so" "-l" "/home/llagus/artery/build/extern/libveins.so" "-l" "/home/llagus/artery/build/src/traci/libtraci.so" "-l" "/home/llagus/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cveins_rsu" "--sim-time-limit=20s")
set_tests_properties(example-veins-rsu PROPERTIES  WORKING_DIRECTORY "/home/llagus/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/llagus/artery/cmake/AddOppRun.cmake;169;add_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;9;add_opp_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;0;")
add_test(example-envmod "/home/llagus/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/llagus/artery/src/artery:/home/llagus/artery/src/traci:/home/llagus/artery/extern/veins/examples/veins:/home/llagus/artery/extern/veins/src/veins:/home/llagus/artery/extern/inet/src:/home/llagus/artery/extern/inet/examples:/home/llagus/artery/extern/inet/tutorials:/home/llagus/artery/extern/inet/showcases" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/llagus/artery/build/extern/libINET.so" "-l" "/home/llagus/artery/build/extern/libveins.so" "-l" "/home/llagus/artery/build/src/traci/libtraci.so" "-l" "/home/llagus/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cenvmod" "--sim-time-limit=20s")
set_tests_properties(example-envmod PROPERTIES  WORKING_DIRECTORY "/home/llagus/artery/scenarios/artery" _BACKTRACE_TRIPLES "/home/llagus/artery/cmake/AddOppRun.cmake;169;add_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;12;add_opp_test;/home/llagus/artery/scenarios/artery/CMakeLists.txt;0;")
