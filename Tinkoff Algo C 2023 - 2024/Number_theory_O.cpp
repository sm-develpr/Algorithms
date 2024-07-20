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
    int a, b, c;
    cin >> a >> b >> c;
    if (c % euclidean(abs(a), abs(b)) == 0) {
        int y = 1;
        while ((c - b * y) % a != 0) {
            y++;
        }
        int x =(c - b * y) / a;
        cout << euclidean(abs(a), abs(b)) << " " << x  << " " << y;
    } else {
        cout << "Impossible";
    }
}