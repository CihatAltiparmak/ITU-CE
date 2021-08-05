/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 5 August 2021
 */

#include <vector>
#include <iostream>
#include "TrieNode.h"

using namespace std;

TrieNode::TrieNode(char data) {
    this->data = data;
    for (auto& node : this->nodes)
        node = NULL;

}

TrieNode::~TrieNode() 
{
    for (auto& node : this->nodes) {
        delete node;
        node = NULL;
    }
}

void TrieNode::set_data(char data) 
{
    this->data = data;
}

char TrieNode::get_data() 
{
    return this->data;
}

vector<int> TrieNode::get_pages() 
{
    return this->pages;
}

void TrieNode::add_pages(int page) 
{
    this->pages.push_back(page);
}

void TrieNode::set_node(TrieNode* trie_node, int i) 
{
    this->nodes[i] = trie_node;
}

TrieNode* TrieNode::get_node(int i) 
{
    return this->nodes[i];
}

void TrieNode::print_pages() {
    for (int i = 0; i < this->pages.size(); i++) {
        cout << pages[i];
        if (i < pages.size() - 1)
            cout << " ";
    }
}
