//
// Created by Сергей on 20.08.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;
struct tripl {
    int f, s, cost;
    tripl(int a, int b, int c) {
        f = a;
        s = b;
        cost = c;
    }
    tripl();
};
bool comp(tripl a, tripl b) {
    return a.cost < b.cost;
}
vector<tripl> g;
vector<int> pred;
vector<int> sz;

int get(int a) {
    return (a == pred[a]) ? a : pred[a] = get(pred[a]);
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) {
        return;
    }
    if (sz[a] < sz[b]) {
        sz[b] += sz[a];
        pred[a] = b;
    } else {
        sz[a] += sz[b];
        pred[b] = a;
    }
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    pred.resize(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        pred[i] = i;
    }
    sz.resize(n + 1, 1);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        g.push_back(tripl(a, b, c));
    }
    sort(g.begin(), g.end(), comp);
    int ans = 0;
    for (size_t i = 0; i < g.size(); ++i) {
        if (get(g[i].f) != get(g[i].s)) {
            ans += g[i].cost;
            unite(g[i].f, g[i].s);
        }
    }
    cout << ans;
}