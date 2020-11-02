#!/bin/bash
OPP_RUN=/home/llagus/artery/omnetpp-5.6.2/bin/opp_run_dbg
NED_FOLDERS="/home/llagus/artery/src/artery:/home/llagus/artery/src/traci:/home/llagus/artery/extern/veins/examples/veins:/home/llagus/artery/extern/veins/src/veins:/home/llagus/artery/extern/inet/src:/home/llagus/artery/extern/inet/examples:/home/llagus/artery/extern/inet/tutorials:/home/llagus/artery/extern/inet/showcases"
LIBRARIES="-l/home/llagus/artery/build/src/artery/libartery_core.so -l/home/llagus/artery/build/src/traci/libtraci.so -l/home/llagus/artery/build/extern/libveins.so -l/home/llagus/artery/build/extern/libINET.so -l/home/llagus/artery/build/src/artery/storyboard/libartery_storyboard.so -l/home/llagus/artery/build/src/artery/envmod/libartery_envmod.so"

$OPP_RUN -n $NED_FOLDERS $LIBRARIES $@
