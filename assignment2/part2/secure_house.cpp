#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <vector> 
#include <string>      
#include "houseKeys.h"
#include "people.h"

using namespace std;

/** 
Given input:
INSERT KEY adam key
TURN KEY adam
ENTER HOUSE adam
INSERT KEY pat foobar
TURN KEY pat
ENTER HOUSE pat
WHO'S INSIDE?

Given output: 
KEY key INSERTED BY adam
FAILURE adam UNABLE TO TURN KEY key
ACCESS DENIED
KEY foobar INSERTED BY pat
SUCCESS pat TURNS KEY foobar
ACCESS ALLOWED
pat
*/

//key vector
houseKeys *keys = new houseKeys(); 

//get name for insert method
string getName(vector<string> currName)
 {
  string toReturn = currName[2];
  return toReturn;
 }

 //get key Method and add to key vector
string getKey(vector<string> currKey, int x)
 {
  if(x == 0) //Used in conjunction with CHANGE LOCKS command to add new keys
  {
   for(int i=3; i<currKey.size();i++)
    {
     keys->addKey(currKey[i]);
    }
   return "Added";
   }
  else //Used to simply return the name of the key a guest enters
  {
  string toReturn = currKey[3]; 
  return toReturn;
  }
 }

//returns the actions in the command
string getAction(vector<string> currAction)
{
    string toReturn;
    if(currAction[0] == "EXIT")
    {
        toReturn = "EXIT";
        return toReturn;
    }
    else
    {
        toReturn = currAction[0] + currAction[1];
        return toReturn;
    }
}

 //read the input and parse it to a string vector
 vector<string> inputToVector(string userInput)
 {
    string temp;
    stringstream sStream(userInput);
    vector<string> inputVector;
    while(sStream >> temp)
    {
        inputVector.push_back(temp);
    }
    return inputVector;
 }

int main(int argc, char* argv[])
{   
    //no keys entered error
    if(argc <= 2)
    {
        cout << "ERROR" << endl;
    }

    //vector variables
    people *home = new people();

    ///People variables
    string owner;// = argv[1];
    string pKey;
    string name;
    string fireFighterKey = "FIREFIGHTER_SECRET_KEY";

    //code variables
    string line;
    int result = 0;
    string lastCommand;
    
    //initialize house owner and keys
    //./secure_house selina foobar 
    for(int i = 2; i <= argc; i++)
    {
        keys -> addKey(argv[i]);
    }
    keys->addKey("FIREFIGHTER_SECRET_KEY");


    vector<string> command = inputToVector(line);

    lastCommand = getAction(command);
    int stop = 0; //stop command for terminal
    if(lastCommand == "EXIT")
    {
        stop = 1;
    }

    bool found = false; //boolean to check keys

    string toEnter;

    while(stop == 0)
    {
        //insert key command
        if(lastCommand == "INSERT")
        {
            name = getName(command);
            pKey = getKey(command,1);

            //Insert key output KEY key INSERTED BY adam
            cout <<"KEY " << pKey << " INSERTED BY " << name;
        
            
        }

        //TURN KEY <user_name>
        else if(lastCommand == "TURN")
        {
            //name = getName(command);
            //pKey = getKey(command,1);

            //search for key
            found = keys->findKey(pKey,0);

            //if found sets to toEnter to name of person
            if(found == true)
            {
                toEnter = name;
            }

            if(found == true)
            {
                found = false;
                if(name == toEnter)
                {
                    //add name to home vector
                    cout << "SUCCESS " << name << "TURNS KEY " << pKey << endl;
                    //home->addPeople(toEnter);
                }
                //access denied if you were not the last person to insert a key
                else
                {
                    cout << "ACCESS DENIED" << endl;
                }
            }
            //access denied if key is not found
            else
            {
                cout << "ACCESS DENIED" << endl;
            }
        }

        //ENTER HOUSE <username>
        else if(lastCommand == "ENTER")
        {
            name = getName(command);
            if(name == toEnter)
            {
                cout << "ACCESS ALLOWED" << endl;
                home -> addPeople(toEnter);
            }
            else
            {
                cout << "ACCESS DENIED" << endl;
            }
        }

        //WHO'S INSIDE?
        else if(lastCommand == "WHO'S")
        {
            home -> whosHome(); 
        }

        //LEAVE HOUSE <user_name>
        else if(lastCommand == "LEAVE")
        {
            name = getName(command);
            bool found = home->findPerson(name,1);
            if(found)
            {
                cout << "OK" << endl;
            }
            else 
            {
                cout << "ACCESS DENIED" << endl; 
            }
        }
        else if(lastCommand == "CHANGE")
        {
            name = getName(command);

            //persons name is not the owner
            if(name != owner)
            {
                cout << "ACCESS DENIED" << endl;
            }
            else if(home->findPerson(owner,0) == false)
            {
                cout << "ACCESS DENIED" << endl;
            }
            else if(home->findPerson(owner,0) == true)
            {
                keys->deleteKeys();
                pKey = getKey(command,0);
                cout << "OK" << endl;
            }
            else
            {
                cout << "ACCESS DENIED" << endl;
            }

        }


    }
    /*
    while (getline(cin, line))
    {
        string person;
        string temp;
        string enter = "ENTER";
        string insert = "INSERT";
        string turn = "TURN";
        string whos = "WHO'S";
       
        temp = line;
    
        //prints line        
        //cout << temp << endl;


    
        //INSERT KEY adam key
        if(temp.find(insert) != std::string::npos)
        {
            cout << insert << endl;

            //set person's key to element 3 in temp
            pKey = temp[3];
            //KEY key INSERTED BY adam
            cout << "KEY " << pKey << " INSERTED BY " << temp[2] << endl;
        }

        //TURN KEY adam
        else if(temp.find(turn) != std::string::npos)
        {
            cout << "TURN" << endl;

             for(int i = 0; i <= argc; i++)
            {
                //FAILURE adam UNABLE TO TURN KEY key
                if(pKey != keys[i])
                {
                    //if fails result = 0
                    result = 0; 
                }
                //SUCCESS pat TURNS KEY foobar
                if(pKey == key[i])
                {
                    //if passes result = 1
                    result = 1; 
                    break;
                }
            }
            if(result = 0)
            {
                cout << "FAILURE" << temp[2] << " UNABLE TO TURN KEY " << pKey << endl;
            }
            if(result = 1)
            {
                cout << "SUCCESS " << temp[2] << "TURNS KEY" << pKey << endl;
            }
            
        }


        //ENTER HOUSE adam
        if(temp.find(enter) != std::string::npos)
        {   
            cout << enter << endl;

            //if canEnter() == true
            home->addPeople(person);

            //if canEnter() == false
            cout << "ACCESS DENIED" << endl;
        }


        if(temp.find(whos) != std::string::npos)
        {
            cout << whos << endl;

            home->whosHome();

        }
        
       
       line.clear();
    }
    */
    

    return 0;
}