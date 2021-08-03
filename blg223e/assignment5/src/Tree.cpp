/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 3 August 2021
 */

#include "Tree.h"
#include "Node.h"
#include <string>

Tree::Tree()
{
    this->size = 1;
    root = new Node();
}

Tree::~Tree()
{
    delete this->root;
}

void Tree::add_result(int state, int letter_size)
{
    Node* tmp = this->root;
    for (int i = letter_size; i > 0; i--) {
        if (state & (1 << i)) {
            if (tmp->get_one() == NULL) {
                tmp->set_one(new Node());
                this->size++;
            }
            tmp = tmp->get_one();
        } else {
            if (tmp->get_zero() == NULL) {
                tmp->set_zero(new Node());
                this->size++;
            }
            tmp = tmp->get_zero();
        }
    }
    int res = (state & 1) != 0;
    tmp->set_data(res);
}

void Tree::prune_tree(Node* parent)
{
    if (parent->get_one() == NULL) {
        // just 'one' child is controlled,
        // that's why if node is leaf node, there are neigher 'one' child nor 'zero' child
        // shortly it be assumed that tree is perfect binary tree
        return;
    }

    prune_tree(parent->get_one());
    prune_tree(parent->get_zero());

    Node* one = parent->get_one();
    Node* zero = parent->get_zero();

    if (one->get_data() == -1 || zero->get_data() == -1)
        return;

    if (one->get_data() == zero->get_data()) {
        parent->set_data(one->get_data());
        delete one;
        delete zero;
        parent->set_one(NULL);
        parent->set_zero(NULL);
        this->size -= 2;
    }
}

Node* Tree::get_root()
{
    return this->root;
}

int Tree::get_size()
{
    return this->size;
}
