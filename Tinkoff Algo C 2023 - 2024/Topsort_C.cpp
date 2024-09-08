//
// Created by Сергей on 12.08.2024.
//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int> color;
set<pair<int, int> > u;

void dfs(int v, vector<vector<int> >& g, vector<bool>& used, vector<int>& topsort, int c) {
    used[v] = 1;
    color[v] = c;
    for (auto i : g[v]) {
        if (!used[i]) {
            dfs(i, g, used, topsort, c);
        }
    }
    topsort.push_back(v);
}

int main() {
    int n, m, f, s;
    cin >> n >> m;
    vector<vector<int> > g(n + 1);
    vector<vector<int> > gt(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> f >> s;
        g[f].push_back(s);
        gt[s].push_back(f);
    }
    color.resize(n + 1);
    vector<bool> used(n + 1, 0);
    vector<int> topsort;
    for (int i = 1; i < n + 1; ++i) {
        if (!used[i]) {
            dfs(i, g, used, topsort, 0);
        }
    }
    std::reverse(topsort.begin(), topsort.end());
    used.assign(n + 1, 0);
    int c = 1;
    for (int i = 0; i < n; ++i) {
        int v = topsort[i];
        if (!used[v]) {
            vector<int> component;
            dfs(v, gt, used, component, c);
            c = c + 1;
        }
    }
    for (size_t i = 1; i < g.size(); ++i) {
        for (size_t j = 0; j < g[i].size(); ++j) {
            if (color[i] != color[g[i][j]]) {
                u.insert(make_pair(color[i], color[g[i][j]]));
            }
        }
    }
    cout << u.size();
}