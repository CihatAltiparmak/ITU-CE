/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 5 August 2021
 */

#include <iostream>
#include <fstream>

#include "Trie.h"
#include "TrieNode.h"

void parse(string line, int line_num, Trie& trie) 
{
    int i = 0;
    while (i < line.size()) {
        while (line[i] == ' ' && i < line.size())
            i++;
        string word = "";
        while (line[i] != ' ' && i < line.size()) {
            char c = tolower(line[i]);
            if (c >= 'a' && c <= 'z')
                word += c;
            i++;
        }
        if (word.size() != 0)
            trie.add_word(word, line_num);
    }
}


int main (int argc, char* argv[]) 
{
    fstream f;
    f.open(argv[1], ios::in);
    if (!f.is_open()) {
        cout << "FAIL: file was not opened" << endl;
        return 1;
    }
    
    Trie trie;

    string line;
    int line_num = 1;
    while (getline(f, line)) {
        parse(line, line_num, trie); 
        line_num++;
    }

    for (int i = 2; i < argc; i++) {
        TrieNode* ans_node = trie.go(argv[i]);
        cout << argv[i] << ":";
        if (ans_node != NULL)
            ans_node->print_pages();
        else
            cout << "-1";
        if (i < argc - 1)
            cout << " "; 
    }
}
