//
// Created by Сергей on 12.08.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void dfs(ll v, vector<vector<ll> >& g, vector<bool>& used, vector<ll>& topsort) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to, g, used, topsort);
        }
    }
    topsort.push_back(v);
}

int main() {
    ll n, m, y;
    cin >> n;
    vector<ll> cost(n + 1, 0);
    for (ll i = 1; i < n + 1; ++i) {
        cin >> cost[i];
    }
    vector<vector<ll> > gt(n + 1);
    for (ll i = 1; i < n + 1; ++i) {
        cin >> m;
        for (ll j = 0; j < m; ++j) {
            cin >> y;
            gt[i].push_back(y);
        }
    }
    vector<ll> topsort;
    vector<bool> used(n + 1);
    dfs(1, gt, used, topsort);
    vector<ll> a;
    ll ans = 0, i = 0;
    while (topsort[i] != 1) {
        ans += cost[topsort[i]];
        a.push_back(topsort[i]);
        i++;
    }
    a.push_back(1);
    ans += cost[topsort[i]];
    cout << ans << " " << a.size() << '\n';
    for (auto i : a) {
        cout << i << " ";
    }
}