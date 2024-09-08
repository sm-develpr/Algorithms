//
// Created by Сергей on 08.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;

struct segtree {
    int n;
    vector<pair<int, int> > tree;

    pair<int, int> compare(pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first) {
            return a;
        }
        if (a.first < b.first) {
            return b;
        }
        return make_pair(a.first, a.second + b.second);
    }

    void build(int v, int vl, int vr, const vector<int>& a) {
        if (vl == vr) {
            tree[v] = make_pair(a[vl], 1);
            return;
        }
        int mid = (vl + vr) / 2;
        build(v * 2, vl, mid, a);
        build(v * 2 + 1, mid + 1, vr, a);
        tree[v] = compare(tree[v * 2], tree[v * 2 + 1]);
    }

    void change(int v, int vl, int vr, int pos, int x) {
        if (pos < vl || pos > vr) {
            return;
        }
        if (vl == vr) {
            tree[v] = make_pair(x, 1);
            return;
        }
        int mid = (vl + vr) / 2;
        change(v * 2, vl, mid, pos, x);
        change(v * 2 + 1, mid + 1, vr, pos, x);
        tree[v] = compare(tree[v * 2], tree[v * 2 + 1]);
    }

    pair<int, int> maxim(int v, int vl, int vr, int l, int r) {
        if (l > vr || r < vl) {
            return make_pair(0, 0);
        }
        if (l <= vl && r >= vr) {
            return tree[v];
        }
        int mid = (vl + vr) / 2;
        return compare(maxim(v * 2 + 1, mid + 1, vr, l , r), maxim(v * 2, vl, mid, l, r));
    }

    segtree(const vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 1, n - 1, a);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }
    segtree s = segtree(a);
    int k, c, b;
    cin >> k;
    while (k--) {
        char t;
        cin >> t;
        if (t == 'Q') {
            cin >> b >> c;
            cout << s.maxim(1, 1, n, b, c).second << " ";
        } else {
            cin >> b >> c;
            s.change(1, 1, n, b, c);
        }
    }
}