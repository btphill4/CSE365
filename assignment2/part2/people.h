#ifndef people_h
#define people_h

#include <vector>
#include<string> 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class people
{
private:
    //creates a string vector to store each person 
    vector<string> people;  

public: 
    void addPeople(string person)
    {
        people.push_back(person);
    }

    bool findPerson(string person, int x)
    {
        bool found;
        for(int i = 0; i<person.size(); i++)
        {
            if(people[i] == person && x == 0)
            {
                found = true;
                return found;
            }
            else if(people[i] == person && x == 1)
            {
                people.erase(people.begin()+i);
                found = true;
                return found;
            }
        }
        found = false;
        return found;
    }

    void whosHome()
    {
        if(people.size() != 0)
        {
            for(int i = 0; i < people.size(); i++)
            {
                if(people.size()==1)
                {
                    cout << people[i] << endl;
                }
                else
                {
                    if(i < people.size()-1)
                    {
                        cout << people[i] << ", ";
                    }
                    else{
                        cout << people[i] << endl;
                    }
                }
            }
        }
        else
        {
            cout << "NOBODY HOME" << endl;
        }
    }
};
#endif