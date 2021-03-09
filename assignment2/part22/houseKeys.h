#ifndef houseKeys_h
#define houseKeys_h
#include <vector>
#include<string>  
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class houseKeys
{
private:
 vector<string> keys;

public:
    void addKey(string tempKey)
    {
    keys.push_back(tempKey);
    }

    //prints the key array
    void printKeys()
    {
    for(int i=0; i<keys.size();i++)
        {
        cout << keys[i] << "\n" << endl;
        }
    }

    //deletes vector and adds firefighter key again
    int deleteKeys()
    {
        keys.clear();
        addKey("FIREFIGHTER_SECRET_KEY");
        return 1;
    }

    //returns true or false if it found the key in the vector
    bool lookForKey(string toSearch, int toDo)
    {
    bool toReturn;
    for(int i=0; i<keys.size();i++)
        {
        if(keys[i] == toSearch && toDo == 1)
        {
        keys.erase(keys.begin()+i);
        toReturn = true;
        return toReturn;
        }
        else if(keys[i] == toSearch && toDo == 0)
        {
        toReturn = true;
        return toReturn;
        }
        }
        toReturn = false;
        return toReturn;
    }
 };
#endif
