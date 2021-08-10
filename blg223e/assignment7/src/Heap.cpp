/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 10 August 2021
 */

#include <functional>
#include <iostream>

#include "Heap.h"

// #include <algorithm>
using namespace std;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

Heap::Heap(int capacity, std::function<int(int, int)> minmax) 
{
    this->size = 0;
    this->capacity = capacity;
    this->arr = new int[capacity];
    this->minmax = minmax;
}

Heap::~Heap() 
{
    delete this->arr;
}

void Heap::add(int val) 
{
    if (this->size == this->capacity)
        return;
    int pos = this->size + 1;
    this->arr[pos] = val;
    
    while (pos != 1) {
        int res = this->minmax(this->arr[pos >> 1], this->arr[pos]);
        if (!res) {
            swap(this->arr[pos >> 1], this->arr[pos]);
        } else {
            break;
        }
        pos >>= 1;
    } 
    
    this->size++; 
    //cout << "dbg: [add] " << is_heap(arr + 1, arr + this->size+1) << endl;
}

void Heap::del(int val) 
{
    int pos = this->find(val);
    
    if (pos == -1)
        return; 

    swap(this->arr[pos], this->arr[this->size]);
    this->size--;   
    this->heapify(pos);
 
    // cout << "dbg: [del] " << is_heap(arr + 1, arr + this->size+1) << endl;
}

int Heap::find(int val) 
{
    for (int i = 1; i <= this->size; i++) {
        if (this->arr[i] == val)
            return i;
    }
    return -1;
}

void Heap::fill_array(int* arr, int size)
{
    for (int i = size - 1; i >= 0; i--) {
        this->arr[size - i] = arr[i]; 
    }
    this->size = size;
}

void Heap::build()
{
    for (int i = (this->size >> 1); i > 0; i--)
        this->heapify(i);
}

void Heap::print() 
{
    for (int i = 1; i <= this->size; i++) {
        cout << this->arr[i];
        if (i != this->size)
            cout << " ";
    }
}

void Heap::heapify(int i) 
{
    int left  = i << 1;
    int right = i << 1 | 1;
    int chosen = i;
    if (left <= this->size && 
        !this->minmax(this->arr[chosen], this->arr[left]))
        chosen = left;
    
    if (right <= this->size && 
             !this->minmax(this->arr[chosen], this->arr[right]))
        chosen = right;

    if (chosen != i) {
        swap(this->arr[i], this->arr[chosen]); 
        this->heapify(chosen);
    }
}

void Heap::sort() {
    int length = this->size;
    for (int i = 1; i <= length; i++) {
        int val = this->arr[1];
        cout << val;
        if (i != length)
            cout << " ";
        this->del(val);
    }
}
