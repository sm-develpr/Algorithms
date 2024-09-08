//
// Created by Сергей on 14.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;
bool flag = false;
bool flag1 = false;
vector<bool> used;
struct vetsh {
    int n, wes;
    vetsh(int num, int w) {
        n = num;
        wes = w;
    }
};

void dfs(int v, int wes,  vector<vector<vetsh> >& g) {
    used[v] = 1;
    for (auto i : g[v]) {
        if (i.wes < wes) {
            flag = true;
            used[v] = 0;
        } else {
            if (!used[i.n]) {
                dfs(i.n, wes, g);
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    used.resize(n * m + 1);
    vector<vector<int > > tab(n + 1, vector<int>(m + 1));
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            cin >> tab[i][j];
        }
    }
    vector<vector<vetsh> > g(n * m + 1);
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            if (i - 1 >= 1 && tab[i][j] >= tab[i - 1][j]) {
                g[m * (i - 1) + j].push_back(vetsh(m * (i - 2) + j, tab[i - 1][j]));
            }
            if (j - 1 >= 1 && tab[i][j] >= tab[i][j - 1]) {
                g[m * (i - 1) + j].push_back(vetsh(m * (i - 1) + j - 1, tab[i][j - 1]));
            }
            if (j + 1 < m + 1 && tab[i][j] >= tab[i][j + 1]) {
                g[m * (i - 1) + j].push_back(vetsh(m * (i - 1) + j + 1, tab[i][j + 1]));
            }
            if (i + 1 < n + 1 && tab[i][j] >= tab[i + 1][j]) {
                g[m * (i - 1) + j].push_back(vetsh(i * m + j, tab[i + 1][j]));
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            if (!used[m * (i - 1) + j]) {
                if (g[m * (i - 1) + j].size() == 0) {
                    ans++;
                    used[m * (i - 1) + j] = 1;
                    continue;
                }
                for (auto k : g[m * (i - 1) + j]) {
                    if (k.wes < tab[i][j]) {
                        used[m * (i - 1) + j] = 1;
                        flag1 = true;
                    }
                }
                if (flag1) {
                    flag1 = false;
                    continue;
                }
                dfs(m * (i - 1) + j, tab[i][j], g);
                if (!flag) {
                    ans++;
                }
                flag = false;
            }
        }
    }
    cout << ans;
}