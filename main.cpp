#include <iostream>
#include "include/classes/Airline.h"
#include "include/classes/Flight.h"
#include "include/utils/ui_utils.h"
#include "include/utils/flight_operations.h"
#include "include/utils/data_io.h"
using namespace std;

int main() {
    displayHeader();
    int menu_choice;

    // Initialize database of flights
    Airline* selectedAirline = createAirline(); // Should have possibility of multiple airlines in the future

    int selected_flight_index = 0;

    while((menu_choice = menu())) {
        clearScreen();
        Flight& selected_flight = selectedAirline -> get_flight(selected_flight_index);
        switch(menu_choice) {
            case 1:
                selected_flight_index = browseFlightList(selectedAirline -> get_flights());
                pressEnter();
                break;
            case 2:
                displaySeatMap(selected_flight);
                pressEnter();
                break;
            case 3:
                displayPassengerInfo(selected_flight);
                pressEnter();
                break;
            case 4:
                addNewPassenger(selected_flight);
                break;
            case 5:
                removeExistingPassenger(selected_flight);
                pressEnter();
                break;
            case 6:
                saveData(selectedAirline -> get_flights());
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