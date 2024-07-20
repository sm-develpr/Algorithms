//
// Created by Сергей on 06.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> fiba(46);

int fib(int n) {
    if (fiba[n] != -1) {
        return fiba[n];
    }
    return fiba[n] = fib(n-1) + fib(n-2);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 46; ++i) {
        fiba[i] = -1;
    }
    fiba[0] = fiba[1] = 1;
    cout << fib(n-1);
}