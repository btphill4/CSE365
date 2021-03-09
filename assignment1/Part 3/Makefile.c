cc = gcc 
all: c_program

c_program: c_program.c 
	$(CC) c_program.c -o c_program

c_program.o: c_program.c
	$(CC) $(CFLAGS) c_program.c
    
clean:
	rm -rf *o c_program 
