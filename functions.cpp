//non-class functions for output and other things
using namespace std;
#include <iostream>
#include "classes.h"

//TODO add map_display
void printWelcomeMessage() {
    cout << "FMAS Version 1.0" << endl;
    cout << "Term Project — Flight Management Application System" << endl;
    cout << "Produced by Group# 139" << endl;
    cout << "Members: Ryabinkin, Simon; ElSayed, Abdelrahman; Boucher, Maxime" << endl;
    cout << endl;
    cout << "<<< PRESS RETURN TO CONTINUE >>>" << endl;
}
void printChoicePrompt() {
    cout<<"Please select one the following options:"<<endl;

cout<<"1. Select a flight"<<endl;

cout<<"2. Display Flight Seat Map."<<endl;

cout<<"3. Display Passengers Information."<<endl;

cout<<"4. Add a New Passenger."<<endl;

cout<<"5. Remove an Existing Passenger"<<endl;

cout<<"6. Save data"<<endl;

cout<<"7. Quit."<<endl;

cout<<"Enter your choice: (1, 2, 3, 4, 5, 6, or 7)";
}


void display_map(Flight& flight){ //NEED GETTERS FOR FLIGHT
    vector <vector<Seat>> seats = flight.seats;
    int num_rows = flight.number_of_rows * 2;
    int num_cols = flight.number_of_seats_per_row * 2;
    
    cout << "Aircraft Seat Map for flight " << flight.ID << endl; //FLIGHT ID DOESN'T EXIST
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
                if (seats[i][j].occupied)
                    cout << " x |";
                else
                    cout << "   |";
            }
        }
        cout << endl;
    }
}