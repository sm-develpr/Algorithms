//
// Created by Сергей on 19.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> m >> n;
    vector<bool> a(n + 1, true);
    a[1] = false;
    for (int i = 2; i < n + 1; ++i) {
        if (a[i]) {
            for (int j = 2 * i; j < n + 1; j = j + i) {
                a[j] = false;
            }
        }
    }
    for (int i = 2; i < n + 1; ++i) {
        if (a[i] && i >= m) {
            cout << i << " ";
        }
    }
}