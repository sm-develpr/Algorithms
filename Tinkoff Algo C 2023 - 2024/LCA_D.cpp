//
// Created by Сергей on 11.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll MAX = 1e5 + 10;
ll LOGMAX = 20;
vector<ll> tin(MAX);
vector<ll> tout(MAX);
vector<bool> used(MAX, 0);
vector<vector<ll> > g(MAX);
vector<vector<ll> > up(MAX, vector<ll>(LOGMAX));
ll  timer = 0;
vector<ll> way(MAX);
vector<ll> cost(MAX);

void dfs(ll v, ll p) {
    used[v] = 1;
    up[v][0] = p;
    way[v] = way[p] + cost[v];
    for (ll i = 1; i < LOGMAX; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    tin[v] = timer++;
    for (ll to : g[v]) {
        if (to != p && !used[to]) {
            dfs(to, v);
        }
    }
    tout[v] = timer++;
}

bool is_p(ll v, ll u) {
    return (tin[v] <= tout[u] && tout[v] >= tout[u]);
}

ll lca(int v, int u) {
    if (is_p(v, u)) return v;
    if (is_p(u, v)) return u;
    for (ll i = LOGMAX - 1; i >= 0; --i) {
        if (!is_p(up[v][i], u)) v = up[v][i];
    }
    return up[v][0];
}

int main() {
    ll n, f, s;
    cin >> n;
    for (ll i = 1; i < n + 1; ++i) {
        cin >> cost[i];
    }
    for (ll i = 1; i < n; ++i) {
        cin >> f >> s;
        g[f].push_back(s);
        g[s].push_back(f);
    }
    ll k;
    cin >> k;
    dfs(1, 1);
    while (k--) {
        cin >> f >> s;
        cout << way[f] + way[s] - 2 * way[lca(f, s)] + cost[lca(f, s)] << " ";
    }
}