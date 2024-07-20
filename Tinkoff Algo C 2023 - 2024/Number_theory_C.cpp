//
// Created by Сергей on 19.07.2024.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll counter = 0;
    vector<ll> ans;
    for (ll i = 1; i < ll(sqrt(n)) + 1; ++i) {
        if (n % i == 0) {
            if (i * i == n) {
                counter++;
                ans.push_back(i);
            } else {
                counter = counter + 2;
                ans.push_back(i);
                ans.push_back(n / i);
            }
        }
    }
    cout << counter;
    std::sort(ans.begin(), ans.end());
    cout << '\n';
    for (long long an : ans) {
        cout << an << " ";
    }
}