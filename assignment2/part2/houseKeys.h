#ifndef houseKeys_h
#define houseKeys_h

#include <vector>
#include<string>  

using namespace std;

class houseKeys
{
private:
 vector<string> keys;

public:
  void addKey(string toAdd)
  {
    keys.push_back(toAdd);
  }

  bool findKey(string tempKey, int x)
  {
    bool found;
    for(int i = 0; i < keys.size(); i++)
    {
      if(keys[i] == tempKey && x ==1)
      {
        keys.erase(keys.begin()+i);
        found = true;
        return found;
      }
      else if(keys[i] == tempKey && x == 0)
      {
        found = true;
        return found;
      }
    }
    found = false; 
    return found;
  }

  int deleteKeys()
  {
    keys.clear();
    addKey("FIREFIGHTER_SECRET_KEY");
    return 1;
  }
};
#endif
