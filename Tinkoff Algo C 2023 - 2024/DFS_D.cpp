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
    if (n - 1 == m) {
        vector<pair<int, int> > gr(m);
        vector<vector<int> > graph(n);
        for (int i = 0; i < m; ++i) {
            cin >> gr[i].first >> gr[i].second;
            graph[gr[i].first - 1].push_back(gr[i].second);
            graph[gr[i].second - 1].push_back(gr[i].first);
        }
        vector<bool> used(n, false);
        dfc(1, used, graph);
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                counter++;
            }
        }
        if (counter == n) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }
}