/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 5 August 2021
 */

#ifndef _TRIE_NODE_H_
#define _TRIE_NODE_H_

#include <vector>

using namespace std;    

class TrieNode {
private:
    char data;
    vector<int> pages;
    TrieNode* nodes[26];
public:
    TrieNode(char);
    ~TrieNode();
    void        set_data(char data);
    char        get_data();
    vector<int> get_pages();
    void        add_pages(int);
    void        set_node(TrieNode*, int);
    TrieNode*   get_node(int);
    void        print_pages();
};

#endif
