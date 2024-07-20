//
// Created by Сергей on 16.06.2024.
//
#include <iostream>
#include "cmath"
using namespace std;

int main() {
    long double a;
    cin >> a;
    long double l = 0;
    long double r = a;
    while (a - (pow(l, 2) + sqrt(l)) > 0.0000001) {
        long double mid = (l + r)/2;
        if ((pow(mid, 2) + sqrt(mid)) > a) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed;
    cout.precision(6);
    cout << l;
}