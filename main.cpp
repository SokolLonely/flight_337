//only main function here. all other functions and calls go to classes.cpp 
//we may create a seperate file for formatted output functions
#include "functions.h"
#include "classes.h"
using namespace std;

int main() {
    displayHeader();
    int menu_choice;
    Flight* selectedFlight = nullptr;

    while((menu_choice = menu())){
        clearScreen();
        switch(menu_choice) {
            case 1:
                selectedFlight = browseFlightList();
                pressEnter();
                break;
            case 2:
                displaySeatMap(selectedFlight);
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