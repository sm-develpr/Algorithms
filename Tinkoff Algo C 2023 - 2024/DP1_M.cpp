//
// Created by Сергей on 13.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<vector<ll> > dp(n, vector<ll>(10));
    for (int i = 0; i < 10; ++i) {
        dp[0][i] = 1;
    }
    dp[0][0] = 0;
    dp[0][8] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][4] + dp[i - 1][6];
                } else if (j == 1) {
                    dp[i][j] = dp[i - 1][6] + dp[i - 1][8];
                } else if (j == 2) {
                    dp[i][j] = dp[i - 1][7] + dp[i - 1][9];
                } else if (j == 3) {
                    dp[i][j] = dp[i - 1][4] + dp[i - 1][8];
                } else if (j == 4) {
                    dp[i][j] = dp[i - 1][3] + dp[i - 1][0] + dp[i - 1][9];
                } else if (j == 5) {
                    dp[i][j] = 0;
                } else if (j == 6) {
                    dp[i][j] = dp[i - 1][1] + dp[i - 1][7] + dp[i - 1][0];
                } else if (j == 7) {
                    dp[i][j] = dp[i - 1][2] + dp[i - 1][6];
                } else if (j == 8) {
                    dp[i][j] = dp[i - 1][1] + dp[i - 1][3];
                } else if (j == 9) {
                    dp[i][j] = dp[i - 1][2] + dp[i - 1][4];
                }
            }
        }
    ll suma = 0;
    for (int i = 0; i < 10; ++i) {
        suma += dp[n - 1][i];
    }
    cout << suma;
}
