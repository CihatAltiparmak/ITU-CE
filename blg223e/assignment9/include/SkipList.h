#ifndef _SKIPLIST_H_
#define _SKIPLIST_H_

#define INF 

#include "MultiNode.h"

class SkipList {
private:
    MultiNode* head;
    MultiNode* tail;
    int height;
public:
    SkipList(int);
    void add(int);
    void remove(int);
    bool is_contain(int);
    void print();
    void clear();
};

#endif
