#include "trie_players.h"

void Trie::insert(string name, unsigned int id){
    Node* current = root;
    Node* aux;
    for(int i = 0; i < name.length(); i++){
        aux = is_child(name[i], current->tail);
        if(aux == NULL){
            aux = new Node;
            aux->c = name[i];
            current->tail.push_back(aux);
        }
        if(i == name.length() - 1) // last char
            aux->ids.push_back(id);
        current = aux;
    }
}

Node* Trie::is_child(char c, vector<Node *> child){
    for(int j = 0; j < child.size(); j++){
        if(c == child[j]->c){
            return child[j];
        }
    }
    return NULL;
}

vector<unsigned int> Trie::query(string prefix){
    Node* current = root;
    Node* aux;
    vector<unsigned int> v;

    for(int i = 0; i < prefix.length(); i++){
        current = is_child(prefix[i], current->tail);
        if(current == NULL)
            return v;
    }

    v.insert(v.end(), current->ids.begin(), current->ids.end());
    v = query_aux(current->tail, v);
    return v;
}

vector<unsigned int> Trie::query_aux(vector<Node*> nodes, vector<unsigned int> v){
    Node* aux;
    for(int i = 0; i < nodes.size(); i++){
        v.insert(v.end(), nodes[i]->ids.begin(), nodes[i]->ids.end());
        v = query_aux(nodes[i]->tail, v);
    }
    return v;
}