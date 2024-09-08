//
// Created by Сергей on 07.08.2024.
//
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
ll INF = -1e9 - 1;

struct segtree {
    int n;
    vector<ll> tree;
    void build(int v, int vl, int vr, const vector<ll>& a) {
        if (vr == vl) {
            tree[v] = a[vl];
            return;
        }
        int mid = (vr + vl) / 2;
        build(v * 2, vl, mid, a);
        build(v * 2 + 1, mid + 1, vr, a);
        tree[v] = std::max(tree[v * 2], tree[v * 2 + 1]);
    }

    segtree(const vector<ll>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 1, n - 1, a);
    }

    ll max(int v, int vl, int vr, int l, int r) {
        if (l > vr || r < vl) {
            return INF;
        }
        if (l <= vl && r >= vr) {
            return tree[v];
        }
        int mid = (vr + vl) / 2;
        return std::max(max(v * 2, vl, mid, l, r), max(v * 2 + 1, mid + 1, vr, l, r));
    }
};

int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }
    int k;
    segtree s = segtree(a);
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        cout << s.max(1, 1, n, l, r) << '\n';
    }
    return 0;
}