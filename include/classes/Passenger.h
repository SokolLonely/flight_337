#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
using namespace std;

class Passenger {
private:
    string passenger_id;
    string first_name;
    string last_name;
    string phone_number;
public:
    Passenger(string passenger_id, string f_name, string l_name, string p_number);
    string get_passenger_id() const;
    string get_first_name() const;
    string get_last_name() const;
    string get_phone_number() const;
    void set_first_name(const string& f_name);
    void set_last_name(const string& l_name);
    void set_phone_number(string p_number);
};

#endif // PASSENGER_H

