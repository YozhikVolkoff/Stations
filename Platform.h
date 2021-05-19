#ifndef PLATFORM_H_
#define PLATFORM_H_
#include<cstdio>
#include<exception>
#include<string>
#include<list>
#include"Railway.h"
using std::list;
using std::string;

class Railway;

class Platform
{
protected:
    string name;
    int pass_cap;
    int cargo_cap;
    list<Railway*> rws;


public:

    Platform(string name);

    const string get_name() const {return name;}

    int get_pass_cap() const {return pass_cap;}

    int set_pass_cap(int new_value);

    virtual int get_cargo_cap() const {return cargo_cap;}

    virtual int set_cargo_cap(int new_value);

    virtual void print() const;

    list<Railway*>::iterator rws_begin();

    list<Railway*>::iterator rws_end();

    Railway* operator[] (string name) const;

    Platform& operator()(Railway* m);

    ~Platform();
};



#endif // PLATFORM_H_
