/* @author
 * Student Name: Cihat Kurtuluş Altıparmak
 * Student ID: 150200105
 * Date: 27 July 2021
 */

#include <iostream>
#include "BlockNode.h"

using namespace std;

BlockNode::BlockNode() { 
    this->trans_head = NULL; 
    this->trans_tail = NULL;

    this->prev_hash = "0";
    this->trans; 
    this->next = NULL; 
}

BlockNode::~BlockNode(){
    if (this->next != NULL) {
        delete this->trans_head;
        delete this->next;
    }
}

void BlockNode::set_trans_head(Node* trans_head) {
    this->trans_head = trans_head;
}


Node* BlockNode::get_trans_head() {
    return this->trans_head;
}
void BlockNode::set_prev_hash(string prev_hash) {
    this->prev_hash = prev_hash;
}

string BlockNode::get_prev_hash() {
    return this->prev_hash;
}
void BlockNode::set_next(BlockNode* next) {
    this->next = next;
}

BlockNode* BlockNode::get_next() {
    return this->next;
}


void BlockNode::set_trans(string trans) {
    this->trans = trans;
}


/* @param None
 * @return the transaction string
 */
string BlockNode::get_trans() {
    return this->trans;
}

/* @param Node the node to add
 * @return None
 */
void BlockNode::add(Node* node) {
    if (this->trans_head == NULL) {
        this->trans_head = node;
        this->trans_tail = node;
    } else {
        this->trans_tail->set_next(node);
        this->trans_tail = this->trans_tail->get_next();
    }
}
