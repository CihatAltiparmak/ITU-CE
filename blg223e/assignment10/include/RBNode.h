/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 19 August 2021
 */

#ifndef _RB_NODE_H_
#define _RB_NODE_H_

#include <string>

using namespace std;

class RBNode {
    private:
        int branching_size;
        int cur_size;
        string* data;
        RBNode** next;

    public:
        RBNode(int);
        ~RBNode();
        void     set_branching_size(int);
        int      get_branching_size();

        void     set_cur_size(int);
        int      get_cur_size();

        void     set_data(int index, string data);
        string   get_data(int);

        void     set_next(int, RBNode*);
        RBNode*  get_next(int);

        bool     is_full();
        
};
#endif
