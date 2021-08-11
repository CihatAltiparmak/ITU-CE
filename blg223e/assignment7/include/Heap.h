/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 10 August 2021
 */

#include <functional>

#ifndef _HEAP_H_
#define _HEAP_H_

class Heap{ 
    private: 
        int capacity; 
        int size; 
        int* arr; 
        std::function<int(int,int)> minmax; 

        int find(int);

    public: 
        Heap(int,std::function<int(int,int)>); 
        ~Heap(); 

        void add(int);
        void del(int);
        void fill_array(int*, int);
        void build();
        void print();
        int  up_heapify(int);
        int  down_heapify(int);
        void sort();
};

#endif
