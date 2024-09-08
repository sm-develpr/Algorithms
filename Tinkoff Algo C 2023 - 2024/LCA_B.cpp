//
// Created by Сергей on 11.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int MAX = 1e5 + 10;
int LOGMAX = 18;
vector<vector<ll> > g(MAX);
vector<bool> used(MAX);
vector<ll> pred(MAX);

void dfs(ll v, ll p) {
    used[v] = 1;
    pred[v] = p;
    for (ll k : g[v]) {
        if (!used[k]) {
            dfs(k, v);
        }
    }
}
int main() {
    ll n, m, a1, a2, x, y, z, f, s;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        cin >> f;
        g[f].push_back(i);
        g[i].push_back(f);
    }
    cin >> a1 >> a2;
    cin >> x >> y >> z;
    ll ans, sum = 0;
    dfs(0, 0);
    for (ll i = 0; i < m; ++i) {
        ans = a1;
        for (ll k = 0; k < a2; ++k) {
            ans = pred[ans];
        }
        sum += ans;
        a1 = (x * a1 + y * a2 + z) % n;
        a2 = (x * a2 + y * a1 + z) % n;
        a1 = (a1 + ans) % n;
    }
    cout << sum;
}
