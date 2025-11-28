//non-class functions for output and other things
#include <iostream>
#include <cstdlib>
#include "classes.h"
#include "functions.h"
using namespace std;

void cleanStandardInputStream (void) {
    int leftover;
    do {
        leftover = cin.get();
    } while (leftover !='\n' && leftover != EOF);
}

void clearScreen(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pressEnter() {
    cout << "\n<<< Press Return to Continue>>>>\n";
    cin.get();
}

void displayHeader() {
    clearScreen();
    cout << "FMAS Version 1.0" << endl;
    cout << "Term Project — Flight Management Application System" << endl;
    cout << "Produced by Group#: 139" << endl;
    cout << "Names: Ryabinkin, Simon; ElSayed, Abdelrahman; Boucher, Maxime" << endl;
    pressEnter();
}

void printChoicePrompt() {
    cout<<"Please select one the following options:\n"<<endl;
    cout<<"1. Select a flight"<<endl;
    cout<<"2. Display Flight Seat Map."<<endl;
    cout<<"3. Display Passengers Information."<<endl;
    cout<<"4. Add a New Passenger."<<endl;
    cout<<"5. Remove an Existing Passenger"<<endl;
    cout<<"6. Save data"<<endl;
    cout<<"7. Quit."<<endl;
    cout<<"Enter your choice: (1, 2, 3, 4, 5, 6, or 7)"<<endl;
}

int menu() {
    int choice = -1;
    clearScreen();
    printChoicePrompt();
    cin >> choice;
    cleanStandardInputStream();
    return choice;
}

void displaySeatMap(Flight& flight) {
    vector <vector<Seat>> seats = flight.get_seats();
    int num_rows = flight.get_number_of_rows() * 2;
    int num_cols = flight.get_number_of_seats_per_row() * 2;
    
    cout << "Aircraft Seat Map for flight " << flight.get_ID() << endl;
    cout << "  ";
    for (int k = 0; k < num_cols/2; k++)
        cout << "  " << (char)65 + k << " ";

    for (int i = 0; i < num_rows; i++){
        if (i % 2 == 0)
            cout << "  +";
        else
            cout << (1 + i / 2) << " |";
        for (int j = 0; j < num_cols; j++){
            if (j % 2 == 0)
                cout << "---+";
            else{
                if (seats[i][j].get_occupied())
                    cout << " x |";
                else
                    cout << "   |";
            }
        }
        cout << endl;
    }
}

Flight browseFlightList();
void displaySeatMap(Flight);
void displayPassengerInformation(Flight);
void addNewPassenger(Flight);
void removeExistingPassenger(Flight);
void saveDataToFile(Flight);
