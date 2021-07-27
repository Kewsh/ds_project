#include "main.hpp"

void add(int id, int health){   // O(1)
    patient* p = new patient(id , health);
    queue_g->add_to_tail(*p);
    hash_map_g->insert(*p);
}

void update(int id, int health){    // O(1)
    patient* p = hash_map_g->get(id);
    p->health = health;
}

void serve_first(){     // O(1)
    
    linked_list::node* target_node = queue_g->popHead();
    patient* p = target_node->value;
    hash_map_g->remove(p->id);
    
    cout << p->id << ' ' << p->health << endl;

    delete target_node;
    delete p;
}

void serve_sickest(){   // O(n)

    linked_list::node* node_iter = queue_g->getHead();
    linked_list::node* target_node = nullptr;
    int minimum_health = INT_MAX;

    do{
        if (node_iter->value->health < minimum_health){
            minimum_health = node_iter->value->health;
            target_node = node_iter;
        }
        node_iter = node_iter->next;
    }while(node_iter != queue_g->getHead());

    linked_list::node* popped_node = queue_g->popNode(target_node->value->id);
    patient* sickest = popped_node->value;
    hash_map_g->remove(sickest->id);

    cout << sickest->id << ' ' << sickest->health << endl;

    delete popped_node;
    delete sickest;
}

string* parse_input(string command){

    string delimiter = " ";
    size_t pos = 0;
    string* tokens = new string[20];
    int index = 0;

    while ((pos = command.find(delimiter)) != string::npos) {
        tokens[index++] = command.substr(0, pos);
        command.erase(0, pos + delimiter.length());
    }

    tokens[index++] = command;
    tokens[index] = "\0";
    return tokens;
}

void process(string* tokens){

    if (tokens[0] == "Add"){
        add(stoi(tokens[1]), stoi(tokens[2]));
        return;
    }

    if (tokens[0] == "Serve"){

        if (tokens[1] == "First")
            serve_first();
        else if (tokens[1] == "Sickest")
            serve_sickest();
        return;
    }

    else if (tokens[0] == "Update")
        update(stoi(tokens[1]), stoi(tokens[2]));
}

int main(){

    queue_g = new linked_list();
    hash_map_g = new hash_map(MAX_PATIENT_COUNT);
    string input;

    while(true){
        getline(cin, input);
        string* tokens = parse_input(input);
        process(tokens);
    }
    return 0;
}
