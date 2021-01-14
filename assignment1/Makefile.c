/*MakeFile example

#target: dependency1 dependency2 ...
#	<tab> command

#NOTE: remember to add the TAB character before the command part

#Typing 'make' will invoke the first target entry in the file

#declare the variable as CC will tell type of compiler */
CC=g++

CFLAGS=-c -Wall

#this target will compile all the files "make all"
all:  c_program
	
c_program: c_program.c 
	$(CC) c_program.c  -o c_program

c_program.o: c_program.c 
	$(CC) $(CFLAGS) c_program.c 

clean:
	rm -rf *o c_program 


#this target will compile when "make compile" is executed
#compile:
#	g++ c_program.c -o assignment1
