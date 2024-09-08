//
// Created by Сергей on 16.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;
vector<int> pred;
vector<int> sz;

int get(int a) {
    return (pred[a] == a) ? a : pred[a] = get(pred[a]);
}

bool check(int a, int b) {
    return get(a) == get(b);
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) {
        return;
    }
    if (sz[a] < sz[b]) {
        pred[a] = b;
        sz[b] += sz[a];
    } else {
        pred[b] = a;
        sz[a] += b;
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
        if (a == 1) {
            unite(b, c);
        } else {
            cout << (check(b, c) ? "YES" : "NO") << '\n';
        }
    }
}