/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 10 August 2021
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <functional>

#include "Heap.h"

using namespace std;

#define CAPACITY 100000000

int arr[CAPACITY];

int is_max(int a, int b) {
    if (a >= b)
        return 1;
    return 0;
        
}

int is_min(int a, int b) {
    if (a <= b)
        return 1;
    return 0;
        
}

int main(int argc, char* argv[]) {

    fstream file;
    file.open(argv[1]);
    if (!file.is_open()) {
        cout << "File was not read" << endl;
        return 1;
    }

    string line; 
    getline(file, line);
    stringstream s(line);
    
    string cmd; s >> cmd;
    function<int(int, int)> func;
    if (cmd == "MAXHEAP")
        func = greater<int>();//is_max;
    else if (cmd == "MINHEAP")
        func = less<int>();

    int capacity; s >> capacity;    
    int size = 0;
    while(s >> arr[size])
        size++;
    
    Heap heap(capacity, func);
    heap.fill_array(arr, size);
    heap.build();
    //heap.print();

    while (getline(file, line)) {
        stringstream fcin(line);
        fcin >> cmd;
        if (cmd == "DEL") {
            int a; fcin >> a;
            heap.del(a);
        } else if (cmd == "ADD") {
            int a; fcin >> a;
            heap.add(a);
        } else if (cmd == "PRINT") {
            heap.print();
        } else if (cmd == "SORT") {
            heap.sort();
        }
    }

    file.close();
    return 0;
}
