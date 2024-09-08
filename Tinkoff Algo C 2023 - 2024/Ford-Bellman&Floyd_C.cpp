//
// Created by Сергей on 02.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;
int INF = 1e9;

struct rebr {
    int f, s, c;
    rebr(int fi, int se, int co) {
        f = fi;
        s = se;
        c = co;
    }
};

int main() {
    int n, m, f, s, c;
    cin >> n >> m;
    vector<rebr> g;
    for (int i = 0; i < m; ++i) {
        cin >> f >> s >> c;
        g.push_back(rebr(f, s, c));
    }
    vector<int> d(n + 1, INF);
    d[1] = 0;
    for (int i = 0; i < n; ++i) {
        for (auto e : g) {
            if (d[e.f] == INF) {
                continue;
            }
            if (d[e.s] > d[e.f] + e.c) {
                d[e.s] = max(-INF, d[e.f] + e.c);
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        if (d[i] == INF) {
            cout << 30000 << " ";
            continue;
        }
        cout << d[i] << " ";
    }
}