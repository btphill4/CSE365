
    Once all documents are entered into the same directory, To set up and run the program:
	To compile, type command : 'make'
	To begin the program, type command: ./secure_house <nameOfOwner> <key1> <key2> ... <keyn> 
	If we would like to run the program allowing a file to enter command line arguments, begin command with: ./secure_house <nameOfOwner> <key1> <key2> ... <keyn> < <inputFile>
	
	-The program allows guests to enter a key using "INSERT KEY <guestName> <key>". 
	-If the key is found in the accepted key list, the guest will have permission to enter.
	-The guest may then enter the house with the command "ENTER HOUSE <guestName>. 
	-If the key was found to be in the accepted list, the guest will be allowed entry. 
	-If the guest does not enter the house immediately after inserting the key, they must re-enter the key before being allowed entry. 
	-To see people in the house, use command "WHO'S INSIDE?". 
	-For a guest to leave the house run the command "LEAVE HOUSE <guestName>". 
	-If the guest is in the house, their name will be removed from the list of guests inside the house. 
	-If the guest name is not inside the house, the program will notify the user that the guest is not in the house. 
	-Command "CHANGE LOCKS <ownerName> <key1> <key2> .. <keyn>" can be used to change the accepted keys for the house 
	-Enter command "EXIT" to end the program

	To summarize, here is the list of available commands once the program has been initiated:

	INSERT KEY <guestName> <keyUsedByGuest>
	ENTER HOUSE <guestName>
	WHO'S INSIDE?
	LEAVE HOUSE <guestName>
	CHANGE LOCKS <ownerName> <key1> <key2> ... <keyn>
	EXIT	
