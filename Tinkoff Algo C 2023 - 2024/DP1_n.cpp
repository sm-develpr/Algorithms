//
// Created by Сергей on 13.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > dp(n);
    dp[1].push_back(1);
    dp[2].push_back(3);
    for (int i = 3; i < n; ++i) {
        if ((i + 1) % 2 == 0 && (i + 1) % 3 == 0) {
            if (dp[i - 1].size() <= dp[(i + 1)/2 - 1].size() && dp[i - 1].size() <= dp[(i + 1)/3 - 1].size()) {
                dp[i] = dp[i - 1];
                dp[i].push_back(1);
            } else if (dp[i - 1].size() >= dp[(i + 1)/2 - 1].size() && dp[(i + 1)/2 - 1].size() <= dp[(i + 1)/3 - 1].size()) {
                dp[i] = dp[(i + 1)/2 - 1];
                dp[i].push_back(2);
            } else {
                dp[i] = dp[(i + 1)/3 - 1];
                dp[i].push_back(3);
            }
        } else if ((i + 1) % 2 == 0) {
            if (dp[i - 1].size() <= dp[(i + 1)/2 - 1].size()) {
                dp[i] = dp[i - 1];
                dp[i].push_back(1);
            } else {
                dp[i] = dp[(i + 1)/2 - 1];
                dp[i].push_back(2);
            }
        } else if ((i + 1) % 3 == 0) {
            if (dp[i - 1].size() <= dp[(i + 1)/3 - 1].size()) {
                dp[i] = dp[i - 1];
                dp[i].push_back(1);
            } else {
                dp[i] = dp[(i + 1)/3 - 1];
                dp[i].push_back(3);
            }
        } else {
            dp[i] = dp[i - 1];
            dp[i].push_back(1);
        }
    }
    for (int i : dp[n - 1]) {
        cout << i;
    }
}