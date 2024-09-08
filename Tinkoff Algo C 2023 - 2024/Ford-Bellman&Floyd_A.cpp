//
// Created by Сергей on 02.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;
int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > d(n + 1, vector<int>(n + 1));
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cin >> d[i][j];
            if (d[i][j] == -1) {
                d[i][j] = INF;
            }
        }
    }
    for (int k = 1; k < n + 1; ++k) {
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int max_way = d[1][1];
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (d[i][j] > max_way && d[i][j] != INF) {
                max_way = d[i][j];
            }
        }
    }
    cout << max_way;
}