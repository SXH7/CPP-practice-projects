#include <iostream>
#include <string>

using namespace std;


// printMsg function prints messeage with or without border
// Will be used multiple times throughout the code
void printMsg(string message, bool printTop= true, bool printBottom= true){
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

// drawHangman will redraw hangman, every guess will slowly complete it
void drawHangman(int count = 0)
{
    if(count >= 1){
        printMsg("|", false, false);
    }
    if(count >= 2){
        printMsg("|", false, false);
    }
    if(count >=3){
        printMsg("O", false, false);
    }
    if(count ==4){
        printMsg("|", false, false);
    }
    if(count ==5){
        printMsg("|\\", false, false);
    }
    if(count >= 6){
        printMsg("/|\\", false, false);
    }
    if(count == 7){
        printMsg(" \\", false, false);
    }
    if(count >= 8){
        printMsg("/ \\", false, false);
    }
    if(count >=9){
        printMsg("+--------+", false, false);
    }
    if(count ==10){
        printMsg("|        |", false, false);
    }
}

// printLetters used to print all letters
// It will also redraw the letters and remove them with each guess
void printLetters(string input, char from, char to, bool top, bool bottom)
{
    string s;
    for(char i = from; i <= to; i++)
    {
        if(input.find(i) == string::npos)
        {
            s+=i;
            s+=" ";
        }
        else
            s+=" ";
    }
    printMsg(s, top, bottom);
}

// function checks if letter guessed by user is in the word or not
bool check(string word, string guess)
{
    bool won = true;
    string s;
    for (int i = 0; i < word.length(); i++)
    {
        if (guess.find(word[i]) == string::npos)
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += word[i];
            s += " ";
        }
    }
    printMsg(s, false);
    return won;

}

// main fuction
int main()
{
    int tries = 0;

    // gameloop
    while(tries <= 10){

        string word;
        cout << "Enter the word to guess.";
        cin >> word;

        printMsg("Hangman");
        drawHangman(tries);
        printLetters(word, 'A', 'M', true, false);
        printLetters(word, 'N', 'Z', false, true);
        check("sample", word);

        if(tries == 9){
            cout << "Last Chance!" << endl;
        }
        if(word == "sample"){
            cout << "You got the word!";
            break;
        }
        if(tries == 10){
            cout << "You didn't get the word :(" << endl;
            break;
        }

        tries++;
    }



    getchar();
    return 0;
}