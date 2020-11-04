simple Txc5{
    parameters: 
        bool sendMsgOnInit = default(false); // whether the module should send out a message on initialization
        int limit = default(2); // another parameter with a default value
        @display("i=block/routing");//add a default icon
    
    gates: 
        input in; 
        output out; 
}

simple Tic5 extends Txc5{
    parameters: 
        @display("i=,cyan"); 
        sendMsgOnInit = true; 
}

simple Toc5 extends Txc5{
    parameters:
        @display("i=,gold");
        sendMsgOnInit = false;  
        
}

network Tictoc5{
    submodules:
        tic: Tic5;
        toc: Toc5;
    connections:
        tic.out-->{ delay = 100ms; }-->toc.in;
        tic.in<--{ delay = 100ms; }<--toc.out;
}