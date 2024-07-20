//
// Created by Сергей on 19.07.2024.
//
#include <iostream>
#include <cmath>
using namespace std;

int gcd2(int n, int m) {
    while ((n > 1 || m > 1) && n != 0 && m != 0) {
        int r = n;
        n = m;
        m = r % m;
    }
    return max(n, m);
}


int main() {
    int n, m, a, b, c, d;
    cin >> a >> b >> c >> d;
    n = a * d + c * b;
    m = b * d;
    if (n <= m) {
        int t = gcd2(m, n);
        n /= t;
        m /= t;
    } else {
        int t = gcd2(n, m);
        n /= t;
        m /= t;
    }
    cout << n << " " << m;
}