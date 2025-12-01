// include/classes/Seat.h
#ifndef SEAT_H
#define SEAT_H

#include <string>
using namespace std;

class Seat {
private:
    int row_number;
    char seat_character;
    string passenger_id;
public:
    Seat(string seat_id, string passenger_id);
    Seat(int row_number, char seat_character, string passenger_id);
    string get_passenger_id() const;
    int get_row_number() const;
    char get_seat_character() const;
    void set_row_number(int r_number);
    void set_seat_character(char s_character);
    void set_passenger_id(string p_id);
};

#endif // SEAT_H

