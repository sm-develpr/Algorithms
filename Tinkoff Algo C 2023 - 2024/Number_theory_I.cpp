//
// Created by Сергей on 19.07.2024.
//
#include <iostream>
using namespace std;

int main() {
    int res = 0, n, m;
    cin >> n >> m;
    if (n < m) {
        swap(n, m);
    }
    while (n != 0 && m != 0) {
        res += int(n / m);
        n = n % m;
        swap(n, m);
    }
    cout << res;
}