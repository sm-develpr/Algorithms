//
// Created by Сергей on 19.07.2024.
//
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    bool flag = true;
    for (ll i = 2; i < ll(sqrt(n)) + 1; ++i) {
        if (n % i == 0) {
            cout << "composite";
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "prime";
    }
}