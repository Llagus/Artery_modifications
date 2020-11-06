simple Tic9{
    parameters: 
        @display("i=block/routing,cyan");
        
    gates: 
        input in; 
        output out; 
}

simple Toc9 {
    parameters: 
        @display("i=block/routing,gold"); 
    
    gates: 
        input in; 
        output out; 
}

network Tictoc9{
    submodules: 
        tic: Tic9;
        toc: Toc9; 
    connections: 
        tic.out-->{delay=100ms;}-->toc.in;
        tic.in<--{delay=100ms;}<--toc.out; 
}