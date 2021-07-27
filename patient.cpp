#include "patient.hpp"

patient::patient(){}

patient::patient(int id, int health): id(id), health(health){}

patient::patient(const patient& p): id(p.id), health(p.health){}
