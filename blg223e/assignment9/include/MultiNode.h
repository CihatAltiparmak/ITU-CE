#ifndef _MULTINODE_H_
#define _MULTINODE_H_

#include <vector>

using namespace std;

class MultiNode {
private:
    int height;
    int data;
    vector<MultiNode*> next;

public:
    MultiNode();
    // ~MultiNode();
    void set_data(int);
    int  get_data();
    void set_height(int);
    int  get_height();
    void set_next(int, MultiNode*);
    MultiNode* get_next(int);

};

#endif
