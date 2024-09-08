//
// Created by Сергей on 25.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

vector<bool> con(vector<bool> a, vector<bool> b) {
    vector<bool> c(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        c[i] = bool(a[i] || b[i]);
    }
    return c;
}


void dfc(int v, vector<bool>& used, const vector<vector<int> >& g) {
    used[v - 1] = true;
    for (auto to : g[v - 1]) {
        if (!used[to - 1]) {
            dfc(to, used, g);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > gr(m);
    vector<vector<int> > graph(n);
    for (int i = 0; i < m; ++i) {
        cin >> gr[i].first >> gr[i].second;
        graph[gr[i].first - 1].push_back(gr[i].second);
        graph[gr[i].second - 1].push_back(gr[i].first);
    }
    vector<bool> used(n, false);
    vector<vector<int> > ans;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            vector<bool> used1(n, false);
            dfc(i+1, used1, graph);
            used = con(used1, used);
            vector<int> h;
            for (int i = 0; i < n; ++i) {
                if (used1[i]) {
                    h.push_back(i + 1);
                }
            }
            ans.push_back(h);
        }
    }
    cout << ans.size() << '\n';
    for (auto j : ans) {
        cout << j.size() << '\n';
        for (auto k : j) {
            cout << k << " ";
        }
        cout << '\n';
    }
}