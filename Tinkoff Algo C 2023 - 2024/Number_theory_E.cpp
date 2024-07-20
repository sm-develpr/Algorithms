//
// Created by Сергей on 19.07.2024.
//
#include <iostream>
using namespace std;
typedef long long ll;

void gcd2(ll n, ll m) {
    while ((n > 1 || m > 1) && n != 0 && m != 0) {
        ll r = n;
        n = m;
        m = r % m;
    }
    cout << max(n, m);
}

int main() {
    ll n, m;
    cin >> n >> m;
    if (n < m) {
        swap(n, m);
    }
    gcd2(n, m);
}