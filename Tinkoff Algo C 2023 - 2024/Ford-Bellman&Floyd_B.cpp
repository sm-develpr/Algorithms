//
// Created by Сергей on 02.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;
int INF = 101;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1, vector<int>(n + 1));
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 0 && i != j) {
                g[i][j] = INF;
            }
        }
    }
    for (int k = 1; k < n + 1; ++k) {
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (g[i][k] < INF && g[k][j] < INF) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    if (g[i][j] <= -INF) {
                        g[i][j] = -INF;
                    }
                }
            }
        }
    }
    vector<vector<int> > res(n + 1, vector<int>(n + 1));
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (g[i][j] == INF) {
                res[i][j] = 0;
            } else {
                res[i][j] = 1;
            }
            for (int k = 1; k < n + 1; ++k) {
                if ((g[k][k] < 0) && (g[i][k] < INF) && (g[k][j] < INF)) {
                    res[i][k] = 2;
                    res[i][j] = 2;
                    res[k][j] = 2;
                }
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }
}