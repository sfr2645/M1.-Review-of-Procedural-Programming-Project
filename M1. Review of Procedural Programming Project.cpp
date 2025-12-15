// M1. Review of Procedural Programming Project.cpp
// This code will allow the user to play a functional game of Rock, Paper, Scissors with the machine
// and keep track of who is winning with a running tally.

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    string challenger;
    string computer;
    int challengerScore = 0;
    int computerScore = 0;
    string rps[] = { "rock", "paper", "scissors" };

    srand((unsigned int)time(NULL));

    while (true) {
        cout << "Please enter rock, paper, or scissors:";
        getline(cin, challenger);

        if (challenger != "rock" && challenger != "paper" && challenger != "scissors") {
            break;
        }

        computer = rps[rand() % 3]; 
        cout << "Computer chooses: " << computer << endl;

        if (challenger == computer) {
            challengerScore++;
            computerScore++;
        }
        else if (challenger == "rock") {
            if (computer == "scissors") challengerScore++;
            else if (computer == "paper") computerScore++;
        }
        else if (challenger == "paper") {
            if (computer == "rock") challengerScore++;
            else if (computer == "scissors") computerScore++;
        }
        else if (challenger == "scissors") {
            if (computer == "paper") challengerScore++;
            else if (computer == "rock") computerScore++;
        }
        cout << "Challenger: " << challengerScore << " Computer: " << computerScore << " \nPress enter to quit." << endl;
    }

    cout << "Challenger: " << challengerScore << " Computer: " << computerScore << endl;
    if (challengerScore > computerScore) cout << "Woohoo! Challenger wins." << endl;
    else if (challengerScore < computerScore) cout << "Lame, computer wins!" << endl;
    else cout << "You tied with the computer!" << endl;
}