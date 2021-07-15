/*
 * @Author: Cihat Kurtuluş Altıparmak
 * Student Name: Cihat Kurtuluş Altıparmak
 * Student ID: 150200105
 * Date: 15 July 2021
 */

#include <math.h>
#include <iostream>
#include "ExpandingArray.h"

using namespace std;

ExpandingArray::ExpandingArray(int capacity) {  
    this->initial_capacity = capacity;
    this->strategy = "TWICE";
    this->capacity = capacity;
    this->size = 0;
}

void ExpandingArray::add(int x) {
    this->arr[this->size] = x;
    this->size += 1;
    this->increase_capacity_by(this->strategy); 
}

void ExpandingArray::remove(int x) {
    bool is_found = false;
    for (int i = 0; i < this->size; i++) {
        if (!is_found && this->arr[i] == x) {
            is_found = true;
            continue;
        }

        if (is_found) {
            arr[i -1] = arr[i];
        }
    }
    if (is_found) {
        this->size -= 1;
        this->decrease_capacity_by(this->strategy);
    }
}

int ExpandingArray::get_current_size() {
    return this->size;
}

int ExpandingArray::get_current_capacity() {
    return this->capacity;
}

void ExpandingArray::clear() {
    this->capacity = this->initial_capacity;
    this->size = 0;
}

void ExpandingArray::increase_capacity_by(string strategy) {
    if (this->size <= this->capacity)
        return;
    if (strategy == "TWICE") {
        this->capacity <<= 1;
    } else if (strategy == "LOG") {
        this->capacity += (int)log2(this->capacity);
    } else if (strategy == "CAP_BY_CAP"){
        this->capacity += this->initial_capacity;
    }
}

void ExpandingArray::decrease_capacity_by(string strategy) {
    if (strategy == "TWICE") {
        if (this->size <= this->capacity / 2)
            this->capacity >>= 1;
    } else if (strategy == "LOG") {
        int rm = log2(this->capacity);
        if (this->size <= this->capacity - rm)   
            this->capacity -= rm;   
     } else if (strategy == "CAP_BY_CAP"){
        if(this->size <= this->capacity - this->initial_capacity)
            this->capacity -= this->initial_capacity;
    }
}

int ExpandingArray::is_contain(int x) {
    for (int i = 0; i < this->size; i++) {
        if (this->arr[i] == x)
            return i;
    }
    return -1;
}

void ExpandingArray::print() {
    for (int i = 0; i < this->size; i++) {
        cout << this->arr[i] << " ";
    }
}

void ExpandingArray::set_strategy(string strategy) {
    this->strategy = strategy;
}
