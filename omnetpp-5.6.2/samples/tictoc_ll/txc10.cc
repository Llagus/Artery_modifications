#include <iostream>
#include <string.h>
#include <omnetpp.h>

using namespace omnetpp; 

class Txc10 : public cSimpleModule{
    protected: 
        virtual void forwardMessage(cMessage *msg); 
        virtual void initialize() override; 
        virtual void handleMessage(cMessage *msg) override; 
};

Define_Module(Txc10); 

void Txc10::forwardMessage(cMessage *msg){
    //In this example, we just pick a random gate to send it on.
    //We draw a random number between 0 and the size of the gate out[]
    int n = gateSize("out"); 
    int k = intuniform(0,n-1); 

    EV << "Forwading message " << msg << " on a port out[" << k << "]\n";
    send(msg, "out", k); 
}

void Txc10::initialize(){
    if(this->getIndex() == 0){
        //Boot the process scheduling the inital message as self-message 
        char msgname[20]; 
        sprintf(msgname, "tic-%d", getIndex()); 
        cMessage *msg = new cMessage ("msgname"); 
        scheduleAt(0.0,msg); 
    }
}

void Txc10::handleMessage(cMessage *msg){
    if (this->getIndex() == 3){
        //Message  arrived
        EV << "Message " << msg << " arrived\n";
        delete msg;  
    }
    else {
        //We need to forward the message
        forwardMessage(msg);
    }

}