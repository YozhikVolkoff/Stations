#include"Platform.h"

Platform::Platform(string name)
{
    this->name = name;
    this->pass_cap = 0;
    this->cargo_cap = -1;
}

int Platform::set_pass_cap(int new_value)
{
    if (new_value >= 0)
    {
        this->pass_cap = new_value;
        return this->pass_cap;
    }
    return 0;
}

int Platform::set_cargo_cap(int new_value)
{
    return 0;
}

void Platform::print() const
{
    printf("\n%s\n", this->name.c_str());
    printf("Average passengers capacity: %d\n", this->pass_cap);
    printf("Connected railways:\n");
    for (auto i = rws.begin(); i != rws.end(); ++i)
    {
        printf("%s <---> %s, passengers load: %d, cargo load: %d\n", (*i)->get_plat1()->get_name().c_str(), (*i)->get_plat2()->get_name().c_str(),
               (*i)->get_pass_load(), (*i)->get_cargo_load());
    }
}

list<Railway*>::iterator Platform::rws_begin()
{
    return rws.begin();
}

list<Railway*>::iterator Platform::rws_end()
{
    return rws.end();
}

Railway* Platform::operator[] (string name) const
{
    for (auto i = rws.begin(); i != rws.end(); ++i)
    {
        if (((*i)->get_plat1()->get_name() == name) || ((*i)->get_plat2()->get_name() == name))
        {
            return (*i);
        }
    }
    throw std::exception();
}

Platform& Platform::operator()(Railway* m)
{
    if ((m->get_plat1()->get_name() == this->get_name()) || (m->get_plat2()->get_name() == this->get_name()))
    {
            this->rws.push_back(m);
    }
    return *this;
}

Platform::~Platform()
{
    /*for (auto i = rws.begin(); i != rws.end(); ++i)
    {
        free(i->station1);
        free(i->station2);
    }*/
    rws.clear();
}
