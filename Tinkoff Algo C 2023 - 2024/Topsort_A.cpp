//
// Created by Сергей on 12.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, y;
    cin >> n >> m;
    vector<pair<int, int> > g(m);
    for (int i = 0; i < m; ++i) {
        cin >> g[i].first >> g[i].second;
    }
    vector<int> sort(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> y;
        sort[y] = i;
    }
    for (auto i : g) {
        if (!(sort[i.first] <= sort[i.second])) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
