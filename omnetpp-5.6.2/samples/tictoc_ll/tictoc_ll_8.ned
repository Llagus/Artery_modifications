simple Tic8 {
    parameters: 
        @display("i=block/routing");
        @display("i=,cyan"); 

    gates: 
        input in; 
        output out; 
}


simple Toc8 {
    parameters: 
        @display("i=block/routing");
        @display("i=,gold"); 

    gates: 
        input in; 
        output out;
}


network Tictoc8{
    submodules: 
        tic: Tic8; 
        toc: Toc8; 
    connections: 
        tic.out-->{ delay = 100ms; }-->toc.in;
        tic.in<--{ delay = 100ms; }<--toc.out; 
}
