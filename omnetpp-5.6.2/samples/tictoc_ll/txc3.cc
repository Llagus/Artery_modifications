#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Txc3: public cSimpleModule{
    protected:
        virtual void initialize() override; 
        virtual void handleMessage(cMessage *msg) override;
    private: 
        int counter; //Note the counter here; 
};

Define_Module(Txc3); 

void Txc3::initialize(){
    counter = 10; 

    WATCH(counter); 
    if(strcmp("tic",getName()) == 0){
        cMessage *msg = new cMessage("tictocMsg");
        EV << "Sending first tictoc message\n";
        send(msg,"out");  
    }
}

void Txc3::handleMessage(cMessage *msg){
    counter --; 
    if (counter == 0){
        EV << getName() << "'s counter reached zero, deleting message\n";
        delete msg; 
    }else{
        EV << "Received message '" << msg->getName() << "', sending the messaage out again\n";
        send(msg,"out");
    }
}