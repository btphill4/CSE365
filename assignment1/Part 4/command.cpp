#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    //print number of arguments(argc) with less than
    cout << argc - 1 << endl;

    //converts argv[] into a string pointer array
    string *temp = new string[argc];

    string a = " ";
    for(int i = 0; i < argc; i++)
    {
        temp[i] = argv[i] + a;
    }

    //prints the array
    for(int i = argc; i >= 1; i--)
    {
        cout << temp[i];
    }

   return 0;
}