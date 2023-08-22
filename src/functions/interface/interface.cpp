#include "./interface.hpp"

bool is_number(string str){
    for(int i = 0; i < str.length(); i++)
        if(!isdigit(str[i]))
            return false;
    return true;
 }

int ranking_size(string command){
    int i = 3;
    while(command[i+1] != ' ' && command[i+1] != '\0') i++;
    i -= 2;
    if(is_number(command.substr(3,i)))
        return stoi(command.substr(3,i));
    return 0;
}

vector<string> read_args(string command){
    stringstream s(command);
    string element;
    vector<string> args;

    while(getline(s,element,'\'')){
        cout << 'a' << endl;
        getline(s,element,'\'');
        args.push_back(element);
    }
    return args;
}

bool is_position(string position){
    if (position != "GK"  && position != "RB" && position != "RWB" && position != "CB" && position != "LB" && position != "LWB" &&
        position != "CDM" && position != "CM" && position != "CAM" && position != "RM" && position != "RW" && position != "LM"  &&
        position != "LW"  && position != "RF" && position != "CF"  && position != "LF" && position != "ST"){
            return false;
    }
    return true;
}

bool has_position(vector<string> args){
    for(int i = 0; i < args.size(); i++)
        if(is_position(args[i]))
            return true;
    return false;
}

void print_players_table(vector<unsigned int> ids, HashPlayers *hash){
    Player *p;
    if(ids.size() == 0)
        cout << "Nenhum jogador encontrado!" << endl;
    for(int i = 0; i < ids.size(); i++){
        p = hash->query(ids[i]);
        if(p != NULL){
            cout << p->id << '\t' << p->name << '\t';
            for(int j = 0; j < p->positions.size() - 1; j++)
                cout << p->positions[j] << ", ";
            cout << p->positions[p->positions.size() - 1] << '\t' << p->rating << '\t' << p->rating_count << endl;
        }
    }
}