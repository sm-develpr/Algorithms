//
// Created by Сергей on 28.07.2024.
//
#include <iostream>
#include <vector>
#include <queue>
int INF = 1e9;
using namespace std;

int main() {
    int n, m, start, f, s;
    cin >> n >> m >> start;
    vector<vector<int> > graph(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> f >> s;
        graph[f].push_back(s);
        graph[s].push_back(f);
    }
    queue<int> t;
    // vector<bool> used(n + 1, 0);
    t.push(start);
    vector<int> dist(n + 1, -1);
    dist[start] = 0;
    while (!t.empty()) {
        int v;
        v = t.front();
        t.pop();
        for (int i : graph[v]) {
            if (dist[i] == -1) {
                dist[i] = dist[v] + 1;
                t.push(i);
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        cout << dist[i] << " ";
    }
}