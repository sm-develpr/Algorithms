//
// Created by Сергей on 06.07.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n != 0 && m != 0) {
        vector<vector<int> > coins(n, vector<int>(m));
        vector<vector<int> > dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> coins[i][j];
            }
        }
        dp[0][0] = coins[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = coins[0][0];
                } else {
                    if (i > 0 && dp[i - 1][j] + coins[i][j] >= dp[i][j]) {
                        dp[i][j] = dp[i - 1][j] + coins[i][j];
                    }
                    if (j > 0 && dp[i][j - 1] + coins[i][j] >= dp[i][j]) {
                        dp[i][j] = dp[i][j - 1] + coins[i][j];
                    }
                }
            }
        }
        vector<char> result;
        int i = n - 1;
        int j = m - 1;
        while (i > 0 || j > 0) {
            if (i != 0 && (j == 0 || dp[i - 1][j] > dp[i][j - 1])) {
                i -= 1;
                result.push_back('D');
            } else {
                j -= 1;
                result.push_back('R');
            }
        }
        std::reverse(result.begin(), result.end());
        cout << dp[n - 1][m - 1] << '\n';
        for (char i : result) {
            cout << i << " ";
        }
    } else {
        cout << 0;
    }
}
