/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 3 August 2021
 */

#include <iostream>
#include <string>
#include <vector>

#include "Tree.h"

using namespace std;

const int inf = 1000000009;
vector<string> PERMUTATIONS;
short int VISITED[26] = { 0 }; // there are the most 26 letter in  English alphabet

string LETTERS = "";
int LETTER_NUM = 0;

int bruh_log2(uint32_t x)
{
    // it be assumed that x is always power of two
    return __builtin_ctz(x);
}

void generate_permutations(string s, int step)
{
    if (step == LETTER_NUM)
        PERMUTATIONS.push_back(s);

    for (int i = 0; i < LETTER_NUM; i++) {
        if (VISITED[i])
            continue;
        VISITED[i] = 1;
        generate_permutations(s + LETTERS[i], step + 1);
        VISITED[i] = 0;
    }
}

int main()
{
    string bits;
    cin >> bits;
    LETTER_NUM = bruh_log2(bits.size());

    for (int i = 0; i < LETTER_NUM; i++)
        LETTERS += 65 + i;

    generate_permutations("", 0);

    vector<Tree*> trees;
    int minimum_node_count = inf;
    for (string s : PERMUTATIONS) {
        Tree* tree = new Tree();
        for (int state = 0; state < bits.size(); state++) {
            int point = 0;
            for (int k = 0; k < LETTER_NUM; k++) {
                if (state & (1 << (LETTER_NUM - 1 - k))) {
                    int loc = LETTER_NUM - 1 - (s[k] - 65);
                    point |= (1 << (loc));
                }
            }
            int res = state << 1;
            if (bits[point] == '1')
                res = res | 1;
            tree->add_result(res, LETTER_NUM);
        }
        tree->prune_tree(tree->get_root());
        minimum_node_count = min(minimum_node_count, tree->get_size());
        trees.push_back(tree);
    }

    for (int i = 0; i < trees.size(); i++) {
        if (trees[i]->get_size() == minimum_node_count)
            cout << PERMUTATIONS[i] << " ";
        delete trees[i];
        trees[i] = NULL;
    }

    cout << minimum_node_count;
}
