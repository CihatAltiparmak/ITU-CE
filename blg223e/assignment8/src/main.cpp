/** @author
 *  Student Name: Cihat Kurtuluş Altıparmak
 *  Student ID  : 150200105
 *  Date        : 13 August 2021
 */

#include <iostream>
#include <vector>

using namespace std;

#define dbg(a) for (int i : a) cout << (char)(i + 'A') << " "; cout << endl;

int n;
int dist;    
int unli = 0; // count of node that repetition value is -1 (UNLImited node) 

vector<vector<int>> ans; // answer list
vector<vector<int>> g;   // graph
vector<int> cost;        // repetition value list of nodes

// if we send reference of path parameter instead of itself, 
// we handle extremely less memory instead of very hudge number of memory in stack
// The handling less memory makes gain more time for solving this problem
void walk (int v, int dist, int space, vector<int>& path) 
{
    // dbg(path);
 
    if (cost[v] == -1)
        space++;

    if (space > unli || cost[v] == 0)
        return;
    
    path.push_back(v);
    
    if (dist == 0) {
        // cout << "added" << endl;
        ans.push_back(path);
        path.pop_back();
        return;
    }
 
    if (cost[v] != -1)
        cost[v]--;

    for (int u : g[v])
        walk(u, dist - 1, space, path);
    
    if (cost[v] != -1)
        cost[v]++;

    path.pop_back();
     
}

int main (int argc, char* argv[]) 
{
    freopen(argv[1], "r", stdin);

    cin >> n;
    g.resize(n);
    cost.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v; cin >> v;
            if (v)
                g[i].push_back(j);
        }
    } 
    
    int tot = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        cin >> cost[c - 'A'];
        if (cost[c - 'A'] != -1)
            tot += cost[c - 'A'];
    } 

    cin >> dist;
    unli = dist - tot;

    for (int i = 0; i < n; i++) {
        vector<int> path;
        walk(i, dist - 1, 0, path);
    }

    for (int i = 0; i < ans.size(); i++) {
        for (int u : ans[i]) {
            char c = 'A' + u;
            cout << c;
        }
        if (i < ans.size() - 1)
            cout << " ";
    }

    fclose(stdin);
        
}
