/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 19 August 2021
 */

#include "RBNode.h"
#include <iostream>
#include <string>

using namespace std;

RBNode::RBNode(int branching_size)
{
    this->branching_size = branching_size;
    this->cur_size = 0;

    this->next = new RBNode*[this->branching_size];
    this->data = new string[this->branching_size];

    for (int i = 0; i < this->branching_size; i++) {
        this->next[i] = NULL;
        this->data[i] = "";
    }
}

RBNode::~RBNode()
{
    for (int i = 0; i < this->branching_size; i++) {
        if (this->next[i] != NULL)
            delete this->next[i];
    }

    if (this->data != NULL)
        delete[] this->data;

    if (this->next != NULL)
        delete[] this->next;
}

void RBNode::set_branching_size(int branching_size)
{
    this->branching_size = branching_size;
}

int RBNode::get_branching_size()
{
    return this->branching_size;
}

void RBNode::set_cur_size(int cur_size)
{
    this->cur_size = cur_size;
}

int RBNode::get_cur_size()
{
    return this->cur_size;
}

void RBNode::set_data(int index, string data)
{
    if (index >= this->cur_size)
        this->cur_size++;
    if (data == "")
        this->cur_size--;
    this->data[index] = data;
}

string RBNode::get_data(int index)
{
    return this->data[index];
}

void RBNode::set_next(int index, RBNode* node)
{
    if (index >= this->cur_size)
        this->cur_size++;
    this->next[index] = node;
}

RBNode* RBNode::get_next(int index)
{
    return this->next[index];
}

bool RBNode::is_full()
{
    return this->cur_size == this->branching_size;
}
