//
// Created by Сергей on 27.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

void dfc(int v, vector<bool>& used, const vector<vector<int> >& g) {
    used[v - 1] = true;
    for (auto to : g[v - 1]) {
        if (!used[to - 1]) {
            dfc(to, used, g);
        }
    }
}

int main() {
    int n, m, counter = 0;
    cin >> n >> m;
    vector<vector<char> > table (n + 2, vector<char>(m + 2, '.'));
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            cin >> table[i][j];
            if (table[i][j] == '#') {
                counter++;
            }
        }
    }
    vector<vector<int> > g(n * m);
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            if (table[i][j] == '#') {
                if (table[i][j + 1] == '#') {
                    g[(i - 1) * m + j - 1].push_back((i - 1) * m + j + 1);
                    g[(i - 1) * m + j].push_back((i - 1) * m + j);
                }
                if (table[i + 1][j] == '#') {
                    g[(i - 1) * m + j - 1].push_back(i * m + j);
                    g[i * m + j - 1].push_back((i - 1) * m + j);
                }
            }
        }
    }
    vector<bool> visited(n * m, false);
    // можно доделать с помощью определения количества компонентов связности, мне это делать лень
}
