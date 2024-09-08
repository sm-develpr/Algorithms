//
// Created by Сергей on 08.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;

struct segtree {
    int n;
    vector<pair<int, int> > tree;
    pair<int, int> maxs(const pair<int, int> &a, const pair<int, int> &b) {
        pair<int, int> ans;
        if (a.first > b.first) {
            ans.first = a.first;
            ans.second = a.second;
        } else {
            ans.first = b.first;
            ans.second = b.second;
        }
        return ans;
    }
    void build(int v, int vl, int vr, const vector<int>& a) {
        if (vl == vr) {
            tree[v] = make_pair(a[vl], vl);
            return;
        }
        int mid = (vl + vr) / 2;
        build(v * 2, vl , mid, a);
        build(v * 2 + 1, mid + 1, vr, a);
        tree[v] = maxs(tree[v * 2], tree[v * 2 + 1]);
    }
    pair<int, int> ind_maxel(int v, int vl, int vr, int l, int r) {
        if (l > vr || r < vl) {
            return make_pair(0, 0);
        }
        if (l <= vl && r >= vr) {
            return tree[v];
        }
        int mid = (vl + vr) / 2;
        if (l > mid) {
            return ind_maxel(v * 2 + 1, mid + 1, vr, l, r);
        } else if (r <= mid) {
            return ind_maxel(v * 2, vl, mid, l, r);
        }
        return maxs(ind_maxel(v * 2, vl, mid, l, r), ind_maxel(v * 2 + 1, mid + 1, vr, l, r));
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
    int k, l, r;
    segtree s = segtree(a);
    cin >> k;
    while (k--) {
        cin >> l >> r;
        pair<int, int> ans = s.ind_maxel(1, 1, n, l, r);
        cout << ans.second << '\n';
    }
}