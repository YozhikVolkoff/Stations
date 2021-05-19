#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED
#include"Platform.h"

class Platform;

class Train
{
protected:
    bool is_pass;
    list<Railway*> route;
    int cap;
    Platform* plat1;
    Platform* plat2;

public:

    Train(bool is_pass, int cap, Platform* pl1, Platform* pl2);

    bool get_is_pass() const {return is_pass;}

    int get_cap() const {return cap;}

    Platform* get_plat1() const {return plat1;}

    Platform* get_plat2() const {return plat2;}

    void add_to_route(Railway* last_railway);

    void print() const;

    ~Train();   
};

#endif // TRAIN_H_INCLUDED
