//
// Created by Сергей on 23.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

void dfc(int v, vector<bool>& used, const vector<vector<int> >& g) {
    used[v] = true;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfc(to, used, g);
        }
    }
}