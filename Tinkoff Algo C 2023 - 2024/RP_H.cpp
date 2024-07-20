//
// Created by Сергей on 05.07.2024.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// Кому надо все робит, но написано хуево, можно не понимать
vector<vector<int> > l;

void f(int N, bool flag, int n, int m, vector<int> a) {
    if (flag) {
        int counter = 1;
        for (size_t u = 0; u < a.size(); ++u) {
            counter *= a[u];
        }
        if (counter != N) {
            return;
        }
        std::sort(a.begin(), a.end());
        for (auto j : l) {
            if (j == a) {
                return;
            }
        }
        l.push_back(a);
        return;
    }
    for (int i = 2; i <= int(sqrt(n)) + 1; ++i) {
        if (i + 1 >= int(sqrt(n)) + 1) {
            vector<int> b;
            b = a;
            if (n != 1 && n >= m) {
                b.push_back(n);
            }
            f(N, true, n / i, m, b);
        }
        if (n % i == 0 && i >= m) {
            vector<int> b;
            b = a;
            b.push_back(i);
            f(N, false, n / i, m, b);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a;

    f(n, false, n, m, a);

    sort(l.begin(), l.end());

    for (vector<int> k : l) {
        for (size_t i = 0; i < k.size() - 1; ++i) {
            cout << k[i] << "*";
        }
        cout << k[k.size() - 1];
        cout << '\n';
    }
}

// 2 2  3 2  4 2  6 2   36 2