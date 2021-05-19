#include"Finder.h"

class Platform;
class Railway;
class Train;

void find_route(map<Platform*, int> Pls, Train *tr)
{
    bool num_set = true;
    int step = 1;
    if (tr->get_is_pass() == true)
    {
	for(auto i = Pls.begin(); i != Pls.end(); i++)
	{
	    (*i).second = (Pls.size() + 1);
            if((*i).first->get_name() == tr->get_plat1()->get_name()) (*i).second = 1;
	}
	while(num_set == true)
	{
	    num_set = false;
            for(auto i = Pls.begin(); i != Pls.end(); i++)                                                                      //проверяем, можем ли с текущего слоя доехать до конечной
            {
		if((*i).second == step)
		{
                    for (auto j = (*i).first->rws_begin(); j != (*i).first->rws_end(); j++)                                                 //итерируемся по перегонам станции с последнего слоя
                    {
			if (((*j)->get_plat1()->get_name() == tr->get_plat2()->get_name()) && ((*j)->get_pass_load() >= tr->get_cap()))
			{
                       	    Pls[(*j)->get_plat1()] = (step + 1);
                            //если какой-нибудь из них соединяет сию с конечной, то ставим ей id и выводим сообщение о найденном пути
			    num_set = true;
                        }
			else if (((*j)->get_plat2()->get_name() == tr->get_plat2()->get_name()) && ((*j)->get_pass_load() >= tr->get_cap()))         //на случай соединения со вторым концом перегона
                        {
                            Pls[(*j)->get_plat2()] = (step + 1);
                            num_set = true;
                        }
                    }
                }
            }
            if (num_set == true) break;                               //Если после поиска конечной id_set поменялся на тру, то мы путь нашли, поэтому break
            for(auto i = Pls.begin(); i != Pls.end(); i++)            //проверяем, можем ли расшириться на один слой; на данном моменте id_set будет false, так как путь до конечной мы не нашли
            {
                if((*i).second == step)
                {
                    for (auto j = (*i).first->rws_begin(); j != (*i).first->rws_end(); j++)                                                  //итерируемся по перегонам станции с последнего слоя
                    {
                        if (((*j)->get_pass_load() >= tr->get_cap()) && (Pls[(*j)->get_plat1()] > (step + 1)))
                        {
                            Pls[(*j)->get_plat1()] = (step + 1);
                            num_set = true;
                        }
                        else if (((*j)->get_pass_load() >= tr->get_cap()) && (Pls[(*j)->get_plat2()] > (step + 1)))
                        {
                            Pls[(*j)->get_plat2()] = (step + 1);
                            num_set = true;
                        }
                    }
                }
            }
            if (num_set == true) step += 1;
        }
        if (Pls[tr->get_plat2()] != (Pls.size() + 1))
        {
            Platform* current = (Platform*)malloc(sizeof(Platform));
            current = tr->get_plat2();
            step = ( Pls[tr->get_plat2()] - 1);
            while(step > 0)
            {
                num_set = false;
                for (auto j = current->rws_begin(); j != current->rws_end(); j++)                                            //итерируемся по перегонам станции с предпоследнего слоя
                {
                    if (((*j)->get_plat1()->get_name() == current->get_name()) && (num_set == false) && ( Pls[(*j)->get_plat2()] == step))
                    {
                        (*j)->set_pass_load((*j)->get_pass_load() - tr->get_cap());
                        current->set_pass_cap( current->get_pass_cap() + tr->get_cap());                                     //меняем пропускаемость у перегона и у станции
                        tr->add_to_route(*j);
                        current = (*j)->get_plat2();
                        step -= 1;
                        num_set = true;
                        break;
                    }
                    else if (((*j)->get_plat2()->get_name() == current->get_name()) && (num_set == false) && ( Pls[(*j)->get_plat1()] == step))
                    {
                        (*j)->set_pass_load((*j)->get_pass_load() - tr->get_cap());
                        current->set_pass_cap( current->get_pass_cap() + tr->get_cap());
                        tr->add_to_route(*j);
                        current = (*j)->get_plat1();
                        step -= 1;
                        num_set = true;
                        break;
                    }
                }
            }
	    current->set_pass_cap( current->get_pass_cap() + tr->get_cap());
        }
    }
    else
    {
        for(auto i = Pls.begin(); i != Pls.end(); i++)
        {
            (*i).second = (Pls.size() + 1);
            if((*i).first->get_name() == tr->get_plat1()->get_name()) (*i).second = 1;
        }
        while(num_set == true)
        {
            num_set = false;
            for(auto i = Pls.begin(); i != Pls.end(); i++)                                                                      //проверяем, можем ли с текущего слоя доехать до конечной
            {
                if((*i).second == step)
                {
                    for (auto j = (*i).first->rws_begin(); j != (*i).first->rws_end(); j++)                                     //итерируемся по перегонам станции с последнего слоя
                    {
                        if (((*j)->get_plat1()->get_name() == tr->get_plat2()->get_name()) && ((*j)->get_cargo_load() >= tr->get_cap()))
                        {
                            Pls[(*j)->get_plat1()] = (step + 1);
                            //если какой-нибудь из них соединяет сию с конечной, то ставим ей id и выводим сообщение о найденном пути
                            num_set = true;
                        }
                        else if (((*j)->get_plat2()->get_name() == tr->get_plat2()->get_name()) && ((*j)->get_cargo_load() >= tr->get_cap()))  //на случай соединения со вторым концом перегона
                        {
                            Pls[(*j)->get_plat2()] = (step + 1);
                            num_set = true;
                        }
                    }
                }
            }
            if (num_set == true) break; 
	    for(auto i = Pls.begin(); i != Pls.end(); i++)
            {
                if((*i).second == step)
                {
                    for (auto j = (*i).first->rws_begin(); j != (*i).first->rws_end(); j++)                                     //итерируемся по перегонам станции с последнего слоя
                    {
                        if (((*j)->get_cargo_load() >= tr->get_cap()) && (Pls[(*j)->get_plat1()] > (step + 1)) && ((*j)->get_plat1()->get_cargo_cap() >= 0))
                        {
                            Pls[(*j)->get_plat1()] = (step + 1);
                            num_set = true;
                        }
                        else if (((*j)->get_pass_load() >= tr->get_cap()) && (Pls[(*j)->get_plat2()] > (step + 1)) && ((*j)->get_plat2()->get_cargo_cap() >= 0))
                        {
                            Pls[(*j)->get_plat2()] = (step + 1);                                                               //Так как поездо грузовой, надо проверять, а в станцию ли мы едем
                            num_set = true;
                        }
                    }
                }
            }
            if (num_set == true) step += 1;
        }
        if (Pls[tr->get_plat2()] != (Pls.size() + 1))
        {
            Platform* current = (Platform*)malloc(sizeof(Platform));
            current = tr->get_plat2();
            step = ( Pls[tr->get_plat2()] - 1);
            while(step > 0)
            {
                num_set = false;
                for (auto j = current->rws_begin(); j != current->rws_end(); j++)                                              //итерируемся по перегонам станции с предпоследнего слоя
                {
                    if (((*j)->get_plat1()->get_name() == current->get_name()) && (num_set == false) && ( Pls[(*j)->get_plat2()] == step))
                    {
                        (*j)->set_cargo_load((*j)->get_cargo_load() - tr->get_cap());
                        current->set_cargo_cap( current->get_cargo_cap() + tr->get_cap());                                     //меняем пропускаемость у перегона и у станции
                        tr->add_to_route(*j);
                        current = (*j)->get_plat2();
                        step -= 1;
                        num_set = true;
                        break;
                    }
                    else if (((*j)->get_plat2()->get_name() == current->get_name()) && (num_set == false) && ( Pls[(*j)->get_plat1()] == step))
                    {
                        (*j)->set_cargo_load((*j)->get_cargo_load() - tr->get_cap());
                        current->set_cargo_cap( current->get_cargo_cap() + tr->get_cap());
                        tr->add_to_route(*j);
                        current = (*j)->get_plat1();
                        step -= 1;
                        num_set = true;
                        break;
                    }
                }
            }
	    current->set_cargo_cap( current->get_cargo_cap() + tr->get_cap());
        }
    }
}
