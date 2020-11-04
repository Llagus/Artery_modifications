simple Txc4{
    parameters: 
        bool sendMsgOnInit = default(false); // whether the module should send out a message on initialization
        int limit = default(2); // another parameter with a default value
        @display("i=block/routing");//add a default icon
    
    gates: 
        input in; 
        output out; 
}

network Tictoc4{
    submodules:
        tic: Txc4 {
            parameters: 
                @display("i=,cyan"); // do not cahnge de icon (first arg of i==) just the color
                sendMsgOnInit = true; 
        }
        toc: Txc4{
            parameters:
                @display("i=,gold");//here too
                sendMsgOnInit = false; 
        }
    connections:
        tic.out-->{ delay = 100ms; }-->toc.in;
        tic.in<--{ delay = 100ms; }<--toc.out;
}