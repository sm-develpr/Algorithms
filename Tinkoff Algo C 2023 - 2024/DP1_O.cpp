//
// Created by Сергей on 13.07.2024.
//
#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<ll> > dp(n, vector<ll>(10));
    for (int i = 0; i < 10; ++i) {
        dp[0][i] = 1;
    }
    dp[0][0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
            } else if (j == 9) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
        }
    }
    ll suma = 0;
    for (int i = 0; i < 10; ++i) {
        suma += dp[n - 1][i];
    }
    cout << suma;
}