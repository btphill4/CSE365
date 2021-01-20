#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char** args)
{
    string sTxt = "Testing string so yuh";
   /* while(cin >> sTxt)
    {
        getline(cin,sTxt);
    }*/
    
    int sSize = sTxt.length(); 

    char* cTxt = new char[sSize];
        for(int i = 0; i < sSize; i++)
        {
            cTxt[i] += sTxt[i-1];
        }
    
    for(int i = 0; i < sSize; i++)                    //iterate the array starting with the max size 1 less than cTxt
    {
    cout << cTxt[i];
    }

   return 0;
}