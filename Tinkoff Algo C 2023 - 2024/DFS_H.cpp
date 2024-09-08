//
// Created by Сергей on 26.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int bo = 0;
vector<int> ans;

void dfc(int counter, int v, vector<bool>& used, const vector<vector<int> >& g) {
    if (counter == bo) {
        ans.push_back(v);
    }
    if (counter > bo) {
        ans.clear();
        ans.push_back(v);
        bo = counter;
    }
    used[v - 1] = true;
    for (auto to : g[v - 1]) {
        if (!used[to - 1]) {
            dfc(counter + 1, to, used, g);
        }
    }
}
int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int> > g(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        g[u - 1].push_back(v);
        g[v - 1].push_back(u);
    }
    vector<bool> used(n, false);
    dfc(0, m, used, g);
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}