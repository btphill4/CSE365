#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector> 
#include<string.h>      


using namespace std;

/** Example input
INSERT KEY adam key
TURN KEY adam
ENTER HOUSE adam
INSERT KEY pat foobar
TURN KEY pat
ENTER HOUSE pat
WHO'S INSIDE?

*/

/** Methods
 * insertKey()
 * turnKey()
 * enter()
 * hasKey()
 * FIREFIGHTER_SECRET_KEY
 * whoseInside()
 * peopleInHouse()
*/

/** 
Given the input:
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

/*
//Variables
string* key = new string[200]; 
string person;
vector<string> house;
string pKey;

//Key Methods
void returnKeys(){
    for(int i = 0; i <= sizeof(key); i++){
        cout << key[i] << ", ";
    }
}
string insertKey(){
    string keyI = "Key Inserted";
    return keyI;
}

void turnKey(){
    for(int i = 0; i < sizeof(key);i++){
        if(pKey == key[i])
        {
            //return "Success" + person + "TURNS KEY" + key;
            cout << "Success " << person << "TURNS KEY" << key;
        }
    }
}
*/
/*bool canEnter(person){
    return canEnter(person);
}*//*

void enter()
{
    if(canEnter() == true)
    {
        house.push_back(person);
    }
    else
    {
       cout << "ACCESS DENIED" << endl;
    }
} */
/*
void whoseInside()
{
    if (house.empty())
    {
        cout << "NOBODY HOME";
    } 
    else 
        for(int i = 0; i < house.size(); i++)
        {
            cout << house.at(i);
        }
}*/


int main(int argc, char* argv[])
{
    //Key variables
    string* key = new string[argc]; 

    ///People variables
    string person;
    string pKey;
    string fireFighterKey = "FIREFIGHTER_SECRET_KEY";
    vector<string> home;

    //code variables
    int size = argc;
    string line;
    int result = 0;
    

    //./secure_house selina foobar test yo keys
  /*  for(int i = 2; i <= size; i++)
    {
        key[i] = argv[2];
        cout << key;
    }*/

    //fireFighterKey = key[sizeof(key) + 1];

    while (getline(cin, line))
    {
        
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
                if(pKey != key[i])
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
            home.push_back(person);

            //if canEnter() == false
            cout << "ACCESS DENIED" << endl;
        }


        if(temp.find(whos) != std::string::npos)
        {
            cout << whos << endl;

             //if empty
            if (home.empty())
            {
                cout << "NOBODY HOME" << endl;
            } 
            //if not empty
            else 
                for(int i = 0; i < home.size(); i++)
                {
                    cout << home.at(i) << ", ";
                }

        }

       
       line.clear();
    }

    

    return 0;
}