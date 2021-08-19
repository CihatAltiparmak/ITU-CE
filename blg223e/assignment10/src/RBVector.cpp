/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 19 August 2021
 */

#include "RBVector.h"
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

RBVector::RBVector(int branching_size)
{
    this->branching_size = branching_size;
    this->base = __builtin_ctz((uint32_t)this->branching_size);
    this->depth = 0;
    this->count = 0;
    this->root = new RBNode(this->branching_size);
}

RBVector::~RBVector()
{
    delete this->root;
}

void RBVector::remove(string val)
{
    int index = this->find(val);

    if (index != -1)
        this->remove_by_index(index);
}

void RBVector::remove_by_index(int index)
{
    for (int i = index; i < this->count - 1; i++) {
        string data = this->_get(i + 1, this->root, depth);
        this->update(i, data);
    }

    this->update(this->count - 1, "");
    this->count--;
}

string RBVector::_get(int index, RBNode* head, int level)
{
    int direction = (index >> (base * level)) & (this->branching_size - 1);

    if (level == 0)
        return head->get_data(direction);

    return this->_get(index, head->get_next(direction), level - 1);
}

void RBVector::update(int index, string val)
{
    this->_update(index, val, this->root, this->depth);
}

void RBVector::_update(int index, string& val, RBNode* head, int level)
{
    int direction = (index >> (base * level)) & (this->branching_size - 1);

    if (level == 0) {
        head->set_data(direction, val);
        return;
    }

    if (head->get_next(direction) == NULL)
        head->set_next(direction, new RBNode(this->branching_size));

    this->_update(index, val, head->get_next(direction), level - 1);
}

void RBVector::push(string val)
{
    if (this->count / this->branching_size == (1 << (depth * base)))
        this->_push(val);
    else
        this->update(this->count, val);

    this->count++;
}

void RBVector::_push(string& val)
{

    this->depth++;
    RBNode* new_root = new RBNode(this->branching_size);
    new_root->set_next(0, this->root);
    new_root->set_next(1, new RBNode(this->branching_size));
    this->root = new_root;

    RBNode* start = this->root->get_next(1);
    int level = this->depth - 1;
    while (level > 0) {
        start->set_next(0, new RBNode(this->branching_size));
        start = start->get_next(0);
        level--;
    }
    start->set_data(0, val);
}

void RBVector::print()
{
    this->_print(this->root, this->depth);
}

void RBVector::_print(RBNode* node, int level)
{
    if (level == 0) {
        for (int i = 0; i < node->get_cur_size(); i++) {
            cout << node->get_data(i) << " ";
        }
        return;
    }

    for (int i = 0; i < node->get_cur_size(); i++)
        this->_print(node->get_next(i), level - 1);
}

void RBVector::clear()
{
    delete this->root;

    this->depth = 0;
    this->count = 0;
    this->root = new RBNode(this->branching_size);
}

int RBVector::find(string val)
{
    int index = 0;
    return this->_find(val, this->root, depth, index);
}

int RBVector::_find(string& val, RBNode* node, int level, int& index)
{
    if (node == NULL)
        return -1;
    if (level == 0) {
        for (int i = 0; i < node->get_cur_size(); i++) {
            if (node->get_data(i) == val)
                return index;
            else
                index++;
        }
        return -1;
    }

    for (int i = 0; i < node->get_cur_size(); i++) {
        int res = this->_find(val, node->get_next(i), level - 1, index);
        if (res >= 0)
            return res;
    }
    return -1;
}

int RBVector::get_gnc()
{
    int total = 1;
    int node_count = ceil((double)this->count / this->branching_size);
    int up = log2(node_count) / log2(this->branching_size);
    int x1 = pow(this->branching_size, up);
    int x2 = node_count - x1;

    if (node_count == 1)
        return 1;
    if (x2 == 0)
        total -= 1;
    for (int i = 0; i < depth; i++) {
        total += x1 + x2;
        x1 = ceil((double)x1 / this->branching_size);
        x2 = ceil((double)x2 / this->branching_size);
    }
    return total;
}
