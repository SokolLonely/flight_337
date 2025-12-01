# Flight Management Application System (FMAS)

A C++ application for managing flight reservations and passenger information.

## Compilation

To compile the program, run:

```bash
g++ -std=c++11 -I include main.cpp src/classes/*.cpp src/utils/*.cpp -o flight_management
```

## Running

After compilation, run the program with:

```bash
./flight_management
```

## Project Structure

- `include/classes/` - Class header files
- `include/utils/` - Utility function headers
- `src/classes/` - Class implementations
- `src/utils/` - Utility function implementations
- `data/` - Data files (flights.txt, passengers.txt)
