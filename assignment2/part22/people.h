#ifndef people_h
#define people_h

# include<vector>
#include<string>  

using namespace std;

class people
{
private:
 vector<string> people;

public:
    //add people to the people vector
    void addPerson(string tempPeople)
    {
    people.push_back(tempPeople);
    }

    //prints the people string vector
    void printHouse()
    {
    if(people.size() != 0)
    {
    for(int i=0; i<people.size();i++)
        {
        if(people.size() == 1)
        {
        cout << people[i] << endl;
        }
        else
        {
        if(i<people.size()-1)
            {
            cout << people[i] << ", ";
            }
        else
            {
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

    //searches the person array and returns true or false if found
    bool personSearch(string tempPerson,int x)
    {
    bool toReturn;
    for(int i=0; i<people.size();i++)
        {
        if(people[i] == tempPerson && x == 0)
        {
        toReturn = true;
        return toReturn;
        }
        else if(people[i] == tempPerson && x == 1)
        {
        people.erase(people.begin()+i);
        toReturn = true;
        return toReturn;
        }
        }
        toReturn = false;
        return toReturn;
    }
 };
#endif
