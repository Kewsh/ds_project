#pragma once

class patient{

public:

    int id;
    int health;

    patient();

    patient(int id, int health);
    
    patient(const patient& p);
};