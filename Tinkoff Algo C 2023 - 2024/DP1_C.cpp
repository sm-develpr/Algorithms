//
// Created by Сергей on 06.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    vector<int> dp(n);
    dp[0] = l[0];
    dp[1] = l[1];
    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + l[i];
    }
    cout << dp.back();
}