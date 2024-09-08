//
// Created by Сергей on 16.08.2024.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> pred;
vector<int> sz;
vector<int> ex;

void get_ex(int a, int sum) {
    sum += ex[a];
    if (a == pred[a]) {
        cout << sum << '\n';
        return;
    }
    get_ex(pred[a], sum);
}
int got(int a) {
    return (a == pred[a]) ? a : got(pred[a]);
}

void unite(int a, int b) {
    a = got(a);
    b = got(b);
    if (a == b) {
        return;
    }
    if (sz[a] < sz[b]) {
        ex[a] -= ex[b];
        sz[b] += sz[a];
        pred[a] = b;
    } else {
        ex[b] -= ex[a];
        sz[a] += sz[b];
        pred[b] = a;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, f, s;
    cin >> n >> m;
    string t;
    pred.resize(n + 1);
    sz.resize(n + 1, 1);
    ex.resize(n + 1, 0);
    for (int i = 1; i < n + 1; ++i) {
        pred[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        cin >> t;
        if (t == "get") {
            cin >> f;
            int sum = 0;
            get_ex(f, sum);
        } else {
            cin >> f >> s;
            if (t == "add") {
                ex[got(f)] += s;
            } else {
                unite(f, s);
            }
        }
    }
}