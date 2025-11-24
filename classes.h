#include <string>
#include <vector>
using namespace std;

class Flight {
    private:
        vector<Seat> seats;
        vector<Passenger> passengers;
        int number_of_rows;
        int number_of_seats_per_row;
        Route* route;
    public:
        Flight(int number_of_rows, int number_of_seats_per_row, Route* route);
        void addPassenger(Passenger& passenger);
};