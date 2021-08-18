#include "MultiNode.h"
#include <vector>
#include <string>

#define inf 1000000009;

using namespace std;

MultiNode::MultiNode()
{
    this->data = inf;
    this->height = 0;
}

/*MultiNode::~MultiNode()
{
    for (int i = 0; i < this->next.size(); i++) {
        if (this->next[i] != NULL)
            delete this->next[i];
    }
}*/

void MultiNode::set_data(int data)
{
    this->data = data;
}

int  MultiNode::get_data()
{
    return this->data;
}

void MultiNode::set_height(int height)
{
    this->height = height;
    this->next.resize(height);
    for (int i = 0; i < height; i++)
        this->next[i] = NULL;
}

int  MultiNode::get_height()
{
    return this->height;
}

void MultiNode::set_next(int level, MultiNode* next_node)
{
    this->next[level] = next_node;
}

MultiNode* MultiNode::get_next(int level)
{
    return this->next[level];
}
