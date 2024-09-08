//
// Created by Сергей on 09.08.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int factorial(int N)
{
    int F = 1;

    for(int i=1; i<=N; ++i)
    {
        F *= i; // Эквивалент F = F*i;
    }
    return F; // Возвращаем ответ
}

struct segtree {
    int n;
    vector<int> tree;
    void build(int v, int vl, int vr, const vector<int>& a) {
        if (vl == vr) {
            tree[v] = a[vl];
            return;
        }
        int mid = (vl + vr) / 2;
        build(v* 2, vl, mid, a);
        build(v*2 + 1, mid + 1, vr, a);
        tree[v] = tree[v * 2] + tree[v * 2 +1];
    }
    void change(int v, int vl, int vr, int pos) {
        if (pos > vr || pos < vl) {
            return;
        }
        if (vl == vr) {
            tree[v] = 1;
            return;
        }
        int mid = (vl + vr) / 2;
        if (pos > mid) {
            change(v * 2 + 1, mid + 1, vr, pos);
        } else {
            change(v * 2, vl, mid, pos);
        }
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
    int sum(int v, int vl, int vr, int l, int r) {
        if (l > vr || r < vl) {
            return 0;
        }
        if (l <= vl && r >= vr) {
            return tree[v];
        }
        int mid = (vl + vr) / 2;
        return sum(v * 2, vl, mid, l, r) + sum(v * 2 + 1, mid + 1, vr, l, r);
    }
    segtree(const vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    int maxim = -1;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] > maxim) {
            maxim = b[i];
        }
    }
    vector<int> a(maxim + 1, 0);
    segtree s = segtree(a);
    std::reverse(b.begin(), b.end());
    int ans = 0;
    for (auto i : b) {
        s.change(1, 0, maxim, i);
        if (i != 0) {
            ans += s.sum(1, 0, maxim, 0, i - 1);
        }
    }
    cout << ans;
}
// + 0 0 2(2) 3(5) 1(6) 0(6) 2(8)