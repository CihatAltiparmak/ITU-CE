/* @author
 * Student Name: Cihat Kurtuluş Altıparmak
 * Student ID: 150200105
 * Date: 27 July 2021
 */

#ifndef _BLOCKLIST_H_
#define _BLOCKLIST_H_

#include "BlockNode.h"

class BlockList {
    private:
        BlockNode* head;
        BlockNode* tail;
        int        size;        
    public:
        BlockList();
        ~BlockList();
        void   add(BlockNode*, string);
        void   clear();
        string print();
        int get_size();
        int search_for_cost(string);
};

#endif
