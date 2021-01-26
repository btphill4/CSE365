#declare the variable as CC will tell type of compiler 
CC=g++

CFLAGS=-c -Wall

#this target will compile all the files "make all"
all:  secure_house
	
secure_house: secure_house.cpp 
	$(CC) secure_house.cpp -o secure_house

secure_house.o: secure_house.cpp 
	$(CC) $(CFLAGS) secure_house.cpp 

clean:
	rm -rf *o secure_house 


#this target will compile when "make compile" is executed
#compile:
#	g++ c_program.cpp -o secure_house