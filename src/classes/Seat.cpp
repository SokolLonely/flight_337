#include "../../include/classes/Seat.h"
#include <string>
using namespace std;

Seat::Seat(string seat_id, string passenger_id)
    : passenger_id(passenger_id)
{   
    // TODO: improve this implementation
    // Find where the numeric part ends
    int num_end = 0;
    while (num_end < seat_id.length() && seat_id[num_end] >= '0' && seat_id[num_end] <= '9') {
        num_end++;
    }
        
    // Extract the row number
    if (num_end > 0) {
        row_number = stoi(seat_id.substr(0, num_end));
    } else {
        row_number = 0;
    }
        
    // Extract the seat character
    if (num_end < seat_id.length()) {
        seat_character = seat_id[num_end];
    } else {
        seat_character = '\0';
    }
}

Seat::Seat(int row_number, char seat_character, string passenger_id)
    : row_number(row_number), seat_character(seat_character), passenger_id(passenger_id)
{}

string Seat::get_passenger_id() const {
    return passenger_id;
}

int Seat::get_row_number() const {
    return row_number;
}

char Seat::get_seat_character() const {
    return seat_character;
}

void Seat::set_row_number(int r_number) {
    row_number = r_number;
}

void Seat::set_seat_character(char s_character) {
    seat_character = s_character;
}

void Seat::set_passenger_id(string p_id) {
    passenger_id = p_id;
}

