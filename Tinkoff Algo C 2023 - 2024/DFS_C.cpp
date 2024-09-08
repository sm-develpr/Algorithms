//
// Created by Сергей on 25.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

void dfc(int v, vector<bool>& used, const vector<vector<int> >& g) {
    used[v - 1] = true;
    for (auto to : g[v - 1]) {
        if (!used[to - 1]) {
            dfc(to, used, g);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > graph(n, vector<int>(n));
    vector<vector<int> > g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            if (graph[i][j]) {
                g[i].push_back(j + 1);
            }
        }
    }
        vector<bool> used(n, false);
        dfc(m, used, g);
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                counter++;
            }
        }
        cout << counter;
}