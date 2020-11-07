#include <iostream>
#include <string.h>
#include <omnetpp.h>
#include "tictoc_ll_14_m.h"

using namespace omnetpp; 

class Txc14 : public cSimpleModule{
    private: 
        long numSent;
        long numReceived; 

    protected: 
        virtual TicTocMsg14 *generateMessage();
        virtual void forwardMessage(TicTocMsg14 *msg); 
        virtual void initialize() override; 
        virtual void handleMessage(cMessage *msg) override; 
        virtual void refreshDisplay() const override;  
};

Define_Module(Txc14); 

void Txc14::initialize(){
    //Iitialize variables 
    numSent = 0; 
    numReceived = 0; 
    WATCH(numSent); 
    WATCH(numReceived); 

    //Module 0 sends the first message
    if(this->getIndex() == 0){
        //Boot the process scheduling the inital message as self-message 
        TicTocMsg14 *msg = generateMessage(); 
        numSent++; 
        scheduleAt(0.0,msg); 
    }
}

void Txc14::handleMessage(cMessage *msg){
    TicTocMsg14 *ttmsg = check_and_cast<TicTocMsg14 *>(msg); 
    if (ttmsg->getDestination() == getIndex()){
        //Message  arrived
        EV << "Message " << msg << " arrived\n";
        numReceived++; 
        bubble("ARRIVED, starting new one!");
        delete msg;  
        

        //Generate another one 
        TicTocMsg14 *newmsg = generateMessage(); 
        EV << newmsg <<endl; 
        forwardMessage(newmsg); 
        numSent++; 
    }
    else {
        //We need to forward the message
        forwardMessage(ttmsg);
    }

}

void Txc14::forwardMessage(TicTocMsg14 *msg){
    //In this example, we just pick a random gate to send it on.
    //We draw a random number between 0 and the size of the gate out[]
    int n = gateSize("gate"); 
    int k = intuniform(0,n-1); 

    EV << "Forwading message " << msg << " on gate[" << k << "]\n";
    // $o and $i suffix is used to identify the input/output part of a two way gate
    send(msg, "gate$o", k); 
}

TicTocMsg14 *Txc14::generateMessage(){
    // Produce source and destination addresses. 
    int src = getIndex(); 
    int n = getVectorSize(); 
    int dest = intuniform (0, n-2); 
    if (dest==src)
        dest++; 
    
    char msgname[20]; 
    sprintf(msgname, "tic-%d-to-%d", src, dest); 

    //Create message object and set source and destination field
    TicTocMsg14 *msg = new TicTocMsg14(msgname); 
    msg->setSource(src);
    msg->setDestination(dest);
    return msg;
}

void Txc14::refreshDisplay() const{
    char buf[40]; 
    sprintf(buf, "rcvd: %ld sent: %ld", numReceived, numSent);
    getDisplayString().setTagArg("t",0,buf);
}