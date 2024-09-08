//
// Created by Сергей on 06.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1, vector<int>(n + 1));
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cin >> g[i][j];
        }
    }
    for (int k = 1; k < n + 1; ++k) {
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (g[i][j] || (g[i][k] && g[k][j])) {
                    g[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cout << g[i][j] << " ";
        }
        cout << '\n';
    }
}