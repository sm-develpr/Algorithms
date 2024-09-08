//
// Created by Сергей on 13.08.2024.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool flag = false;

void dfs(int v, vector<vector<int> >&g, vector<int>& used, vector<int>& topsort) {
    used[v] = 1;
    for (int i : g[v]) {
        if (used[i] == 1) {
            flag = true;
        }
        if (used[i] == 0) {
            dfs(i, g, used, topsort);
        }
    }
    topsort.push_back(v);
    used[v] = 2;
}

int main() {
    int n, m, f, s;
    cin >> n >> m;
    vector<vector<int> > g(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> f >> s;
        g[f].push_back(s);
    }
    vector<int> used(n + 1, 0);
    vector<int> topsort;
    for (int i = 1; i < n + 1; ++i) {
        if (!used[i]) {
            dfs(i, g, used, topsort);
        }
    }
    std::reverse(topsort.begin(), topsort.end());
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        pos[topsort[i]] = i;
    }
    if (flag) {
        cout << -1;
    } else {
        for (auto i : topsort) {
            cout << i << " ";
        }
    }
}