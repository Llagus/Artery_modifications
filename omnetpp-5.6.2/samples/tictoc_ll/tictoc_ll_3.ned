simple Txc3{
    parameters: 
        @display("i=block/routing");//add a default icon
    
    gates: 
        input in; 
        output out; 
}

network Tictoc3{
    submodules:
        tic: Txc3 {
            parameters: 
                @display("i=,cyan"); // do not cahnge de icon (first arg of i==) just the color
        }
        toc: Txc3{
            parameters:
                @display("i=,gold");//here too
        }
    connections:
        tic.out-->{ delay = 100ms; }-->toc.in;
        tic.in<--{ delay = 100ms; }<--toc.out;
}