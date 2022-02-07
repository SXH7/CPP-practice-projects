#include <iostream>
using namespace std;

void printmsg(string message, bool printTop= true, bool printBottom= true){
    if(printTop)
    {
        cout <<  "+---------------------------------------+" << endl;
        cout << "|";
    }
    else{
        cout << "|";
    }

    bool front = true;
    for(int i = message.length(); i < 39; i++)
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
    cout << message;

    if(printBottom)
    {
        cout << "|" << endl;
        cout << "+---------------------------------------+" << endl;
    }
    else{
        cout << "|" << endl;
    }
}

void drawHangman(int count = 0)
{
    if(count >= 1){
        printmsg("|", false, false);
    }
    if(count >= 2){
        printmsg("|", false, false);
    }
    if(count >=3){
        printmsg("O", false, false);
    }
    if(count ==4){
        printmsg("|", false, false);
    }
}

int main()
{
    printmsg("Hangman");
    drawHangman(10);
}