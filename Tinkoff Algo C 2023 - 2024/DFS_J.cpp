//
// Created by Сергей on 27.07.2024.
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, y, u;
    cin >> n >> m;
    vector<vector<int> > g(n);
    for (int i = 0; i < m; ++i) {
        cin >> y >> u;
        g[y - 1].push_back(u);
        g[u - 1].push_back(y);
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == n - 1) {
            cout << i + 1;
            break;
        } else {
            unordered_set<int> sos;
            for (int j : g[i]) {
                sos.insert(j);
            }
            for (auto j : g[i]) {
                for (int e : g[j - 1]) {
                    sos.insert(e);
                }
            }
            if (sos.size() == n) {
                cout << i + 1;
            }
        }
    }
}

