//
// Created by Сергей on 07.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dp(8, vector<int>(8));
    for (int i = 0; i < 8; ++i) {
        dp[7][i] = 1;
    }
    for (int i = 6; i > -1; --i) {
        for (int j = 0; j < 8; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i + 1][j + 1];
            } else if (j == 7) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = dp[i + 1][j - 1] + dp[i + 1][j + 1];
            }
        }
    }
    cout << dp[m - 1][n - 1];
}