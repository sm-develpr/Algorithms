//
// Created by Сергей on 28.07.2024.
//
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int INF = 1e9;

int main() {
    int n, m, start, u, v, c;
    cin >> n >> m >> start;
    vector<vector<pair<int, int> > > g(n + 1);
    for (int i = 0 ; i < m; ++i) {
        cin >> u >> v >> c;
        g[v].push_back(make_pair(u, c));
        g[u].push_back(make_pair(v, c));
    }
    vector<bool> used(n + 1, 0);
    vector<int> dist(n + 1, INF);
    deque<int> q;
    dist[start] = 0;
    q.push_back(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        if (used[v]) { continue;}
        used[v] = 1;
        for (auto i : g[v]) {
            if (dist[i.first] > dist[v] + i.second) {
                dist[i.first] = dist[v] + i.second;
                if (i.second == 0) {
                    q.push_front(i.first);
                } else {
                    q.push_back(i.first);
                }
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        if (dist[i] == INF) {
            cout << -1 << " ";
            continue;
        }
        cout << dist[i] << " ";
    }
}