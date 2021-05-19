#include"Railway.h"

Railway::Railway(Platform* pl1, Platform* pl2, int max_pass_load, int max_cargo_load)
{
    this->plat1 = pl1;
    this->plat2 = pl2;
    this->max_pass_load = max_pass_load;
    this->max_cargo_load = max_cargo_load;
    this->pass_load = max_pass_load;
    this->cargo_load = max_cargo_load;

}

int Railway::set_pass_load(int new_pass_load)
{
    if (new_pass_load >= 0)
    {
	this->pass_load = new_pass_load;
	return this->pass_load;
    }
    return 0;
}

int Railway::set_cargo_load(int new_cargo_load)
{
    if (new_cargo_load >= 0)
    {
	this->cargo_load = new_cargo_load;
	return this->cargo_load;
    }
    return 0;
}
