//
// Created by Сергей on 05.07.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > result;
double time() {
    clock_t cl = clock( );
    if (cl != (clock_t)-1 )
        return (double)cl / (double)CLOCKS_PER_SEC;
}

void f(int l, int n, int count, vector<int> a) {
    if (count == n) {
        std::sort(a.begin(), a.end());
        result.push_back(a);
        return;

    }
    if (count > n) {
        return;
    }
    for (int i = 1; i < l + 1; ++i) {
        vector<int> b;
        b = a;
        b.push_back(i);
        f(i, n, count + i, b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int count = 0;
    vector<int> a;
    f(n, n, count, a);
    sort(result.rbegin(), result.rend());
    for (vector<int> i : result) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << '\n';
    }
    cout << time();
}