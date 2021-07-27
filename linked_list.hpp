#pragma once
#include "patient.hpp"

class linked_list{

public:

    class node{

    public:

        patient* value;
        node* next;
        node* prev;

        node(patient& value);
        node(const node& node_t);
    };

    linked_list();

    linked_list(patient& p);

    void add_to_tail(patient& p);

    node* popHead();

    node* popNode(int id);

    node* getNode(int id);

    node* getHead(){
        return head;
    }

private:

    node* head;

};