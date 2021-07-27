#pragma once
#include <iostream>
#include <string>
#include <climits>
using namespace std;

#include "linked_list.hpp"
#include "hash_map.hpp"
#include "patient.hpp"

#define MAX_PATIENT_COUNT 1000000

linked_list* queue_g;
hash_map* hash_map_g;

string* parse_input(string command);

void add(int id, int health);

void update(int id, int health);

void serve_first();

void serve_sickest();

void process(string* tokens);
