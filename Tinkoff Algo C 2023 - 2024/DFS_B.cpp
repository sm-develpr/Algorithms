//
// Created by Сергей on 25.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > graph(m);
    vector<vector<int> > h(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        cin >> graph[i].first >> graph[i].second;
        h[graph[i].first - 1][graph[i].second - 1] = 1;
        h[graph[i].second - 1][graph[i].first - 1] = 1;
    }
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            counter += h[i][j];
        }
        cout << counter << " ";
        counter = 0;
    }
}