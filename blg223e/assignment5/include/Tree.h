/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 3 August 2021
 */

#ifndef _TREE_H_
#define _TREE_H_

#include "Node.h"
#include <string>

using namespace std;

class Tree {
private:
    Node* root;
    int   size;

public:
    Tree();
    ~Tree();

    void  add_result(int, int);
    void  prune_tree(Node*);
    int   get_size();
    Node* get_root();
};

#endif
