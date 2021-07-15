/*
 * @Author: Cihat Kurtuluş Altıparmak
 * Student Name: Cihat Kurtuluş Altıparmak
 * Student ID: 150200105
 * Date: 15 July 2021
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include "ExpandingArray.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        return 1;
    }
    

    ifstream file (argv[1]);
    if (!file.is_open())
        return 1;

    string line;
    getline(file, line);
    stringstream s (line);
    int capacity; s >> capacity;
    
    ExpandingArray erray(capacity);
    while(getline(file, line)) {
        stringstream converter (line);
        string command;
        converter >> command;
        if (command == "SS") {
            string strategy;
            converter >> strategy;
            erray.set_strategy(strategy);
        } else if (command == "ADD") {
            int a;
            while (converter >> a)
                erray.add(a);
        } else if (command == "REMOVE") {
            int a;
            while (converter >> a)
                erray.remove(a);        
        } else if (command == "GC") {
            cout << erray.get_current_capacity() << " ";
        } else if (command == "GS") {
            cout << erray.get_current_size() << " ";
        } else if ( command == "PRINT") {
            erray.print(); 
        } else if (command == "CONTAINS") {
            int x;
            converter >> x;
            int result = erray.is_contain(x);
            if (result == -1)
                cout << x << " is not in the array ";
            else
                cout << x << " is at index " << result << " ";
        } else if (command == "CLEAR") {
            erray.clear();
        }

    }    
}
