//
// Created by Сергей on 28.07.2024.
//
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main() {
    int n, m, s, t, u, v, c;
    cin >> n >> s >> t;
    vector<vector<pair<int, int> > > g(n + 1);
    vector<vector<int> > prev(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        prev[i].push_back(i);
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cin >> u;
            if (u != 0 && u != -1) {
                g[i].push_back(make_pair(j, u));
            }
        }
    }
    vector<bool> used(n + 1, 0);
    vector<long long> dist(n + 1, 1e9 + 1);
    dist[s] = 0;
    set<pair<int, int> > r;
    r.insert(make_pair(0, s));
    while (!r.empty()) {
        int k = r.begin()->second;
        r.erase(r.begin());
        for (auto i : g[k]) {
            if (dist[i.first] > dist[k] + i.second) {
                prev[i.first] = prev[k];
                prev[i.first].push_back(i.first);
                dist[i.first] = dist[k] + i.second;
                r.insert(make_pair(dist[i.first], i.first));
            }
        }
    }
    if (dist[t] == 1e9 + 1) {
        cout << -1;
    } else {
        cout << dist[t];
    }
}