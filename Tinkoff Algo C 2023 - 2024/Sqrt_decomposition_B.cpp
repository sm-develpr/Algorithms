//
// Created by Сергей on 22.08.2024.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

struct segtree {
    vector<ll> t;
    vector<ll> pushed;
    ll n;
    void push(ll v) {
        ll s = pushed[v];
        pushed[v] = 0;
        pushed[v * 2] += s;
        pushed[v * 2 + 1] += s;
        t[v * 2] += s;
        t[v * 2 + 1] += s;
    }
    void build(ll v, ll vl, ll vr, vector<ll>& a) {
        if (vl == vr) {
            t[v] = a[vl];
            return;
        }
        ll mid = (vl + vr) / 2;
        build(v * 2, vl, mid, a);
        build(v * 2 + 1, mid + 1, vr, a);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }

    void plus(ll v, ll vl, ll vr, ll l, ll r, ll x) {
        if (l > vr || r < vl) {
            return;
        }
        if (l <= vl && r >= vr) {
            pushed[v] += x;
            t[v] += x;
            return;
        }
        push(v);
        ll mid = (vl + vr) / 2;
        plus(v * 2, vl, mid, l, r, x);
        plus(v * 2 + 1, mid + 1, vr, l, r, x);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }

    ll maxim(ll v, ll vl, ll vr, ll l, ll r) {
        if (l > vr || r < vl) {
            return -1;
        }
        if (l <= vl && r >= vr) {
            return t[v];
        }
        push(v);
        ll mid = (vl + vr) / 2;
        return max(maxim(v * 2, vl, mid, l, r), maxim(v * 2 + 1, mid + 1, vr, l, r));
    }

    segtree(vector<ll> &a) {
        n = a.size();
        t.resize(4 * n);
        pushed.resize(4 * n, 0);
        build(1, 1, n - 1, a);
    }
};

int main() {
    ll n, m, f, s, x;
    char t;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }
    segtree k = segtree(a);
    cin >> m;
    while (m--) {
        cin >> t;
        if (t == 'm') {
            cin >> f >> s;
            cout << k.maxim(1, 1, n, f, s) << " ";
        } else {
            cin >> f >> s >> x;
            k.plus(1, 1, n, f, s, x);
        }
    }
}