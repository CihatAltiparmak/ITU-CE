/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 3 August 2021
 */

#ifndef _NODE_H_
#define _NODE_H_

class Node {
private:
    Node* one;
    Node* zero;
    int   data;

public:
    Node();
    ~Node();
    void  set_one(Node*);
    Node* get_one();

    void  set_zero(Node*);
    Node* get_zero();

    void  set_data(int);
    int   get_data();
};

#endif
