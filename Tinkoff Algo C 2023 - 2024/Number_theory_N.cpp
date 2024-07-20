//
// Created by Сергей on 20.07.2024.
//
#include <iostream>
using namespace std;

int euclidean(int n, int m) {
    while (m != 0) {
        int t = m;
        m = n % m;
        n = t;
    }
    return n;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << euclidean(a - 1, b - 1) + 1;
}