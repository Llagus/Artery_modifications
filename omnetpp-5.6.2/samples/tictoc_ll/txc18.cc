#include <iostream>
#include <string.h>
#include <omnetpp.h>
#include "tictoc_ll_18_m.h"

using namespace omnetpp; 

class Txc18 : public cSimpleModule {
    private: 
        simsignal_t arrivalSignal;
    protected: 
        virtual TicTocMsg18 *generateMessage(); 
        virtual void forwardMessage(TicTocMsg18 *msg); 
        virtual void initialize() override; 
        virtual void handleMessage(cMessage *msg) override; 
};

Define_Module(Txc18);

void Txc18::initialize(){
    arrivalSignal = registerSignal("arrival");
    //Module 0  sends the first message
    if (getIndex() == 0){
            //Boot the process scheduling the initial message as a self-message
            TicTocMsg18 *msg = generateMessage();
            scheduleAt(0.0,msg);
    }
}

void Txc18::handleMessage(cMessage *msg){
    //cast the cMessage to TicTocMsg18
    TicTocMsg18 *ttmsg = dynamic_cast<TicTocMsg18 *>(msg);

    if (ttmsg->getDestination() == getIndex()){
        //Message arrived
        int hopCount = ttmsg->getHopCount(); 
        //send a signal
        emit(arrivalSignal, hopCount); 

        EV << "Message " << ttmsg << " arrived after " << hopCount << " hops.\n";
        bubble("ARRIVED, starting a new one!");

        delete ttmsg; 

        //Generate new message
        TicTocMsg18 *newmsg = generateMessage();
        EV << newmsg << endl;
        forwardMessage(newmsg);
    } 
    else {
        //We need to forward the message
        forwardMessage(ttmsg); 
    }
}

TicTocMsg18 *Txc18::generateMessage(){
    //Produce source and destination addresses
    int src = getIndex();
    int n = getVectorSize(); 
    int dest = intuniform(0, n-2); 
    if (dest>= src) dest++; 

    char msgname[20];
    sprintf(msgname, "tic-%d-to%d",src,dest);
    TicTocMsg18 *msg = new TicTocMsg18(msgname);
    msg->setSource(src);
    msg->setDestination(dest);
    return msg; 
}

void Txc18::forwardMessage(TicTocMsg18 *msg){
    //increment hop count
    msg->setHopCount(msg->getHopCount()+1);

    //Same routing as before: random gate
    int n = gateSize("gate"); 
    int k = intuniform(0, n-1); 

    EV << "Foewarding message " << msg << " on gate[" << k << "]\n";
    send(msg, "gate$o", k);
}
