#include <iostream>
#include <omnetpp.h>
#include <string.h>
#include "tictoc_ll_15_m.h"

using namespace omnetpp; 

class Txc15 : public cSimpleModule{
    private: 
        long numSent;
        long numReceived;
        cHistogram hopCountStats; 
        cOutVector hopCountVector;  

    protected: 
        virtual TicTocMsg15 *generateMessage();
        virtual void forwardMessage(TicTocMsg15 *msg); 
        virtual void initialize() override; 
        virtual void handleMessage(cMessage *msg) override;  
        virtual void finish() override; 
};

Define_Module(Txc15); 

void Txc15::initialize(){
    //Iitialize variables 
    numSent = 0; 
    numReceived = 0; 
    WATCH(numSent); 
    WATCH(numReceived); 

    hopCountStats.setName("hopCountstats");
    hopCountVector.setName("HopCount");  

    //Module 0 sends the first message
    if(this->getIndex() == 0){
        //Boot the process scheduling the inital message as self-message 
        TicTocMsg15 *msg = generateMessage(); 
        numSent++; 
        scheduleAt(0.0,msg); 
    }
}

void Txc15::handleMessage(cMessage *msg){
    TicTocMsg15 *ttmsg = check_and_cast<TicTocMsg15 *>(msg); 
    if (ttmsg->getDestination() == getIndex()){
        //Message  arrived
        int hopcount = ttmsg->getHopCount(); 
        EV << "Message " << ttmsg << " arrived\n";
        numReceived++; 
        hopCountVector.record(hopcount); 
        hopCountStats.collect(hopcount);
        bubble("ARRIVED, starting new one!");
        delete ttmsg;  
        

        //Generate another one 
        TicTocMsg15 *newmsg = generateMessage(); 
        EV << newmsg <<endl; 
        forwardMessage(newmsg); 
        numSent++; 
    }
    else {
        //We need to forward the message
        forwardMessage(ttmsg);
    }

}

void Txc15::forwardMessage(TicTocMsg15 *msg){
    //Increment hop count
    msg->setHopCount(msg->getHopCount() +1);
    //In this example, we just pick a random gate to send it on.
    //We draw a random number between 0 and the size of the gate out[]
    int n = gateSize("gate"); 
    int k = intuniform(0,n-1); 

    EV << "Forwading message " << msg << " on gate[" << k << "]\n";
    // $o and $i suffix is used to identify the input/output part of a two way gate
    send(msg, "gate$o", k); 
}

TicTocMsg15 *Txc15::generateMessage(){
    // Produce source and destination addresses. 
    int src = getIndex(); 
    int n = getVectorSize(); 
    int dest = intuniform (0, n-2); 
    if (dest==src)
        dest++; 
    
    char msgname[20]; 
    sprintf(msgname, "tic-%d-to-%d", src, dest); 

    //Create message object and set source and destination field
    TicTocMsg15 *msg = new TicTocMsg15(msgname); 
    msg->setSource(src);
    msg->setDestination(dest);
    return msg;
}

void Txc15::finish() {
    //This function is called by OMNET++ at the end of the simulation
    EV << "Sent:    "<< numSent <<endl;
    EV <<"Received: "<< numReceived <<endl; 
    EV <<"Hop count, min:   "<< hopCountStats.getMin()<<endl;
    EV <<"Hop count, max:   "<< hopCountStats.getMax()<<endl;
    EV <<"Hop count, mean:  "<< hopCountStats.getMean()<<endl;
    EV <<"Hop count, stddev:"<< hopCountStats.getStddev()<<endl; 

    recordScalar("#sent", numSent); 
    recordScalar("#received", numReceived); 

    hopCountStats.recordAs("hop count");
}