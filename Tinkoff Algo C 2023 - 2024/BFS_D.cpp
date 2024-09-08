//
// Created by Сергей on 28.07.2024.
//
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int INF = 1e9;

int rast(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
    int n, start, end, u, v;
    cin >> n;
    vector<pair<int, int> > g(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> u >> v;
        g[i] = make_pair(u, v);
    }
    cin >> start >> end;
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    vector<bool> used(n+1, 0);
    /*priority_queue <pair<int, int> > s;
    vector<bool> visited(n + 1, 0);
    s.push(make_pair(0, start));
    while (!s.empty()) {
        int v = s.top().second;
        s.pop();
        if (visited[v]) {
            continue;
        }
        visited[v] = 1;
        for (int i = 1; i < n + 1; ++i) {
            if (dist[i] > dist[v] + rast(g[i], g[v])) {
                dist[i] = dist[v] + rast(g[i], g[v]);
                s.push(make_pair(-dist[i], i));
            }
        }
    }
    cout << dist[end];*/
    for (int i = 0; i < n; ++i) {
        int min_v, min_dist = INF;
        for (v = 1; v < n + 1; ++v) {
            if (!used[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }
        }
        used[min_v] = 1;
        for (int j = 1; j < n + 1; ++j) {
            if (dist[j] > dist[min_v] + rast(g[min_v], g[j])) {
                dist[j] = dist[min_v] + rast(g[min_v], g[j]);
            }
        }
    }
    cout << dist[end];
}