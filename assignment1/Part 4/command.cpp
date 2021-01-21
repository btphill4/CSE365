#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    char arr[argc + 1]; 

    //print number of arguments(argc)
    cout << argc << endl;
    int size = sizeof(argv);

    for(int i = 1; i <= argc; i++)
    {
        cout << argv[i] << " ";//<< endl;
    }
    cout << endl;


    /*while(size > 0){
        cout << argv << endl;
        size--;
    }*/ 
    

   return 0;
}