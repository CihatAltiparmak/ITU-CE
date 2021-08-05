/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 5 August 2021
 */

#include <string>
#include "Trie.h"
#include "TrieNode.h"

using namespace std;

Trie::Trie() {
    this->root = new TrieNode('-');
}

Trie::~Trie() {
    delete this->root;
}

TrieNode* Trie::go(string word) 
{
    TrieNode* tmp = this->root;
    for (char c : word) {
        tmp = tmp->get_node(c - 'a');
        if (tmp == NULL)
            return NULL;
    }
    return tmp;
}

void Trie::add_word(string word, int page) 
{
    TrieNode* tmp = this->root;
    for (char c : word) {
        if (tmp->get_node(c - 'a') == NULL)
            tmp->set_node(new TrieNode(c - 'a'), c - 'a');
        tmp = tmp->get_node(c - 'a');
    }
    tmp->add_pages(page);
}
