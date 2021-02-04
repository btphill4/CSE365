#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include "people.h"
#include "houseKeys.h"

using namespace std;

//creates a keys pointer vector of type houseKeys to store key variables
houseKeys *keys = new houseKeys(); 

//Save terminal commands to a vector to manipulate
string commandToVector(vector<string> tempVector)
 {
  string toReturn;
  if(tempVector[0] == "EXIT") //EXIT command will quit the program
   {
    toReturn = "EXIT";
    return toReturn;
   }
  else
   {
    toReturn = tempVector[0] + tempVector[1]; //All commands other than exit are two strings
    return toReturn;
   }
 }

//gets the input and inputs it into a vector string
vector<string> parseInput(string inputCommand)
 {
  string temp;
  stringstream ss(inputCommand);
  vector<string> parsedInput;
  while(ss >> temp)
   {
    parsedInput.push_back(temp);
   }  
  return parsedInput; 
}

//finds the key from user input
string findKey(vector<string> tempKeyVector, int x)
 {
  if(x == 0) 
  {
   for(int i=3; i<tempKeyVector.size();i++)
    {
     keys->addKey(tempKeyVector[i]);
    }
   return "Added";
   }
  else //Used to simply return the name of the key a person enters
  {
  string toReturn = tempKeyVector[3]; 
  return toReturn;
  }
 }

//finds the persons name
string findName(vector<string> tempNameVector)
 {
  string toReturn = tempNameVector[2];
  return toReturn;
 }


int main(int argc, char* argv[])
{
    if(argc <= 2) //Error if no key is provided
    {
        cout << "ERROR" << endl;
    }

    string owner = argv[1];
    string finalCommand;
    string name;
    string keyName;  
    people *person = new people();
    keys->addKey("FIREFIGHTER_SECRET_KEY");
    for(int i=2; i<argc; i++)
    {
        keys->addKey(argv[i]);
    }

    string inLine;
    
    getline(cin,inLine);
    
    //saves user input to a string vector
    vector<string> command = parseInput(inLine);
    
    //used to compare actions in if statements
    finalCommand = commandToVector(command); 

    //Used to manually exit the program
    int exit = 0; 
    if(finalCommand == "EXIT")
    {
        exit = 1;
    }
    
    //used in while loop
    bool found = false; 
    string toEnter;

   while(exit == 0)
    {
        //insert command
        if(finalCommand == "INSERTKEY")
        {
            name = findName(command);
            keyName = findKey(command,1);
            cout << "KEY " << keyName << " INSERTED BY " << name  << endl;
            
        }
        //TURN KEY <user_name>
        else if(finalCommand == "TURNKEY")
        {
            //search for key
            found = keys->lookForKey(keyName,0);
            if(found == true)
            {
                cout << "SUCCESS " << name << " TURNS KEY " << keyName << endl;
                toEnter = name;
            }
            else
            {
                cout << "FAILURE " << name << " UNABLE TO TURN KEY " << keyName << endl;
            }
            
        }

        //ENTER HOUSE <username>
        else if(finalCommand == "ENTERHOUSE")
            {
            name = findName(command);
            if(found == true)
                {
                found = false;
                if(name == toEnter)
                {
                    cout << "ACCESS ALLOWED" << endl;
                    person->addPerson(toEnter);
                }
                else
                {
                    cout << "ACCESS DENIED" << endl;
                }
                }  	
            else
                {
                cout << "ACCESS DENIED" << endl;
                }
            } 

        //WHO'S INSIDE?
        else if(finalCommand == "WHO'SINSIDE?")
        {
            person->printHouse(); 
        }

        //LEAVE HOUSE <user_name>
        else if(finalCommand == "LEAVEHOUSE")
        { 
            name = findName(command);
            bool success =  person->personSearch(name,1);
            if(success)
                {
                cout << "OK" << endl; 
                }	
            else
                {
                cout << name << " NOT HERE" << endl;
                }
        }

        //CHANGE LOCKS <user_name> <key_1> <key_2> ... <key_n>
        else if (finalCommand == "CHANGELOCKS")
        {
            name = findName(command);
            if(name != owner)
                {
                cout << "ACCESS DENIED" << endl;
                } 	    
            else if(person->personSearch(owner,0) == false)
                {
                cout << "ACCESS DENIED" << endl;
                }
            else if(person->personSearch(owner,0) == true)
                {
                keys->deleteKeys();
                keyName = findKey(command,0);
                cout << "OK" << endl;
                }
            else
                {
                cout << "ACCESS DENIED" << endl;
                }
        }

        //EXIT to manually exit the program
        else if(finalCommand == "EXIT")
        {
            // exits program
        } 
        else
        {
            cout << "ERROR" << endl;
        } 
        if(!(getline(cin,inLine)))
        {
            exit = 1;
        }
        //exits program
        if(inLine == "")
        {
            exit = 1;
        }

        else
        {
            command = parseInput(inLine);
            finalCommand = commandToVector(command);
            //exits program
            if(finalCommand == "EXIT")
            {
            exit = 1;
            }
        }
    }
}
