/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 19 August 2021
 */

#ifndef _RB_VECTOR_H_
#define _RB_VECTOR_H_

#include <string>
#include "RBNode.h"

using namespace std;

class RBVector {
    private:
        RBNode* root;
        int    branching_size;
        int    base;
        int    depth;
        int    count;
        void   _push(string&);
        void   _update(int, string&, RBNode*, int);
        void   _print(RBNode*, int);
        int    _find(string&, RBNode*, int, int&);
        string _get(int, RBNode*, int);
    public:
        RBVector(int);
        ~RBVector();
        void remove(string);
        void remove_by_index(int);
        void update(int, string);
        void push(string);
        void print();
        void clear();
        int  find(string);
        int  get_gnc();
};

#endif
