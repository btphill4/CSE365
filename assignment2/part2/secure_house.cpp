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
}


int main(int argc, char* argv[])
{
    int size = argc;
    string fireFighterKey = "FIREFIGHTER_SECRET_KEY";
    string line;
    vector<string> home;
    int result = 0;

    for(int i = 2; i <= size; i++)
    {
        key[i] = argv[2];
        cout << key;
    }

    fireFighterKey = key[sizeof(key) + 1];

    while (getline(cin, line))
    {
        string temp[sizeof(line)];
        int sizeL = sizeof(line);
        //cout << line << endl;
        for(int i = 0; i < sizeL; i++)
        {
            temp[i] = line[i];
            cout << temp[i] << endl;
        }


        //INSERT KEY adam key
        if(temp[1] == "INSERT")
        {
            //set person's key to element 3 in temp
            pKey = temp[3];
            //KEY key INSERTED BY adam
            cout << "KEY " << pKey << " INSERTED BY " << temp[2] << endl;
        }

        //TURN KEY adam
        if(temp[1] == "TURN")
        {
           
            //turnKey()?

            for(int i = 0; i <= sizeL; i++)
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
        if(temp[1] == "ENTER")
        {
            //if canEnter() == true
            home.push_back(person);

            //if canEnter() == false
            cout << "ACCESS DENIED";
        }

        //WHO'S INSIDE?
        if(temp[1] == "WHO'S")
        {
            //if empty
            if (home.empty())
            {
                cout << "NOBODY HOME";
            } 
            //if not empty
            else 
                for(int i = 0; i < home.size(); i++)
                {
                    cout << home.at(i);
                }

        }
        


    }

    

    return 0;
}