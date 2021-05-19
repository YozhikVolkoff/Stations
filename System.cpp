#include"System.h"

System::System()
{

}

Platform* System::create_platform(string name)
{
    Platform* pl = new Platform(name);
    bool a = false;
    for (auto i = this->Pls.begin(); i != this->Pls.end(); i++)
    {
        if ((*i).first->get_name() == name)
        {
	    a = true;
	    break;
        }
    }
    if (a == false) 
    {
	this->Pls[pl] = 0;
	return pl;
    }
    return nullptr;
}

Station* System::create_station(string name)
{
    Station* st = new Station(name);
    bool a = false;
    for (auto i = this->Pls.begin(); i != this->Pls.end(); i++)
    {
        if ((*i).first->get_name() == name)
        {
            a = true;
            break;
        }
    }
    if (a == false)
    {
        this->Pls[st] = 0;
        return st;
    }
    return nullptr;
}


Platform* System::find_platform(string name)
{
    for (auto i = Pls.begin(); i != Pls.end(); i++)
    {
        if ((*i).first->get_name() == name) 
        {
            return (*i).first;
        }
    }
    return nullptr;
}

Railway* System::create_railway(string A, string B, int max_pass_load, int max_cargo_load)
{
    Platform* pl1 = find_platform(A);
    Platform* pl2 = find_platform(B);
    if ((pl1 != nullptr) && (pl2 != nullptr) && (max_pass_load >= 0) && (max_cargo_load >= 0))
    {
	Railway* rw = new Railway(pl1, pl2, max_pass_load, max_cargo_load);
	(*pl1)(rw);
	(*pl2)(rw);
	return rw;
    }	
    else return nullptr;
}

Train* System::create_train(bool is_pass, int cap, string A, string B)
{
    Platform* pl1 = find_platform(A);
    Platform* pl2 = find_platform(B);
    if ((pl1 != nullptr) && (pl2 != nullptr) && (cap>=0))
    {
        Train* tr = new Train(is_pass, cap, pl1, pl2);
        this->Trs.push_back(tr);
	return tr;
    }
    else return nullptr;
}

void System::trains_go()
{
    for (auto i = this->Trs.begin(); i != this->Trs.end(); i++)
    {
	find_route(this->Pls, (*i));
	(*i)->print();
    }
}

System::~System()
{
    /*for (auto i = this->Pls.begin(); i != this->Pls.end(); i++)
    {
	for (auto j = (*i).first->rws_begin(); j != (*i).first->rws_end(); j++)
	{
	    //delete j;
	}
	//free((*i).first);
    }*/
    Pls.clear();
    Trs.clear();
}
