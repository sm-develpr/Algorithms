//
// Created by Сергей on 11.08.2024.
//
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 200001;
const int LOGMAX = 20;

int n, l;
vector<pair<int, int> > g[MAX];
int tin[MAX], tout[MAX];
int timer;
pair<int, int> up[MAX][LOGMAX];

void dfs(int v, int p = 1, int c = INT_MAX) {
    tin[v] = timer++;
    up[v][0] = make_pair(p, c);
    for (size_t i = 1; i <= l; ++i) {
        up[v][i].first = up[up[v][i - 1].first][i - 1].first;
        up[v][i].second = min(up[v][i - 1].second, up[up[v][i - 1].first][i - 1].second);
    }
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i].first;
        dfs(to, v, g[v][i].second);
    }
    tout[v] = timer++;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int minlca(int a, int b) {
    int res = INT_MAX;
    for (int i = l; i >= 0; i--) {
        if (!upper(up[a][i].first, b)) {
            res = min(res, up[a][i].second);
            a = up[a][i].first;
        }
    }

    if (!upper(a, b)) {
        res = min(res, up[a][0].second);
    }

    for (int i = l; i >= 0; i--) {
        if (!upper(up[b][i].first, a)) {
            res = min(res, up[b][i].second);
            b = up[b][i].first;
        }
    }

    if (!upper(b, a)) {
        res = min(res, up[b][0].second);
    }

    return res;
}


int main() {
    int m;
    cin >> n;
    l = 1;
    while ((1 << l) <= n) ++l;
    for (int i = 2; i < n + 1; i++) {
        int x;
        int p;
        cin >> x >> p;
        g[x].push_back(make_pair(i, p));
    }
    dfs(1);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int res = minlca(u, v);
        cout << res << '\n';
    }
    return 0;
}