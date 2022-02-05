#include <iostream>
using namespace std;

void printmsg(string message, bool printTop= true, bool printBottom= true){
    if(printTop)
    {
        cout <<  "+---------------------------------------+" << endl;
        cout << "|";
    }

    bool front = true;
    for(int i = message.length(); i < 41; i++)
    {
        if(front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }

    if(printBottom)
    {
        cout << "|";
        cout << "+---------------------------------------+";
    }
}

int main()
{
    printmsg("test");
}