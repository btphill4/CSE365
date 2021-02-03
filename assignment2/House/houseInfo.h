#ifndef houseInfo_h
#define houseInfo_h

using namespace std;

class houseInfo
{
private:
 vector<string> keys;

public:
 void addKey(string toAdd)
  {
   keys.push_back(toAdd);
  }

 bool keySearch(string toSearch, int toDo)
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

 void printKeys()
  {
   for(int i=0; i<keys.size();i++)
    {
     cout << keys[i] << "\n" << endl;
    }
  }

int deleteKeys()
 {
  keys.clear();
  addKey("POLICE_SECRET_KEY");
  addKey("FIREFIGHTER_SECRET_KEY");
  return 1;
 }
 };
#endif
