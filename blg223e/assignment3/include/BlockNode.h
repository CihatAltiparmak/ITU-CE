/* @author
 * Student Name: Cihat Kurtuluş Altıparmak
 * Student ID: 150200105
 * Date: 27 July 2021
 */

#ifndef _BLOCK_NODE_H_
#define _BLOCK_NODE_H_

#include <iostream>
#include "Node.h"

using namespace std;

class BlockNode {
    private:
        Node*      trans_head;
        Node*      trans_tail;
        string     prev_hash;
        string     trans;
        BlockNode* next;        
    public:
        BlockNode();
        ~BlockNode();

        void       set_trans_head(Node*);
        Node*      get_trans_head();

        void       set_prev_hash(string);
        string     get_prev_hash();

        void       set_next(BlockNode*);
        BlockNode* get_next();

        void        set_trans(string);
        string      get_trans();

        void        add(Node*);
};

#endif
