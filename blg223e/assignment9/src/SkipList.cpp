#include "SkipList.h"
#include "MultiNode.h"

#include <iostream>

using namespace std;

const int inf = 1 << 31 - 1;

SkipList::SkipList(int height)
{
    this->head = new MultiNode();
    this->head->set_data(-inf);
    this->head->set_height(height);

    this->tail = new MultiNode();
    this->tail->set_data(inf);
    this->tail->set_height(height); 

    for (int i = 0; i < height; i++)
        this->head->set_next(i, this->tail);
    
    this->height = height;
}

void SkipList::add(int x)
{
    int level = this->height - 1;
    MultiNode* back[this->height];
    
    MultiNode* tmp = this->head;
    while (level >= 0) {
        int data = tmp->get_next(level)->get_data();
        if (data > x) {
            back[level] = tmp;
            level--;
        } else if (data == x) {
            return; 
        } else {
            tmp = tmp->get_next(level);
        }
    }

    MultiNode* node = new MultiNode();
    node->set_height(rand() % this->height + 1);
    node->set_data(x); 

    for (int i = 0; i < node->get_height(); i++) { 
        MultiNode* left = back[i];
        MultiNode* right = back[i]->get_next(i);
        left->set_next(i, node);
        node->set_next(i, right);
    } 

}


void SkipList::remove(int x)
{
    int level = this->height - 1;
    MultiNode** back = new MultiNode* [this->height];
    
    MultiNode* tmp = this->head;
    while (level >= 0) {
        int data = tmp->get_next(level)->get_data();
        if (data >= x) {
            back[level] = tmp;
            level--;
        } else {
            tmp = tmp->get_next(level);
        }
    }

    if (tmp->get_next(0)->get_data() == inf)
        return;

    MultiNode* deleted_node = NULL;
    for (int i = 0; i < this->height; i++) {
        MultiNode* node = back[i]->get_next(i);

        if (node->get_data() == x) {
            back[i]->set_next(i, node->get_next(i));
            deleted_node = node;
        }
    }

    delete deleted_node;
}

bool SkipList::is_contain(int x)
{
    int level = this->height - 1;
    
    MultiNode* tmp = this->head;
    while (level >= 0) {
        int data = tmp->get_next(level)->get_data();
        if (data > x) {
            level--;
        } else if (data == x) {
            return true;
        } else {
            tmp = tmp->get_next(level);
        }
    }
    
    return false;
}

void SkipList::clear()
{
    MultiNode* tmp = this->head->get_next(0);
    while (tmp->get_next(0) != NULL) {
        MultiNode* deleted_node = tmp;
        tmp = tmp->get_next(0);
        delete deleted_node;
        deleted_node = NULL;
    }

    for (int i = 0; i < height; i++)
        this->head->set_next(i, this->tail);
}

void SkipList::print() 
{
    for (int i = 0; i < this->height; i++) {
        MultiNode* tmp = this->head->get_next(i);
        cout << "L" << i << ": ";
        while (tmp->get_next(i) != NULL) {
            cout << tmp->get_data() << " ";
            tmp = tmp->get_next(i);
        }
    }   
}


