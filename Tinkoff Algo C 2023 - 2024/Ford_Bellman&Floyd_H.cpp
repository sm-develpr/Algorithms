//
// Created by Сергей on 06.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;
double INF = 1.01;


int main() {
    int n, m;
    cin >> n >> m;
    int start, end, f, s;
    long double c;
    cin >> start >> end;
    vector<vector<long double> > g(n + 1, vector<long double>(n + 1, INF));
    for (int i = 0; i < m; ++i) {
        cin >> f >> s >> c;
        g[f][s] = c / 100;
        g[s][f] = c / 100;
    }
    for (int k = 1; k < n + 1; ++k) {
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (g[i][k] + g[k][j] - g[i][k] * g[k][j] >= 0) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j] - g[i][k] * g[k][j]);
                }
            }
        }
    }
    cout << g[start][end];
}
int main() {
    int n, m;
    cin >> n >> m;
    int start, end, f, s;
    long double c;
    cin >> start >> end;
    vector<vector<long double> > g(n + 1, vector<long double>(n + 1, INF));
    for (int i = 0; i < m; ++i) {
        cin >> f >> s >> c;
        g[f][s] = c / 100;
        g[s][f] = c / 100;
    }
    for (int k = 1; k < n + 1; ++k) {
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (g[i][k] + g[k][j] - g[i][k] * g[k][j] >= 0) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j] - g[i][k] * g[k][j]);
                }
            }
        }
    }
    cout << g[start][end];
}
