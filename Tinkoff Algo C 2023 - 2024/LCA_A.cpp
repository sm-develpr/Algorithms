//
// Created by Сергей on 10.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> tin;
vector<int> tout;
int t = 1;

void dfs(int v, vector<bool>& used, vector<vector<int> >& g) {
    used[v] = 1;
    tin[v] = t++;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to, used, g);
        }
    }
    tout[v] = t++;
}

int main() {
    int n, v, start;
    cin >> n;
    vector<vector<int> > g(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> v;
        if (v != 0) {
            g[i].push_back(v);
            g[v].push_back(i);
        }
        if (v == 0) {
            start = i;
        }
    }
    tin.resize(n + 1);
    tout.resize(n + 1);
    vector<bool> used(n + 1);
    dfs(start, used, g);
    int k, v1, v2;
    cin >> k;
    while (k--) {
        cin >> v1 >> v2;
        if (tin[v1] < tin[v2] && tout[v1] > tout[v2]) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}