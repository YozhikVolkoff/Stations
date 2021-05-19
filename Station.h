#ifndef STATION_H_INCLUDED
#define STATION_H_INCLUDED
#include"Platform.h"

class Station: public Platform
{
protected:

public:

    Station(string name);

    int set_cargo_cap(int new_value);

    void print() const;

    //~Station();
};
#endif // STATION_H_INCLUDED
