#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    char arr[sizeof(argv)]; 

    //print number of arguments(argc)
    cout << argc << endl;
    
    int size = sizeof(argc);
    int m = size;
   //cout << "Size:" << size << endl;

    do{
        cout << m << endl;
        cout << argv[m];
        m--;
    }while(m =! 0);


    for(int i = 1; i <= argc; i++)
    {
    
        //cout << argv[i] << " ";//<< endl;
        
    }
    cout << endl << size;

    

    /*while(size > 0){
        cout << argv << endl;
        size--;
    }*/ 
    

   return 0;
}