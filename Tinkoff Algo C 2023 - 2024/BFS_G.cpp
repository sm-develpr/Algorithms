//
// Created by Сергей on 29.07.2024.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n * m + 1);
    vector<vector<char> > table(n + 2, vector<char>(m + 2, '#'));
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            cin >> table[i][j];
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            if (table[i][j] == '.') {
                if (table[i + 1][j] == '.') {
                    g[(i - 1) * m + j].push_back(i * m + j);
                    g[i * m + j].push_back((i - 1) * m + j);
                }
                if (table[i][j + 1] == '.') {
                    g[(i - 1) * m + j].push_back((i - 1) * m + j + 1);
                    g[(i - 1) * m + j + 1].push_back((i - 1) * m + j);
                }
            }
        }
    }
    int start = 1;
        int end = n * m;
        queue<int> d;
        d.push(start);
        vector<int> dist(n * m + 1, -1);
        dist[start] = 0;
        while (!d.empty()) {
            int v = d.front();
            d.pop();
            for (int i : g[v]) {
                if (dist[i] == -1) {
                    dist[i] = dist[v] + 1;
                    d.push(i);
                }
            }
        }
        cout << dist[end];
}

// ебвл тестирующую систему в жопу
/*
2 10
.###..##..
.....#....*/
