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
    vector<vector<int> > dp(n + 1, vector<int>(w + 1, 0));
    dp[0][0] = 1;
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        cin >> ves[i];
        sum += ves[i];
    }
    if (sum < w) {
        cout << "no";
    } else {
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < ves[i]; ++j) {
                if (j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            for (int j = ves[i]; j < w + 1; ++j) {
                if (dp[i - 1][j] || dp[i - 1][j - ves[i]]) {
                    dp[i][j] = 1;
                }
            }
        }
        if (dp[n][w]) {
            cout << "yes";
        } else {
            cout << "no";
        }
    }
}