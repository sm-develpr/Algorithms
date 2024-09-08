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
    cin >> n >> m >> s >> t;
    vector<vector<pair<int, int> > > g(n + 1);
    vector<vector<int> > prev(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        prev[i].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> c;
        g[u].push_back(make_pair(v, c));
        g[v].push_back(make_pair(u, c));
    }
    vector<bool> used(n + 1, 0);
    vector<long long> dist(n + 1, 1e9);
    dist[s] = 0;
    priority_queue<pair<int, int> > r;
    r.push(make_pair(0, s));
    while (!r.empty()) {
        int k = r.top().second;
        r.pop();
        for (auto i : g[k]) {
            if (dist[i.first] > dist[k] + i.second) {
                prev[i.first] = prev[k];
                prev[i.first].push_back(i.first);
                dist[i.first] = dist[k] + i.second;
                r.push(make_pair(-dist[i.first], i.first));
            }
        }
    }
    if (dist[t] == 1e9) {
        cout << -1;
    } else {
        cout << dist[t] << " " << prev[t].size() << '\n';
        for (auto i : prev[t]) {
            cout << i << " ";
        }
    }
    // На информатиксе все зашло, на тинькофф не заходит с ошибкой на 4 тесте
}