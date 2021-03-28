all in one server
it has a fifo from fifo.c
popens pp.c
creates a pipe with child itself writes the data to server
sigsend send the signal to server
the output is redirected to p5.c
which then ouputs the data
