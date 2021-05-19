#include"Train.h"

Train::Train(bool is_pass, int cap, Platform* pl1, Platform* pl2)
{
    this->is_pass = is_pass;
    this->cap = cap;
    this->plat1 = pl1;
    this->plat2 = pl2;
}

void Train::add_to_route(Railway* last_railway)
{
    this->route.push_front(last_railway);
}

void Train::print() const
{
    if (this->is_pass == 1) printf("\nPassenger train %s - %s\nNumber of passengers: %d\n", this->plat1->get_name().c_str(), this->plat2->get_name().c_str(), this->cap);
    else printf("\nCargo train %s - %s\nCargo weight: %d\n", this->plat1->get_name().c_str(), this->plat2->get_name().c_str(), this->cap);
    printf("Train route:\n");
    for(auto i = route.begin(); i != route.end(); i++)
    {
	printf("%s <---> %s\n", (*i)->get_plat1()->get_name().c_str(), (*i)->get_plat2()->get_name().c_str());
    }
}

Train::~Train()
{
    route.clear();
}
