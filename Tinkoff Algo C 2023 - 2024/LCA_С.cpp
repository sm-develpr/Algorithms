//
// Created by Сергей on 10.08.2024.
//
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
size_t tim = 0;
const ll MAXLG = 21;
const ll MAX = 1000100;
vector<ll> tin(MAX);
vector<ll> tout(MAX);
vector<vector<ll> > g(MAX);
vector<vector<ll> > binup(MAX, vector<ll>(MAXLG));
vector<bool> used(MAX);


void dfs(ll v, ll p = 0, ll len = 0) {
    used[v] = 1;
    tin[v] = ++tim;
    binup[v][0] = p;
    for (size_t i = 1; i < MAXLG; ++i) {
        binup[v][i] = binup[binup[v][i - 1]][i - 1];
    }
    for (size_t i = 0; i < g[v].size(); ++i) {
        ll to = g[v][i];
        if (to != p && !used[to])
            dfs(to, v, len + 1);
    }
    tout[v] = tim;
}

bool is_pred(ll v, ll u) {
    return (tin[v] <= tin[u] && tout[v] >= tout[u]);
}
int lca(ll v, ll u) {
    if (is_pred(v, u)) {
        return v;
    }
    if (is_pred(u, v)) {
        return u;
    }
    for (ll k = MAXLG - 1; k >= 0; --k) {
        int to_v = binup[v][k];
        if (!is_pred(to_v, u)) {
            v = to_v;
        }
    }
    return binup[v][0];
}
int main() {
    ll a1, a2, sum = 0, x, y, z, n, m, v;
    cin >> n >> m;
    for (ll i = 1; i < n; ++i) {
        cin >> v;
        g[v].push_back(i);
        g[i].push_back(v);
    }
    dfs(0);
    cin >> a1 >> a2;
    cin >> x >> y >> z;
    sum = v = 0;
    for (ll i = 0; i < m; i++) {
        v = lca((a1 + v) % n, a2);
        sum += v;
        a1 = (x * a1 + y * a2 + z) % n;
        a2 = (x * a2 + y * a1 + z) % n;
    }
    cout << sum;
}

// ебал эту задачу
// ебал я просто людей кто писал ебаные ограничение на данные
// они блять просто нахуй кусок говна пиздеж средь бела дня
//