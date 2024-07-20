//
// Created by Сергей on 03.07.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void f(int n, vector<int> a, string str = "") {
    if (n == 0) {
        cout << str << "\n";
    }
    for (auto x : a) {
        vector<int> b;
        b = a;
        b.erase(std::find(b.begin(), b.end(), x));
        f(n - 1, b, str + to_string(x));
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    f(n, a);
}