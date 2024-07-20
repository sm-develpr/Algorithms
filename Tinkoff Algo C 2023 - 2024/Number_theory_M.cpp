//
// Created by Сергей on 19.07.2024.
//
#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n) {
    for (int i = 2; i < int(sqrt(n)) + 1; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        if (prime(i) && prime(n - i)) {
            if (i > n - i) {
                cout << n - i << " " << i;
                break;
            } else {
                cout << i << " " << n - i;
                break;
            }
        }
    }
}