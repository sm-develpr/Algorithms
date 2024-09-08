//
// Created by Сергей on 25.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

void dfs(bool color, int v, vector<int> &used, vector<vector<int> >& g) {
    used[v - 1] = color;
    for (int a : g[v - 1]) {
        if (used[a - 1] == 2) {
            dfs(!color, a, used, g);
        } else if (used[a - 1] == color) {
            cout << "NO";
            exit(0);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > g(m);
    vector<vector<int> > graph(n);
    for (int i = 0; i < m; ++i) {
        cin >> g[i].first >> g[i].second;
        graph[g[i].first - 1].push_back(g[i].second);
        graph[g[i].second - 1].push_back(g[i].first);
    }
    vector<int> used(n, 2);
    for (int i = 0; i < n; ++i) {
        if (used[i] == 2) {
            dfs(true, i + 1, used, graph);
        }
    }
    cout << "YES";
}