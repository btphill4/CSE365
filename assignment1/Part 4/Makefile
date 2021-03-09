#MakeFile example

#target: dependency1 dependency2 ...
#	<tab> command

#NOTE: remember to add the TAB character before the command part

#Typing 'make' will invoke the first target entry in the file

#declare the variable as CC will tell type of compiler 
CC=g++

CFLAGS=-c -Wall

#this target will compile all the files "make all"
all:  command
	
command: command.cpp 
	$(CC) command.cpp -o command

command.o: command.cpp 
	$(CC) $(CFLAGS) command.cpp 

clean:
	rm -rf *o command 


#this target will compile when "make compile" is executed
#compile:
#	g++ c_program.cpp -o command