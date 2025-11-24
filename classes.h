//header file for classes.cpp
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

class Passenger{
    private:
        std::string first_name;
        std::string last_name;
        int phone_number;
    public:
        std::string get_first_name() const{
            return first_name;
        }
        std::string get_last_name() const{
            return last_name;
        }
        int get_phone_number() const{
            return phone_number;
        }
        void set_first_name(const std::string& f_name){
            first_name = f_name;
        }
         void set_first_name(const std::string& l_name){
            last_name =l_name;
        }
        void set_phone_number(int p_number){
            phone_number = p_number;
        }
        Passenger();
        Passenger(std::string f_name, std::string l_name, int p_number);
};

class Seat{
    private:
        int row_number;
        char seat_character;
        Passenger* passenger_ptr; 
    public:
                
        int get_row_number() const{
            return row_number;
        }
        char get_seat_character() const{
            return seat_character;
        }
        Passenger* get_passenger_ptr(){
            return passenger_ptr;
        }
        //
        void set_row_number(int r_number){
            row_number = r_number;
        }
        void set_seat_character(char s_character){
            seat_character = s_character;
        }
        void set_passenger_ptr(Passenger* p_ptr){
            passenger_ptr = p_ptr;
        }
        Seat();
        Seat(int r_number, char s_character, Passenger* p_ptr);

};