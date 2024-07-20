//
// Created by Сергей on 14.07.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> ves(n + 1);
    vector<vector<bool> > dp(n + 1, vector<bool>(w + 1, 0));
    for (int i = 1; i < n + 1; ++i) {
        cin >> ves[i];
    }
    for (int i = 0; i < n + 1; ++i) {
        dp[i][0] = true;
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < ves[i]; ++j) {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = ves[i]; j < w + 1; ++j) {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - ves[i]];
        }
    }
    for (int i = w; i >= 0; --i) {
        if (dp[n][i] == 1) {
            cout << i;
            break;
        }
    }
}
