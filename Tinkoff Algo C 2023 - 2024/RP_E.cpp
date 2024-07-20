//
// Created by Сергей on 04.07.2024.
//
#include <iostream>
#include <string>
#include "vector"
#include "algorithm"
using namespace std;

void f(int o, int n, int k, vector<int> a) {
    if (k == 0) {
        for (size_t l = 0; l < a.size(); ++l) {
            cout << a[l] << ' ';
        }
        cout << '\n';
        a.clear();
        return;
    }
    for (int j = k; j < o + 1; ++j) {
        vector<int> b;
        b = a;
        b.push_back(j);
        f(j - 1, n - 1, k - 1, b);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    f(n, n, k, a);
}