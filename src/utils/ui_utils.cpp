// src/utils/ui_utils.cpp
#include "../../include/utils/ui_utils.h"
#include <iostream>
using namespace std;

void cleanStandardInputStream(void) {
    int leftover;
    do {
        leftover = cin.get();
    } while (leftover != '\n' && leftover != EOF);
}

void clearScreen(void) {
    cout << "\033[2J\033[1;1H"; // ANSI escape sequence to clear the screen (cross-platform compatible)
}

void pressEnter() {
    cout << "\n<<< Press Return to Continue >>>" << endl;
    cin.get();
}

void displayHeader() {
    clearScreen();
    cout << "FMAS Version 1.0" << endl;
    cout << "Term Project - Flight Management Application System" << endl;
    cout << "Produced by Group#: 11" << endl;
    cout << "Names: Ryabinkin, Simon; ElSayed, Abdelrahman; Boucher, Maxime" << endl;
    pressEnter();
    cleanStandardInputStream();
}

void printChoicePrompt() {
    cout << "Please select one the following options:\n" << endl;
    cout << "1. Select a flight" << endl;
    cout << "2. Display Flight Seat Map." << endl;
    cout << "3. Display Passengers Information." << endl;
    cout << "4. Add a New Passenger." << endl;
    cout << "5. Remove an Existing Passenger" << endl;
    cout << "6. Save data" << endl;
    cout << "7. Quit." << endl;
    cout << "\nEnter your choice: (1, 2, 3, 4, 5, 6, or 7) ";
}

int menu() {
    int choice = -1;
    clearScreen();
    
    while (true) {
        printChoicePrompt();

        if (!(cin >> choice)) {
            cin.clear();
            cout << "\nInvalid choice. Please enter a number between 1 and 7.\n" << endl;
            cleanStandardInputStream();
            continue;
        }
        cleanStandardInputStream();
        break;
    }
    return choice;
}

