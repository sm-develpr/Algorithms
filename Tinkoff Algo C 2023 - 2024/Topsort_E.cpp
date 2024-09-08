//
// Created by Сергей on 13.08.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;

void dfs(int v, vector<vector<pair<int, int> > >& g, vector<int>& used, vector<int>& topsort) {
    used[v] = 1;
    for (auto i : g[v]) {
        if (!used[i.first]) {
            dfs(i.first, g, used, topsort);
        }
    }
    topsort.push_back(v);
}

int main() {
    int n, m, s, t, a, b, c;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int, int> > > gt(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        gt[a].push_back(make_pair(b, c));
    }
    vector<int> used(n + 1, 0);
    vector<int> topsort;
    for (int i = 1; i < n + 1; ++i) {
        if (!used[i]) {
            dfs(i, gt, used, topsort);
        }
    }
    std::reverse(topsort.begin(), topsort.end());
    vector<int> dist(n + 1, INF);
    dist[s] = 0;
    for (int v : topsort) {
        for (auto& [to, w] : gt[v]) {
            if (dist[v] != INF && dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
            }
        }
    }
    if (dist[t] != INF) {
        cout << dist[t];
    } else {
        cout << "Unreachable";
    }
}
/*
 * 2 3 1
2 1 1
3 6 1
6 7 2
2 6 3
6 4 5
7 4 2
5 4 3
8 4 1
5 8 1
2 5 4
1 5 2
 2-(-10)>3
2-(-3)-1
3-(-2)>6
6-(-7)>7
2-(-13)>6
6-(-8)>4
7-(-10)>4
5-(-9)>4
8-(-2)>4
5-(3)>8
2-(-9)>5
1-(10)>5

 */