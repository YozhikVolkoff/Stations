#include"Station.h"

Station::Station(string name): Platform(name)
{
    this->name = name;
    this->pass_cap = 0;
    this->cargo_cap = 0;
}

int Station::set_cargo_cap(int new_value)
{
    if (new_value >= 0)
    {
        this->cargo_cap = new_value;
        return this->cargo_cap;
    }
    return 0;
}

void Station::print() const
{
    printf("\n%s\n", this->name.c_str());
    printf("Average passengers capacity: %d\n", this->pass_cap);
    printf("Average cargo capacity: %d\n", this->cargo_cap);
    printf("Connected railways:\n");
    for (auto i = rws.begin(); i != rws.end(); ++i)
    {
        printf("%s <---> %s, passengers load: %d, cargo load: %d\n", (*i)->get_plat1()->get_name().c_str(), (*i)->get_plat2()->get_name().c_str(),
               (*i)->get_pass_load(), (*i)->get_cargo_load());
    }
}
