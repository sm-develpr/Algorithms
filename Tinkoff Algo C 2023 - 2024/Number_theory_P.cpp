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
    cin >> a >> b;
    c = 1;
    if (c % euclidean(abs(a), abs(b)) == 0) {
        int y = 1;
        while ((c - b * y) % a != 0) {
            y++;
        }
        int x =(c - b * y) / a;
        int ans = x;
        while (0 > ans || ans > b) {
            if (ans > b) {
                ans -= b / euclidean(a, b);
            } else {
                ans += b / euclidean(a, b);
            }
        }
        cout << ans;
    } else {
        cout << "Impossible";
    }
}