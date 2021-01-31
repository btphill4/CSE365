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
string returnKeys(){
    for(int i = 0; i <= sizeof(key); i++){
        return key[i];
    }
}
string insertKey(){
    return "Key Inserted";
}

string turnKey(){
    for(int i = 0; i < sizeof(key);i++){
        if(pKey == key[i])
        {
            cout << "Success " << person << "TURNS KEY" << key;
        }
    }
}

/*bool canEnter(){

}*/

/*string enter()
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

string whoseInside()
{
    if (house.empty())
    {
        return "NOBODY HOME";
    } 
    else 
        for(int i = 0; i < house.size(); i++)
        {
            return house.at(i);
        }
}


int main(int argc, char* argv[])
{
    int size = sizeof(argv);
    string fireFighterKey = "FIREFIGHTER_SECRET_KEY";
    string line;

    for(int i = 2; i <= size; i++){
    key[i] = argv[2];
    cout << key;
    }

    fireFighterKey = key[sizeof(key) + 1];

    while (getline(cin, line))
    {
        cout << line << endl;
    }


}