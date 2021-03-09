#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sendfile.h>
#include <unistd.h>

void segfault_handler(int signum)
{
    printf("Congratulations, you crashed the program!\nHere's your flag:\n");
    setuid(0);
    int flag_fd = open("/flag", 0);
    sendfile(1, flag_fd, 0, 1024);
    exit(0);
}

using namespace std;

int main(int argc, char *argv[])
{

    printf("Hello, we hear that you're really good at causing programs to crash (well, at least the programs that you write).\n");
    printf("In this challenge, we will give you the flag only if you can crash this program (i.e. cause a segmentation fault).\n");
    printf("You'll need to read the source code to understand the code, what input the program takes, and how to cause a segmentation fault\n");
    signal(SIGSEGV, segfault_handler);

    argc = 3;
    argv = (char**) malloc(sizeof(char*)*3);
    argv[1] = "selina";
    argv[2] = "foobar";

    string* owner = NULL;
    string* userKey = NULL;
    string* secretKey = new string("FIREFIGHTER_KEY");
    vector<string> keys;
    vector<string> authorized;
    vector<string> occupants;
    string a = "LATCHKEY INSERT";
    string b = "LATCHKEY twist";
    string c = "DEWLLING access";
    string d = "WHO'S within";
    string e = "MODIFY LATCH";
    string f = "FLEE DEWLLING";
    int num = 0;

    // assign owner
    owner = new string(argv[1]);

    // assign authorized keys
    for (int i = 2; i < argc; ++i)
        keys.emplace_back(argv[i]);

    string input = "";
    while(getline(cin, input))
    {
        num += 1;
        if (num == 100)
        {
            cout << "That's all this house will do" << endl;
            break;
        }

        if(input.find(a) != string::npos)
        {
            size_t pos = input.find(a);
            string temp = input.substr(pos+11);
            pos = temp.find(" ");
            *userKey = temp.substr(pos+1);
            char str[temp.length()];
            for (int i = 0; i < sizeof(str); i++)
            {
                str[i] = temp[i];
            }
            char* user = strtok(str, " ");

            cout << "KEY " << *userKey << " INSERTED BY ";
            printf("%s", user);
            cout << "\n";

        }
        else if(input.find(b) != string::npos)
        {
            size_t pos = input.find(b);
            string user = input.substr(pos+9);
            if (find(keys.begin(), keys.end(), *userKey) != keys.end() || *userKey == *secretKey)
            {
                cout << "SUCCESS " << user << " TURNS KEY " << *userKey << endl;
                authorized.emplace_back(user);
            }
            else
            {
                cout << "FAILURE " << user << " UNABLE TO TURN KEY " << *userKey << endl;
            }
        }
        else if(input.find(c) != string::npos)
        {
            size_t pos = input.find(b);
            string user = input.substr(pos+13);
            if (find(authorized.begin(), authorized.end(), user) != authorized.end())
            {
                cout << "ACCESS ALLOWED" << endl;
                occupants.emplace_back(user);
            }
            else
            {
                cout << "ACCESS DENIED" << endl;
            }
        }
        else if(input.find(d) != string::npos)
        {
            if(occupants.empty())
            {
                cout << "NOBODY HOME" << endl;
            }
            else
            {
                ostringstream ss;
                copy(occupants.begin(), occupants.end() - 1, ostream_iterator<string>(ss, ", "));
                ss << occupants.back();

                cout << ss.str() << "\n";
            }
        }
        else if(input.find(e) != string::npos)
        {
            size_t pos = input.find(b);
            string temp = input.substr(pos+13);
            char str[temp.length()];
            for (int i = 0; i < sizeof(str); i++)
            {
                str[i] = temp[i]; // <user_name> <key_1> <key_n>
            }
            char* user = strtok(str, " ");
            string username = user;

            // check if username is owner and if owner is inside home
            if (find(occupants.begin(), occupants.end(), *owner) != occupants.end() && username.compare(*owner) == 0)
            {
                keys.clear();
                pos = temp.find(" ");
                string temp2 = temp.substr(pos+1);
                stringstream ss(temp2);
                string token;

                while(getline(ss, token, ' '))
                {
                    keys.emplace_back(token);
                }
                cout << "OK" << endl;
            }
            else
            {
                cout << "ACCESS DENIED" << endl;
            }
        }
        else if(input.find(f) != string::npos)
        {
            size_t pos = input.find(a);
            string user = input.substr(pos+13);
            if (find(occupants.begin(), occupants.end(), user) != occupants.end())
            {
                occupants.erase(std::remove(occupants.begin(), occupants.end(), user), occupants.end());
                cout << "OK" << endl;
            }
            else
            {
                cout << user << " NOT HERE" << endl;
            }
        }
        else
        {
            cout << "ERROR" << endl;
        }
    }
    return 0;
}