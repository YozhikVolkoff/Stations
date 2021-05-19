#include"System.h"

extern "C"
{
    System* create_system()
    {
	return new System();
    }

    Platform* find_platform(System *S, char* n)
    {
	return S->find_platform(n);
    }

    Platform* create_platform(System* S, char* n)
    {
	return S->create_platform(n);
    }

    Station* create_station(System* S, char* n)
    {
	return S->create_station(n);
    }

    Railway* create_railway(System* S, char* n1, char* n2, int pass_cap, int cargo_cap)
    {
	return S->create_railway(n1, n2, pass_cap, cargo_cap);
    }

    Train* create_train(System* S, bool is_pass, int cap, char* n1, char* n2)
    {
	return S->create_train(is_pass, cap, n1, n2);
    }

    void trains_go(System* S)
    {
	S->trains_go();
    }

    void dispose_system(System* S)
    {
	delete S;
    }
}
