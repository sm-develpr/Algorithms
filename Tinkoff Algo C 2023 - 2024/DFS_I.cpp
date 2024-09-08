//
// Created by Сергей on 26.07.2024.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(int v, int n, vector<int> way, vector<vector<int> > &g) {
    if (v > n) {
        cout << 123;
        exit(0);
    }
    if (v == n) {
        for (int i : way) {
            cout << i << " ";
        }
        exit(0);
    }
    for (int to : g[v - 1]) {
        way.push_back(to);
        dfs(to, n, way, g);
        way.pop_back();
    }
}

int main() {
    int n, u;
    cin >> n;
    vector<vector<int> > g(n);
    for (int i = 1; i < n; ++i) {
        cin >> u;
        g[u - 1].push_back(i + 1);
    }
    vector<int> way;
    way.push_back(1);
    dfs(1, n, way, g);
}