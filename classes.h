//header file for classes.cpp
#ifndef CH
#define CH

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Passenger;
class Seat;
class Airline;
class Route;
class Flight;

class Passenger{
    private:
        string passenger_id;
        string first_name;
        string last_name;
        string phone_number;
    public:
        Passenger(string passenger_id, string f_name, string l_name, string p_number);
        string get_passenger_id() const{
            return passenger_id;
        }
        string get_first_name() const{
            return first_name;
        }
        string get_last_name() const{
            return last_name;
        }
        string get_phone_number() const{
            return phone_number;
        }
        void set_first_name(const string& f_name){
            first_name = f_name;
        }
         void set_last_name(const string& l_name){
            last_name = l_name;
        }
        void set_phone_number(string p_number){
            phone_number = p_number;
        }
};

class Seat{
    private:
        int row_number;
        char seat_character;
        string passenger_id;
    public:  
        Seat(string seat_id, string passenger_id);     
        string get_passenger_id() const {
            return passenger_id;
        }
        int get_row_number() const{
            return row_number;
        }
        char get_seat_character() const{
            return seat_character;
        }
        void set_row_number(int r_number){
            row_number = r_number;
        }
        void set_seat_character(char s_character){
            seat_character = s_character;
        }
        void set_passenger_id(string passenger_id){
            passenger_id = passenger_id;
        }
};

class Airline{
    private:
        string name;
        vector<Flight> flights;
    public:
        Airline();
        Airline(string name);

        void set_name(string name);
        string get_name() const;
        vector<Flight> get_flights() const { return flights; }
        void addFlight(Flight& flight);
};

class Route {
    private:
        string source;
        string destination;
    public:
        Route(string source, string destination): source(source), destination(destination){}
        string get_source() const { return source; }
        string get_destination() const { return destination; }
};

class Flight {
    private:
        vector<Seat> seats;
        vector<Passenger> passengers;
        int number_of_rows;
        int number_of_seats_per_row;
        Route route;
        string flight_id;
        void resize_seats();
    public:
        Flight(string flight_id, int number_of_rows, int number_of_seats_per_row, Route route);
        void addPassenger(Passenger& passenger);
        void addSeat(Seat& seat);
        vector<Seat> get_seats () { return seats; }
        int get_number_of_rows() const { return number_of_rows; }
        int get_number_of_seats_per_row() const { return number_of_seats_per_row; }
        Route get_route() const { return route; }
        string get_flight_id() const { return flight_id; }
        vector<Passenger> get_passengers() const { return passengers; }
};

#endif