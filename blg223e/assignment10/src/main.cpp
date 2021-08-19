/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 19 August 2021
 */

#include "RBNode.h"
#include "RBVector.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    fstream f;
    f.open(argv[1], ios::in);

    if (!f.is_open()) {
        cout << "ERROR WHILE FILE OPENING" << endl;
        return 1;
    }

    string line;
    getline(f, line);
    stringstream s(line);

    string d;
    int rbv;
    s >> d >> rbv;
    RBVector* vector = new RBVector(rbv);

    while (getline(f, line)) {
        stringstream fcin(line);
        string cmd;
        fcin >> cmd;

        if (cmd == "PUSH") {
            string data;
            fcin >> data;
            vector->push(data);
        } else if (cmd == "FIND") {
            string data;
            fcin >> data;
            cout << vector->find(data) << " ";
        } else if (cmd == "RM") {
            string data;
            fcin >> data;
            vector->remove(data);
        } else if (cmd == "RMI") {
            int ind;
            fcin >> ind;
            vector->remove_by_index(ind);
        } else if (cmd == "UPDATE") {
            int ind;
            string data;
            fcin >> ind >> data;
            vector->update(ind, data);
        } else if (cmd == "CLEAR") {
            vector->clear();
        } else if (cmd == "GNC") {
            cout << vector->get_gnc() << " ";
        } else if (cmd == "PRINT") {
            vector->print();
        }
    }

    delete vector;
    return 0;
}
