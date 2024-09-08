//
// Created by Сергей on 07.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;
int MAXN = 1e5;
typedef long long ll;
vector<ll> pushed(MAXN * 4, 0);

struct segtree  {
    int n;
    vector<ll> tree;

    void push(int v, int vl, int vr) {
        ll x = pushed[v];
        pushed[v] = 0;

        pushed[v * 2] += x;
        pushed[v * 2 + 1] += x;

        int mid = (vr + vl) / 2;
        tree[v * 2] += x * (mid - vl + 1);
        tree[v * 2] += x * (vr - mid);
    }

    void build(int v, int l, int r, vector<ll>& a) {
        if (l == r) {
            tree[v] = a[l];
            return;
        }
        int mid = (r + l) / 2;
        build(v * 2, l, mid, a);
        build(v * 2 + 1, mid + 1, r, a);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
    ll sum(int v, int vl, int vr, int l, int r) {
        if (r < vl || l > vr) {
            return 0;
        }
        if (l <= vl && r >= vr) {
            return tree[v];
        }
        int mid = (vr + vl) / 2;
        // push(v, vl, vr);
        return sum(v * 2, vl, mid, l, r) + sum (v * 2 + 1, mid + 1, vr, l, r);
    }
    void change(int v, int vl, int vr, int p, ll x) {
        if (p < vl || p > vr) {
            return;
        }
        if (vr == vl) {
            tree[v] = x;
            return;
        }
        int mid = (vl + vr) / 2;
        change(v * 2, vl, mid, p, x);
        change(v * 2 + 1, mid + 1, vr, p, x);
        tree[v] = tree[2 * v] + tree[v * 2 + 1];
    }
    segtree(vector<ll> &a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 1, n - 1, a);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1, 0);
    segtree s = segtree(a);
    for (int i = 0; i < m; ++i) {
        char t;
        cin >> t;
        if (t == 'A') {
            int pos;
            ll x;
            cin >> pos >> x;
            s.change(1, 1, n, pos, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << s.sum(1, 1, n, l, r) << '\n';
        }
    }
}