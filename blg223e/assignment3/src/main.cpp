/* @author
 * Student Name: Cihat Kurtuluş Altıparmak
 * Student ID: 150200105
 * Date: 27 July 2021
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "md5.h"
#include "BlockList.h"

using namespace std;

typedef struct person {
    string name ;
    int cash;
} person;

bool cmp(person& p1, person& p2) {
    return p1.name <= p2.name;
}

int main(int argc, char* argv[]) {
    
    if (argc != 2)
        return 1;

    fstream f;
    f.open(argv[1], ios::in);
    
    if (!f.is_open())
        return 1;

    BlockList blocks;

    person P[100000];
    int person_num = 0;
    string line;
    getline(f, line);
    
    stringstream s(line);
    while(s>>P[person_num].name>>P[person_num].cash)
        person_num++;

    sort(P, P + person_num, cmp);
    
    while (getline(f, line)) {
        stringstream fcin (line);
        string command; fcin >> command;
        if (command == "BLOCK") {
            
            string result_hash = "";
            string p_from, p_to, cost;
            BlockNode* block_node = new BlockNode();
            while (fcin >> p_from >> p_to >> cost) {  
                Node* new_node = new Node(p_from, p_to, cost);
                block_node->add(new_node);       
                result_hash += p_from + p_to + cost;
            }

            blocks.add(block_node, result_hash); 
        
        } else if (command == "BALANCE") {
            for (int i = 0; i < person_num; i++) {
                int res = blocks.search_for_cost(P[i].name);
                cout << P[i].name << ":" 
                     << P[i].cash + res<< " ";
            }
        } else if (command == "CLEAR") {
            blocks.clear();
        } else if (command == "PRINT") {
            cout << blocks.print() << " ";
        }
    }

    return 0;
}
