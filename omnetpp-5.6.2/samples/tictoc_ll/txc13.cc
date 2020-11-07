#include <iostream>
#include <string.h>
#include <omnetpp.h>
#include "tictoc_ll_13_m.h"

using namespace omnetpp; 

class Txc13 : public cSimpleModule{
    protected: 
        virtual TicTocMsg13 *generateMessage();
        virtual void forwardMessage(TicTocMsg13 *msg); 
        virtual void initialize() override; 
        virtual void handleMessage(cMessage *msg) override; 
};

Define_Module(Txc13); 

void Txc13::forwardMessage(TicTocMsg13 *msg){
    //In this example, we just pick a random gate to send it on.
    //We draw a random number between 0 and the size of the gate out[]
    int n = gateSize("gate"); 
    int k = intuniform(0,n-1); 

    EV << "Forwading message " << msg << " on gate[" << k << "]\n";
    // $o and $i suffix is used to identify the input/output part of a two way gate
    send(msg, "gate$o", k); 
}

void Txc13::initialize(){
    if(this->getIndex() == 0){
        //Boot the process scheduling the inital message as self-message 
        TicTocMsg13 *msg = generateMessage(); 
        scheduleAt(0.0,msg); 
    }
}

void Txc13::handleMessage(cMessage *msg){
    TicTocMsg13 *ttmsg = check_and_cast<TicTocMsg13 *>(msg); 
    if (ttmsg->getDestination() == getIndex()){
        //Message  arrived
        EV << "Message " << msg << " arrived\n";
        bubble("ARRIVED, starting new one!");
        delete msg;  

        //Generate another one 
        TicTocMsg13 *newmsg = generateMessage(); 
        EV << newmsg <<endl; 
        forwardMessage(newmsg); 
    }
    else {
        //We need to forward the message
        forwardMessage(ttmsg);
    }

}

TicTocMsg13 *Txc13::generateMessage(){
    // Produce source and destination addresses. 
    int src = getIndex(); 
    int n = getVectorSize(); 
    int dest = intuniform (0, n-2); 
    if (dest==src)
        dest++; 
    
    char msgname[20]; 
    sprintf(msgname, "tic-%d-to-%d", src, dest); 

    //Create message object and set source and destination field
    TicTocMsg13 *msg = new TicTocMsg13(msgname); 
    msg->setSource(src);
    msg->setDestination(dest);
    return msg;
}