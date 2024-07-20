//
// Created by Сергей on 12.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dp(n + 2, vector<int>(m + 2, 0));
    for (int i = 2; i < n + 2; ++i) {
        for (int j = 2; j < m + 2; ++j) {
            if (j == 2 && i == 2) {
                dp[2][2] = 1;
            } else {
                dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j - 2];
            }
        }
    }
    cout << dp[n + 1][m + 1];
}