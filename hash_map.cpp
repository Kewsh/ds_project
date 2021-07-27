#include "hash_map.hpp"

hash_map::hash_map(int size): size(size){
    arr = new linked_list*[size];
    for (int i = 0; i < size; i++)
        arr[i] = new linked_list();
}

void hash_map::insert(patient& p){
    int index = calculate_index(p.id);
    arr[index]->add_to_tail(p);
}

void hash_map::update(int id, int new_health){
    int index = calculate_index(id);
    arr[index]->getNode(id)->value->health = new_health;
}

patient* hash_map::get(int id){

    linked_list* target_list = arr[calculate_index(id)];
    linked_list::node* target_node = target_list->getNode(id);

    if (target_node == nullptr) return nullptr;
    else return target_node->value;
}

void hash_map::remove(int id){
    pop(id);
}

patient& hash_map::pop(int id){
    int index = calculate_index(id);
    linked_list::node* popped_node = arr[index]->popNode(id);
    patient* p = popped_node->value;
    delete popped_node;
    return *p;
}

int hash_map::calculate_index(int id){
    return id & (size - 1);
}
