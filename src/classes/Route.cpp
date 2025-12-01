// src/classes/Route.cpp
#include "../../include/classes/Route.h"
using namespace std;

Route::Route(string source, string destination)
    : source(source), destination(destination)
{}

string Route::get_source() const {
    return source;
}

string Route::get_destination() const {
    return destination;
}

