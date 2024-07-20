//
// Created by Сергей on 12.07.2024.
//
#include "iostream"
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dp(n + 4, vector<int>(m + 4, 0));
    int x_ptr = 2;
    for (int i = 2; i < n + 2; ++i) {
        dp[i][x_ptr] = dp[i - 2][x_ptr + 1] + dp[i - 2][x_ptr - 1] + dp[i - 1][x_ptr - 2] + dp[i + 1][x_ptr - 2];
        // cout << i << " " << x_ptr << '\n';
        if (i == 2) {
            dp[2][2] = 1;
        }
        int h = i;
        while (h > 2) {
            h--;
            x_ptr++;
            dp[h][x_ptr] = dp[h - 2][x_ptr + 1] + dp[h - 2][x_ptr - 1] + dp[h - 1][x_ptr - 2] + dp[h + 1][x_ptr - 2];
            // cout << h << " " << x_ptr << '\n';
        }
        x_ptr = 2;
    }
    int y_ptr = n + 1;
    for (int i = 3; i < m + 2; ++i) {
        int k = i;
        dp[y_ptr][k] = dp[y_ptr - 2][k + 1] + dp[y_ptr - 2][k - 1] + dp[y_ptr - 1][k - 2] + dp[y_ptr + 1][k - 2];
        // cout << y_ptr << " " << k << '\n';

        while (k < m + 1 && y_ptr > 2) {
            k++;
            y_ptr--;
            dp[y_ptr][k] = dp[y_ptr - 2][k + 1] + dp[y_ptr - 2][k - 1] + dp[y_ptr - 1][k - 2] + dp[y_ptr + 1][k - 2];
            // cout << y_ptr << " " << k << '\n';
        }
        y_ptr = n + 1;
    }
    // cout << '\n';
    cout << dp[n + 1][m + 1];
}