#include <iostream>
#include <omnetpp.h>
#include <string.h>

using namespace omnetpp; 

class Txc7 : public cSimpleModule{
    public: 
        Txc7();
        virtual ~Txc7();

    private:
        cMessage *event; 
        cMessage *tictocMsg; 

    protected: 
        virtual void initialize() override; 
        virtual void handleMessage(cMessage *msg) override; 
};


Define_Module(Txc7); 


Txc7::Txc7(){
    event = tictocMsg = nullptr;  
}


Txc7::~Txc7(){
    cancelAndDelete(event);
    delete tictocMsg; 
}


void Txc7::initialize(){
    event = new cMessage("event"); 
    tictocMsg=nullptr; 
    if(par("sendMsgOnInit").boolValue()){
        EV << "Scheduling first send at t=5.0\n";
        scheduleAt(5.0,event); 
        tictocMsg = new cMessage("tictocMsg"); 
    } 
}


void Txc7::handleMessage(cMessage *msg){
    if (msg == event){
        EV << "Wait period is over, sending back message\n";
        send(tictocMsg,"out"); 
        tictocMsg=nullptr; 
    }
    else {
        //lose the message with 0.1 probability: 
        if(uniform(0,1)<0.1){
            EV << "\"Losing\"message\n";
            delete msg; 
        }
        else {
            simtime_t delay = par("delayTime");
            
            EV << "Message arrived, starting to wait " << delay << " secs...\n";
            tictocMsg = msg;
            scheduleAt(simTime()+delay, event);
        }
    }
}