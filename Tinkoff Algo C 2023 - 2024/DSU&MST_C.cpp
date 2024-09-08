//
// Created by Сергей on 16.08.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> pred;
vector<int> sz;

int get(int a) {
    return (a == pred[a]) ? a : pred[a] = get(pred[a]);
}

bool check(int a, int b) {
    return (get(a) == get(b));
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
        sz[a] += sz[b];
    }
}

struct triple {
    string type;
    int a, b;
    triple(string t, int v, int u) {
        type = t;
        a = v;
        b = u;
    }
    triple() {}
};

int main() {
    int n, m, k, f, s;
    string h;
    cin >> n >> m >> k;
    pred.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 1; i < n + 1; ++i) {
        pred[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        cin >> f >> s;
    }
    vector<triple> asks;
    for (int i = 0; i < k; ++i) {
        cin >> h >> f >> s;
        asks.push_back(triple(h, f, s));
    }
    std::reverse(asks.begin(), asks.end());
    vector<string> sends;
    for (auto i : asks) {
        if (i.type == "ask") {
            sends.push_back(check(i.a, i.b) ? "YES" : "NO");
        } else {
            unite(i.a, i.b);
        }
    }
    std::reverse(sends.begin(), sends.end());
    for (auto i : sends) {
        cout << i << '\n';
    }
}
