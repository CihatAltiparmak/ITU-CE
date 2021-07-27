/* @author
 * Student Name: Cihat Kurtuluş Altıparmak
 * Student ID: 150200105
 * Date: 27 July 2021
 */
 
#include "BlockList.h"
#include "BlockNode.h"
#include "md5.h"

BlockList::BlockList()
{
    this->head  = NULL;
    this->tail  = NULL;
    this->size  = 0;
}

BlockList::~BlockList() {
    if (this->head != NULL)
        delete this->head;
}

void BlockList::add(BlockNode* blocknode, string trans) {
    /* if there is just one node, there is not tail
     * hence md5 hashing is not available
     */
    if (this->size == 0) {
        blocknode->set_trans(trans);
        this->head = blocknode;
        this->tail = blocknode;
        this->size += 1;
        return;
    }

    MD5 md5;
    blocknode->set_trans(trans);
    blocknode->set_prev_hash(
            md5(this->tail->get_prev_hash() + this->tail->get_trans()));
    this->tail->set_next(blocknode);

    this->tail = this->tail->get_next();
    this->size += 1;
}

void BlockList::clear() {
    if (this->head != NULL)
        delete this->head;
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

string BlockList::print() {
    if (this->size == 0)
        return "NA";

    return this->tail->get_prev_hash();
}

int BlockList::get_size() {
    return this->size;
}

/*
 * @param name the name of individuals
 * @return the gain of the individual
 */
int BlockList::search_for_cost(string name) {
    int res = 0;
    BlockNode* tmp_block = this->head;
    while (tmp_block != NULL) {
        Node* tmp_node = tmp_block->get_trans_head();
        while (tmp_node != NULL) {
            if (tmp_node->get_from() == name)
                res -= tmp_node->get_amount();
            if (tmp_node->get_to() == name)
                res += tmp_node->get_amount();

            tmp_node = tmp_node->get_next();
        }
        tmp_block = tmp_block->get_next();
    }
    return res;
}
