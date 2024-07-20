//
// Created by Сергей on 19.07.2024.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    bool flag = true;
    vector<ll> ans;
    while (n != 1) {
        for (ll i = 2; i < ll(sqrt(n)) + 2; ++i) {
            if (n % i == 0) {
                ans.push_back(i);
                n = n / i;
                break;
            }
            if (i < (ll(sqrt(n)) + 2) && (i + 1) >= ll(sqrt(n)) + 2) {
                ans.push_back(n);
                n = 1;
            }
        }
    }
    for (size_t i = 0; i < ans.size(); ++i) {
        int counter = 1;
        while (ans[i] == ans[i + 1]) {
            counter++;
            i++;
        }
        if (counter == 1) {
            if (flag) {
                cout << ans[i];
                flag = false;
            } else {
                cout << "*" << ans[i];
            }
        } else if (flag) {
            cout << ans[i] << "^" << counter;
            flag = false;
        } else {
            cout << "*" << ans[i] << "^" << counter;
        }
    }
}