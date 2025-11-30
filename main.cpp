//only main function here. all other functions and calls go to classes.cpp 
//we may create a seperate file for formatted output functions
#include <fstream>
#include <string>
#include "functions.h"
#include "classes.h"
using namespace std;

int main() {
    displayHeader();
    int menu_choice;

    // Initialize database of flights
    Airline* selectedAirline = createAirline(); // Should have possibility of multiple airlines in the future

    int selected_flight_index = 0;

    while((menu_choice = menu())) {
        clearScreen();
        switch(menu_choice) {
            case 1:
                selected_flight_index = browseFlightList(selectedAirline -> get_flights());
                pressEnter();
                break;
            case 2:
                displaySeatMap(selectedAirline -> get_flights()[selected_flight_index]);
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
                cout << "Program terminated." << endl;
                delete selectedAirline;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                pressEnter();
                break;
        }
    }
    delete selectedAirline;
    return 0;   
}