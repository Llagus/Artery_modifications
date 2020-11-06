#include <iostream>
#include <string.h>
#include <omnetpp.h>

using namespace omnetpp; 

class Tic9 : public cSimpleModule{
    public: 
        Tic9(); 
        virtual ~Tic9();
    private: 
        int seq; 
        simtime_t timeout; 
        cMessage *timeoutEvent; 
        cMessage *message; 
    protected: 
        virtual void initialize() override; 
        virtual void handleMessage(cMessage *msg) override; 
        virtual cMessage *generateNewMessage();
        virtual void sendCopyOf(cMessage *msg);
};

Define_Module(Tic9);

Tic9::Tic9(){
    message = timeoutEvent = nullptr; 
}

Tic9::~Tic9(){
    cancelAndDelete(timeoutEvent); 
    delete message; 
}

void Tic9::initialize(){
    seq = 0; 
    timeout = 1.0; 
    timeoutEvent = new cMessage("timeoutMsg"); 

    EV << "Sending initialization message\n";
    message = generateNewMessage(); 
    sendCopyOf(message);
    scheduleAt(simTime()+timeout, timeoutEvent); 
}

cMessage *Tic9::generateNewMessage(){
    //Generate messages with a new name every time
    char msgname[20]; 
    sprintf(msgname, "-tic-%d", ++seq);
    cMessage *msg = new cMessage(msgname);
    return msg;
}

void Tic9::sendCopyOf(cMessage *msg){
    //Duplicate the message and send the copy
    cMessage *copy = dynamic_cast<cMessage *>(msg->dup()); 
    send(copy,"out");
}


void Tic9::handleMessage(cMessage *msg){
    if (msg == timeoutEvent){
        EV << "Timeout exceed sending again\n";
        sendCopyOf(message);  
        scheduleAt(simTime()+timeout, timeoutEvent);
    }
    else{
        EV << "Received: " << msg->getName() << "\n"; 
        delete msg; 

        EV << "Timer cancelled\n";
        cancelEvent(timeoutEvent); 
        delete message; 

        //already to generate another one 
        message = generateNewMessage();
        sendCopyOf(message); 
        scheduleAt(simTime()+timeout,timeoutEvent); 
    }
}


class Toc9 : public cSimpleModule{
    protected: 
        virtual void handleMessage(cMessage *msg) override; 
};


Define_Module(Toc9); 

void Toc9::handleMessage(cMessage *msg){
    if(uniform(0,1)<0.1){
        EV << "\"Losing\" message";
        bubble("Message lost :(");
        delete msg; 
    } 
    else{
        EV << "Received, sending back and ack"<< msg->getName()<<endl;
        delete msg; 
        cMessage *ack = new cMessage("tictocAck");
        send(ack, "out");
    }
}
