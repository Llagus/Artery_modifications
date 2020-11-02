# CMake generated Testfile for 
# Source directory: /home/llagus/artery/scenarios
# Build directory: /home/llagus/artery/build/scenarios
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(mtits2017-test "/home/llagus/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/llagus/artery/src/artery:/home/llagus/artery/src/traci:/home/llagus/artery/extern/veins/examples/veins:/home/llagus/artery/extern/veins/src/veins:/home/llagus/artery/extern/inet/src:/home/llagus/artery/extern/inet/examples:/home/llagus/artery/extern/inet/tutorials:/home/llagus/artery/extern/inet/showcases" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/scenarios/highway-police/libartery_police.so" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/llagus/artery/build/extern/libINET.so" "-l" "/home/llagus/artery/build/extern/libveins.so" "-l" "/home/llagus/artery/build/src/traci/libtraci.so" "-l" "/home/llagus/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "--sim-time-limit=30s")
set_tests_properties(mtits2017-test PROPERTIES  WORKING_DIRECTORY "/home/llagus/artery/scenarios/mt-its2017" _BACKTRACE_TRIPLES "/home/llagus/artery/cmake/AddOppRun.cmake;169;add_test;/home/llagus/artery/scenarios/CMakeLists.txt;23;add_opp_test;/home/llagus/artery/scenarios/CMakeLists.txt;0;")
add_test(car2car-grid-cam_bsp "/home/llagus/artery/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/llagus/artery/src/artery:/home/llagus/artery/src/traci:/home/llagus/artery/extern/veins/examples/veins:/home/llagus/artery/extern/veins/src/veins:/home/llagus/artery/extern/inet/src:/home/llagus/artery/extern/inet/examples:/home/llagus/artery/extern/inet/tutorials:/home/llagus/artery/extern/inet/showcases" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/scenarios/highway-police/libartery_police.so" "-l" "/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/llagus/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/llagus/artery/build/extern/libINET.so" "-l" "/home/llagus/artery/build/extern/libveins.so" "-l" "/home/llagus/artery/build/src/traci/libtraci.so" "-l" "/home/llagus/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-ccam_bsp" "--sim-time-limit=30s")
set_tests_properties(car2car-grid-cam_bsp PROPERTIES  WORKING_DIRECTORY "/home/llagus/artery/scenarios/car2car-grid" _BACKTRACE_TRIPLES "/home/llagus/artery/cmake/AddOppRun.cmake;169;add_test;/home/llagus/artery/scenarios/CMakeLists.txt;39;add_opp_test;/home/llagus/artery/scenarios/CMakeLists.txt;0;")
subdirs("artery")
subdirs("gemv2")
subdirs("highway-police")
subdirs("rsu_grid")
subdirs("storyboard")
