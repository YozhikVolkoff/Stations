#ifndef SYSTEM_H_
#define SYSTEM_H_
#include"Railway.h"
#include"Platform.h"
#include"Station.h"
#include"Train.h"
#include"Finder.h"

class Platform;
class Staion;
class Railway;
class Train;

class System
{
protected:
    list<Train*> Trs;
    map<Platform*, int> Pls {};

public:

    System();
    
    Platform* find_platform(string name);

    Platform* create_platform(string name);

    Station* create_station(string name);

    Railway* create_railway(string A, string B, int pass_cap, int cargo_cap);

    Train* create_train(bool is_pass, int cap, string A, string B);

    void trains_go();

    ~System();
};

#endif // PLATFORM_H_
