/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 5 August 2021
 */

#ifndef _TRIE_H_
#define _TRIE_H_

#include <string>
#include "TrieNode.h"

using namespace std;

class Trie {
private:
    TrieNode* root;
public:
    Trie();
    ~Trie();
    TrieNode* go(string);
    void      add_word(string, int);
};

#endif
