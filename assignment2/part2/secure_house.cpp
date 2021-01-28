#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector> 

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

//Variables
string key; 
string person;
vector<string> house;
string pKey;

//Key Methods
string returnKey(){
    return key;
}
string insertKey(){

}

string turnKey(){
    if(pKey == key)
    {
        cout << "Success " << person << "TURNS KEY" << key;
    }
}

string enter()
{
    if(canEnter() == true)
    {
        house.push_back(person);
    }
    else
    {
       cout << "ACCESS DENIED" << endl;
    }
}
bool canEnter(){

}

string whoseInside()
{
    if (house.empty())
    {
        cout << "Empty";
    } 
    else 
        for(int i = 0; i < house.size(); i++)
        {
            cout << house.at(i);
        }
}


int main(int argc, char* argv[])
{
 
    
    
}