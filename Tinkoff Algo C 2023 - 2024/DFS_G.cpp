//
// Created by Сергей on 25.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<int> &used, vector<vector<int> >& g) {
    used[v - 1] = 1;
    for (int to : g[v - 1]) {
        if (used[to - 1] == 1) {
            cout << 1;
            exit(0);
        } else {
            dfs(to, used, g);
        }
    }
    used[v - 1] = 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    int f, s;
    for (int i = 0; i < m; ++i) {
        cin >> f >> s;
        g[f - 1].push_back(s);
    }
    vector<int> used(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i + 1, used, g);
        }
    }
    cout << 0;
}