#include "linked_list.hpp"

linked_list::node::node(patient& value): value(&value){}

linked_list::node::node(const node& node_t){
        this->value = node_t.value;
        this->next = node_t.next;
        this->prev = node_t.prev;
}

linked_list::linked_list(): head(nullptr){}

linked_list::linked_list(patient& p){
    node* node_t = new node(p);
    node_t->next = node_t;
    node_t->prev = node_t;
    head = node_t;
}

void linked_list::add_to_tail(patient& p){
    node* new_tail = new node(p);

    if (head == nullptr){
        new_tail->next = new_tail;
        new_tail->prev = new_tail;
        head = new_tail;
        return;
    }

    head->prev->next = new_tail;
    new_tail->prev = head->prev;
    new_tail->next = head;
    head->prev = new_tail;
}

linked_list::node* linked_list::popHead(){
    node* temp = nullptr;
    if (head == nullptr);
    else if (head->next == head){
        temp = head;
        head = nullptr;
    }
    else{
        head->next->prev = head->prev;
        head->prev->next = head->next;
        temp = head;
        head = head->next;
    }
    return temp;
}

linked_list::node* linked_list::popNode(int id){

    node* target_node = getNode(id);

    if (target_node == nullptr)
        return nullptr;
    if (target_node == head)
        return popHead();
    
    target_node->prev->next = target_node->next;
    target_node->next->prev = target_node->prev;
    return target_node;
}

linked_list::node* linked_list::getNode(int id){

    if (head == nullptr)
        return nullptr;

    if (head->next == head){
        if (head->value->id != id) return nullptr;
        else return getHead();
    }

    node* node_iter = head;
    do{
        if (node_iter->value->id == id){
            return node_iter;
        }
        node_iter = node_iter->next;
    }while(node_iter != head);
    
    return nullptr;
}
