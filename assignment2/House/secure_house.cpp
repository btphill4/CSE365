//Author

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include "houseInfo.h"
#include "guestInfo.h"

using namespace std;

//keys is an object of the houseInfo class which conatins/manipulates all the information related to the house keys which will be used by the main file to interact with the keys vector
houseInfo *keys = new houseInfo(); 

//This method is called after user enters input to seperate command line input
vector<string> parseInput(string input)
 {
  string temp;
  stringstream ss(input);
  vector<string> parsed;
  while(ss >> temp)
   {
    parsed.push_back(temp);
   }  
  return parsed; 
}

//Below method pulls the command out of the vector created when parseInput is called
string seperateCommand(vector<string> toSeperate)
 {
  string toReturn;
  if(toSeperate[0] == "EXIT") //EXIT command will quit the program
   {
    toReturn = "EXIT";
    return toReturn;
   }
  else
   {
    toReturn = toSeperate[0] + toSeperate[1]; //All commands other than exit are two strings
    return toReturn;
   }
 }

//Below method is called to get guestName from the users input
string seperateName(vector<string> toSeperate)
 {
  string toReturn = toSeperate[2];
  return toReturn;
 }

//Below method is called to get keyName from user input
string seperateKey(vector<string> toSeperate, int toDo)
 {
  if(toDo == 0) //Used in conjunction with CHANGE LOCKS command to add new keys
  {
   for(int i=3; i<toSeperate.size();i++)
    {
     keys->addKey(toSeperate[i]);
    }
   return "Added";
   }
  else //Used to simply return the name of the key a guest enters
  {
  string toReturn = toSeperate[3]; 
  return toReturn;
  }
 }

int main(int argc, char* argv[])
 {
  if(argc <= 2) //If owner or key is not entered, the user will be notified
   {
    cout << "ERROR" << endl;
   }

  string ownerName = argv[1];
  string finalCommand;
  string guestName;
  string keyName;  
  //houseInfo *keys = new houseInfo(); //Created object of houseInfo class that will manipulate key information
  guestInfo *guests = new guestInfo();
  keys->addKey("POLICE_SECRET_KEY");
  keys->addKey("FIREFIGHTER_SECRET_KEY");
  for(int i=2; i<argc; i++)
   {
    keys->addKey(argv[i]);
   }

   string inLine;
  
   getline(cin,inLine);
   
   vector<string> command = parseInput(inLine);//Command vector will contain entire user input
 
   finalCommand = seperateCommand(command); //finalCommand contains the command entered by user
   int exit = 0; //exit will be used to stop the program at users discretion

   if(finalCommand == "EXIT")
    {
     exit = 1;
    }
   
   bool found = false; //Found will be used with INSERT KEY to check validity of the key

   string toEnter;

   while(exit == 0)
    {
      keys->printKeys();
      //insert command
     if(finalCommand == "INSERTKEY")
      {
       guestName = seperateName(command);
       keyName = seperateKey(command,1);
       cout << "KEY " << keyName << " INSERTED BY " << guestName  << endl;
       found = keys->keySearch(keyName,0);
       string isCop;
       if(guestName.size() >= 20)
      	{
         isCop = guestName.substr(0,20);
        }
       if(found == true)
	      {
          if(keyName == "POLICE_SECRET_KEY" && isCop != "officer_with_warrant")
            {
            found = false;
            }
          toEnter = guestName;
        }
      }
      else if(finalCommand == "ENTERHOUSE")
        {
          guestName = seperateName(command);
          if(found == true)
            {
              found = false;
              if(guestName == toEnter)
              {
                cout << "ACCESS ALLOWED" << endl;
                guests->addGuest(toEnter);
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
     else if(finalCommand == "WHO'SINSIDE?")
      {
      guests->printGuests(); 
      }
     else if(finalCommand == "LEAVEHOUSE")
	  { 
      guestName = seperateName(command);
      bool success =  guests->guestSearch(guestName,1);
      if(success)
        {
        cout << "OK" << endl; 
        }	
      else
        {
        cout << guestName << " NOT HERE" << endl;
        }
	  }
     else if (finalCommand == "CHANGELOCKS")
	  {
	   guestName = seperateName(command);
	   if(guestName != ownerName)
	    {
	     cout << "ACCESS DENIED" << endl;
	    } 	    
	   else if(guests->guestSearch(ownerName,0) == false)
	    {
	     cout << "ACCESS DENIED" << endl;
	    }
	   else if(guests->guestSearch(ownerName,0) == true)
	    {
	     keys->deleteKeys();
	     keyName = seperateKey(command,0);
	     cout << "OK" << endl;
	    }
	   else
	    {
	     cout << "ACCESS DENIED" << endl;
	    }
	  }
     else if(finalCommand == "EXIT")
	  {
	   //
	  } 
     else
	  {
	    cout << "ERROR" << endl;
	  } 
     if(!(getline(cin,inLine)))
      {
        exit = 1;
      }
        if(inLine == "")
          {
            exit = 1;
          }
        else
          {
            command = parseInput(inLine);
            finalCommand = seperateCommand(command);
            if(finalCommand == "EXIT")
            {
              exit = 1;
            }
          }
    }
} 
