//
// Created by Сергей on 20.08.2024.
//

// O(n^2 + m) для полных графов
// зашло при n <= 20000 и m <= 100000
#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<vector<pair<int, int> > > g;
vector<int> used;
vector<int> min_edge;
vector<int> sel_e;
int weight_min_ost = 0;
const int INF = 1e9;

/*
int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    used.resize(n + 1, 0);
    min_edge.resize(n + 1, INF);
    g.resize(n + 1);
    sel_e.resize(n + 1, -1);
    min_edge[1] = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 1; j < n + 1; ++j) {
            if (!used[j] && (v == -1 || min_edge[j] < min_edge[v])) {  // находим минимальное ребро из нашей компоненты связности
                v = j;
            }
        }
        if (min_edge[v] == INF) {
            exit(0);  // нет мин остова, из этой вершины нельзя добраться ни до одной другой
        }
        */
/*if (sel_e[v] != -1) {
            cout << v << sel_e[v];
        }*//*

        used[v] = 1;
        weight_min_ost += min_edge[v];
        // обновляем список min_edge, добавляем новые расстояния которые возникли от новрй вершны v
        for (auto to : g[v]) {
            if (!used[to.first] && to.second < min_edge[to.first]) {
                min_edge[to.first] = to.second;
                sel_e[to.first] = v;
            }
        }
    }
    cout << weight_min_ost;
}*/
        // O(mlogn)
        set<pair<int, int> > q;
int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    used.resize(n + 1, 0);
    min_edge.resize(n + 1, INF);
    g.resize(n + 1);
    sel_e.resize(n + 1, -1);
    min_edge[1] = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    q.insert(make_pair(0, 1));
    for (int i = 0; i < n; ++i) {
        if (q.empty()) {
            exit(0);  // нет миностова
        }
    }
    int v = q.begin()->second;
    q.erase(q.begin());
    if (sel_e[v] != -1) {
        cout << v << " " << sel_e[v];
    }
    for (auto to : g[v]) {
        if (!used[to.first] && to.second < min_edge[to.first]) {
            q.erase(make_pair(min_edge[to.first], to.first));
            min_edge[to.first] = to.second;
            sel_e[to.first] = v;
            q.insert(make_pair(min_edge[to.first], to.first));
        }
    }
}


