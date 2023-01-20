%.o: %.cpp
	g++ -c -o -O2 $@ $<
%.o: %.cc
	g++ -c -o -O2 $@ $<

stdinServer: stdinServer.o connect.o
	g++ -o stdinServer -O2 stdinServer.o connect.o

connect.o: connect.cpp
stdinServer.o: stdinServer.cc
