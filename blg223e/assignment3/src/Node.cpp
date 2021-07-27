/* @author
 * Student Name: Cihat Kurtuluş Altıparmak
 * Student ID: 150200105
 * Date: 27 July 2021
 */

#include <iostream>
#include <sstream>
#include "Node.h"

using namespace std;

Node::Node(string from, string to, string amount)
{
    this->next = NULL;
    this->from = from;
    this->to = to;
    stringstream s (amount);
    s >> this->amount;
}

Node::~Node() {
    if (this->next != NULL)
        delete this->next;
}

void Node::set_from(string from) {
    this->from = from;
}

string Node::get_from() {
    return this->from;
}

void Node::set_to(string to) {
    this->to = to;
}

string Node::get_to() {
    return this->to;
}

void Node::set_amount(int amount) {
    this->amount = amount;
}

int Node::get_amount() {
    return this->amount;
}

void Node::set_next(Node* next) {
    this->next = next;
}

Node* Node::get_next() {
    return this->next;
}
