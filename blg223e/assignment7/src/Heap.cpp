/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 10 August 2021
 */

#include <functional>
#include <iostream>

#include "Heap.h"

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
    this->size++; 
    pos = this->up_heapify(pos);
    this->down_heapify(pos);

}

void Heap::del(int val) 
{
    int pos = this->find(val);
    
    if (pos == -1)
        return; 

    swap(this->arr[pos], this->arr[this->size]);
    this->size--;   
    pos = this->down_heapify(pos);
    pos = this->up_heapify(pos);
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
        this->down_heapify(i);
}

void Heap::print() 
{
    for (int i = 1; i <= this->size; i++) {
        cout << this->arr[i];
        if (i != this->size)
            cout << " ";
    }
}

int Heap::down_heapify(int i) 
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
        return this->down_heapify(chosen);
    } else
        return i;
}

int Heap::up_heapify(int i) {
    if (i == 1)
        return i;

    int root = i >> 1;
    if (!this->minmax(this->arr[root], this->arr[i])) {
        swap(this->arr[root], this->arr[i]);
        return this->up_heapify(root);
    } else
        return i;
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
