simple Txc6{
    parameters:
        bool sendMsgOnInit = default(false); 
        int limit = default(3);
        @display("i=block/routing"); 
    gates: 
        input in; 
        output out;
}

simple Tic6 extends Txc6{
    parameters: 
        @display("i=,cyan");
        sendMsgOnInit = true; 

}

simple Toc6 extends Txc6{
    parameters: 
        @display("i=, gold"); 
        limit = 5; 
}

network Tictoc6{
    submodules:
        tic: Tic6; 
        toc: Toc6; 
    connections: 
        tic.out-->{ delay = 100ms; }-->toc.in;
        tic.in<--{ delay = 100ms; }<--toc.out; 
}