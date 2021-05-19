#ifndef RAILWAY_H_INCLUDED
#define RAILWAY_H_INCLUDED
#include"Platform.h"

class Platform;

class Railway
{
protected:
    Platform* plat1;
    Platform* plat2;
    int max_pass_load;
    int max_cargo_load;
    int cargo_load;
    int pass_load;

public:

    Railway(Platform* pl1, Platform* pl2, int max_pass_load, int max_cargo_load);

    int get_max_pass_load() const {return max_pass_load;}

    int get_max_cargo_load() const {return max_cargo_load;}

    int get_pass_load() const {return pass_load;}

    int get_cargo_load() const {return cargo_load;}

    int set_pass_load(int new_pass_load);

    int set_cargo_load(int new_cargo_load);

    Platform* get_plat1() const {return plat1;}

    Platform* get_plat2() const {return plat2;}
};


#endif // RAILWAY_H_INCLUDED
