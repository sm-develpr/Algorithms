//
// Created by Сергей on 08.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;

struct segtree {
    int n;
    vector<int> tree;
    void build(int v, int vl, int vr, const vector<int>& a) {
        if (vl == vr) {
            if (a[vl] == 0) {
                tree[v] = 1;
            } else {
                tree[v] = 0;
            }
            return;
        }
        int mid = (vl + vr) / 2;
        build(v * 2, vl, mid, a);
        build(v * 2 + 1, mid + 1, vr, a);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
    void kth_z(int v, int vl, int vr, int k) {
        if (vl == vr) {
            cout << vl << " ";
            return;
        }
        if (k > tree[v]) {
            cout << -1;
            return;
        }
        int mid = (vl + vr) / 2;
        if (k > tree[v * 2]) {
            kth_z(v * 2 + 1, mid + 1, vr, k - tree[v * 2]);
        } else {
            kth_z(v * 2, vl, mid, k);
        }
    }
    void change(int v, int vl, int vr, int pos, int x) {
        if (pos > vr || pos < vl) {
            return;
        }
        if (vl == vr) {
            if (x == 0) {
                tree[v] = 1;
            } else {
                tree[v] = 0;
            }
            return;
        }
        int mid = (vl + vr) / 2;
        change(v * 2, vl, mid, pos, x);
        change(v * 2 + 1, mid + 1, vr, pos, x);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
    int sum(int v, int vl, int vr, int l, int r) {
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

    segtree(const vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 1, n - 1, a);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }
    segtree s = segtree(a);
    int k;
    cin >> k;
    while (k--) {
        char to;
        cin >> to;
        if (to == 'u') {
            int pos, x;
            cin >> pos >> x;
            s.change(1, 1, n, pos, x);
        } else {
            int l, r, c;
            cin >> l >> r >> c;
            if (s.sum(1, 1, n, l, r) < c) {
                cout << -1 << " ";
                continue;
            }
            if (l != 1) {
                c += s.sum(1, 1, n, 1, l - 1);
            }
            s.kth_z(1, 1, n, c);
        }
    }
}