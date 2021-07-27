#pragma once
#include "linked_list.hpp"
#include "patient.hpp"

class hash_map{

private:

    linked_list** arr;
    int size;

public:

    hash_map(int size);

    void insert(patient& p);

    void update(int id, int new_health);

    patient* get(int id);

    void remove(int id);

    patient& pop(int id);

    int calculate_index(int id);
};