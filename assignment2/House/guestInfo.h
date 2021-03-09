#ifndef guestInfo_h
#define guestInfo_h

using namespace std;

class guestInfo
{
private:
 vector<string> guests;

public:
 void addGuest(string toAdd)
  {
   guests.push_back(toAdd);
  }

 bool guestSearch(string toSearch,int toDo)
  {
   bool toReturn;
   for(int i=0; i<guests.size();i++)
    {
     if(guests[i] == toSearch && toDo == 0)
      {
       toReturn = true;
       return toReturn;
      }
     else if(guests[i] == toSearch && toDo == 1)
      {
  	guests.erase(guests.begin()+i);
	toReturn = true;
	return toReturn;
      }
    }
    toReturn = false;
    return toReturn;
   }

 void printGuests()
  {
   if(guests.size() != 0)
   {
   for(int i=0; i<guests.size();i++)
    {
     if(guests.size() == 1)
      {
       cout << guests[i] << endl;
      }
     else
      {
       if(i<guests.size()-1)
	      {
         cout << guests[i] << ", ";
        }
       else
        {
          cout << guests[i] << endl;
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
