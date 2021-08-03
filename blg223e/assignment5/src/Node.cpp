/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 3 August 2021
 */

#include "Node.h"
#include <string>

Node::Node()
{
    this->data = -1;
    this->one = NULL;
    this->zero = NULL;
}

Node::~Node()
{
    if (this->one != NULL)
        delete this->one;
    if (this->zero != NULL)
        delete this->zero;
}

void Node::set_one(Node* one)
{
    this->one = one;
}

Node* Node::get_one()
{
    return this->one;
}

void Node::set_zero(Node* zero)
{
    this->zero = zero;
}

Node* Node::get_zero()
{
    return this->zero;
}

void Node::set_data(int data)
{
    this->data = data;
}

int Node::get_data()
{
    return this->data;
}
