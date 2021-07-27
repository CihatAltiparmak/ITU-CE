/* @author
 * Student Name: Cihat Kurtuluş Altıparmak
 * Student ID: 150200105
 * Date: 27 July 2021
 */

#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>

using namespace std;

class Node {
    private:
        string from;
        string to;
        int    amount; 
        Node*  next;
    public:        

        Node(string, string, string);        
        ~Node();

        void   set_from(string);
        string get_from();
        
        void   set_to(string);
        string get_to();

        void   set_amount(int);
        int    get_amount();

        void   set_next(Node*);
        Node*  get_next();

};

#endif
