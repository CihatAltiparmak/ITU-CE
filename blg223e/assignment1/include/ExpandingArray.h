/*
 * @Author: Cihat Kurtuluş Altıparmak
 * Student Name: Cihat Kurtuluş Altıparmak
 * Student ID: 150200105
 * Date: 15 July 2021
 */

#include <iostream>

using namespace std;

class ExpandingArray {
public:
    int arr[1000000];
    int is_contain(int x);
    void print();
    void add(int);
    void remove(int);
    int get_current_capacity();
    int get_current_size();
    void clear();
    void set_strategy(string);
    ExpandingArray(int);
private: 
    int capacity;
    int size;
    string strategy;
    int initial_capacity;
    void increase_capacity_by(string);
    void decrease_capacity_by(string);
};
