//only main function here. all other functions and calls go to classes.cpp 
//we may create a seperate file for formatted output functions
#include "functions.h"
#include "classes.h"
using namespace std;

int main() {
    //cleanStandardInputStream();
    displayHeader();
    int choice;
    Flight active;
    while((choice = menu())){
        switch(choice){
            case 1:
                cout << "Select a flight" << endl; //TODO: replace with function call
                
                active = browseFlightList();
                pressEnter();
                break;
            case 2:
                cout << "Display Flight Seat Map" << endl; //TODO: replace with function call
                pressEnter();
                break;
            case 3:
                cout << "Display Passengers Information" << endl; //TODO: replace with function call
                pressEnter();
                break;
            case 4:
                cout << "Add a New Passenger" << endl; //TODO: replace with function call
                pressEnter();
                break;
            case 5:
                cout << "Remove an Existing Passenger" << endl; //TODO: replace with function call
                pressEnter();
                break;
            case 6:
                cout << "Save data" << endl; //TODO: replace with function call
                pressEnter();
                break;
            case 7:
                cout << "Quitting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                pressEnter();
                break;
        }
    }
    return 0;   
}