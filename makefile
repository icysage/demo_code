# this is an example makefile file
# that uses variables to make
# it easier to change commands.
CC = g++
CFLAGS = -g -Wall -std=c++11  
OBJECTS = main.o reading.o
HEADERS = main.h reading.h

main: $(OBJECTS) $(HEADERS)
	 $(CC) $(OBJECTS) -o main 
 
# this will, if given a .o file to re-compile
# will compile the corresponding .cpp file 
%.o: %.cpp
	$(CC) -c  $(CFLAGS) $< 

clean:
	rm *.o main
