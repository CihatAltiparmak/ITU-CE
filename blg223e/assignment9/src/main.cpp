#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <random>

#include "SkipList.h"
#include "MultiNode.h"

using namespace std;

int main (int argc, char* argv[])
{

    fstream f;
    f.open(argv[1], ios::in);
    if (!f.is_open()) {
        cout << "File couldn't be read" << endl;
        return 1;
    }

    string line;
    getline(f, line);
    stringstream s1(line);
    int seed;
    s1 >> line >> seed;
    srand(seed);

    getline(f, line);
    stringstream s2(line);
    int height;
    s2 >> line >> height;
    SkipList skip_list(height);

    while (getline(f, line)) {
        stringstream fcin(line);
        string cmd; fcin >> cmd;
        
        // cout << "--------dbg--------"  << endl;
        // cout << "pre: ";
        //skip_list.print(); 
        if (cmd == "ADD") {
            int element;
            while (fcin >> element)
                skip_list.add(element);
        } else if (cmd == "DEL") {
            int element;
            while (fcin >> element)
                skip_list.remove(element);
        } else if (cmd == "CLEAR") {
            skip_list.clear();
        } else if (cmd == "CONTAINS") {
            int element;
            while (fcin >> element) {
                cout << element << " ";
                if (skip_list.is_contain(element)) {
                    cout << "IN ";
                } else {
                    cout << "OUT ";
                }
            }
        } else if (cmd == "PRINT") {
            skip_list.print();
        }
        //cout << "fin: ";
        //skip_list.print();
        //cout << "-------------------" << endl;
    }
    return 0;
}
