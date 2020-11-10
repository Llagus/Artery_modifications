simple Txc18{
    parameters: 
        @signal[arrival](type="long");
        @statistic[hopCount](title="hop count"; source="arrival"; record=vector,stats; interpolationmode=none);
        @display("i=block/routing,gold");
    gates: 
        inout gate[]; 
}
network Tictoc18{
    parameters: 
        int numCentralNodes = default(2); 
    types: 
        channel Channel extends ned.DelayChannel{
            delay = 100ms;
        }
    submodules:
        tic[numCentralNodes+4]: Txc18;
    connections: 
        //connect the 2 nodes in one side to the central nodes
        tic[0].gate++ <--> Channel <--> tic[2].gate++;
        tic[1].gate++ <--> Channel <--> tic[2].gate++;

        //connect central nodes together
        for i = 2..numCentralNodes+1{
            tic[i].gate++ <--> Channel <--> tic[i+1].gate++; 
        }
        //connect the 2 nodes on the other side to the central nodes
        tic[numCentralNodes+2].gate++ <--> Channel <--> tic[numCentralNodes+1].gate++; 
        tic[numCentralNodes+3].gate++ <--> Channel <--> tic[numCentralNodes+1].gate++; 
}