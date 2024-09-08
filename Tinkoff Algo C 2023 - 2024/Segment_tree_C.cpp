//
// Created by Сергей on 07.08.2024.
//
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) {
        return max(a, b);
    }
    return b ? gcd(b, a % b) : a;
}

struct segtree {
    int n;
    vector<ll> tree;
    void build(int v, int vl, int vr, const vector<ll>& a) {
        if (vl == vr) {
            tree[v] = a[vl];
            return;
        }
        int mid = (vr + vl) / 2;
        build(v * 2, vl, mid, a);
        build(v * 2 + 1, mid + 1, vr, a);
        tree[v] = gcd(tree[v * 2], tree[v * 2 + 1]);
    }
    segtree(const vector<ll>& a) {
        n = a.size();
        tree.resize(n * 4);
        build(1, 1, n - 1, a);
    }
    void change(int v, int vl, int vr, int pos, ll x) {
        if (pos > vr || pos < vl) {
            return;
        }
        if (vl == vr) {
            tree[v] = x;
            return;
        }
        int mid = (vl + vr) / 2;
        change(v * 2, vl, mid, pos, x);
        change(v * 2 + 1, mid + 1, vr, pos, x);
        tree[v] = gcd(tree[v * 2], tree[v * 2 + 1]);
    }
    ll nod(int v, int vl, int vr, int l, int r) {
        if (r < vl || l > vr) {
            return 0;
        }
        if (r >= vr && l <= vl) {
            return tree[v];
        }
        ll mid = (vr + vl) / 2;
        return gcd(nod(v * 2, vl, mid, l, r), nod(v * 2 + 1, mid + 1, vr, l, r));
    }
};

int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }
    segtree s = segtree(a);
    int k;
    cin >> k;
    while (k--) {
        char t;
        cin >> t;
        if (t == 's') {
            int l, r;
            cin >> l >> r;
            cout << s.nod(1, 1, n, l, r) << " ";
        } else {
            int pos, x;
            cin >> pos >> x;
            s.change(1, 1, n, pos, x);
        }
    }
}