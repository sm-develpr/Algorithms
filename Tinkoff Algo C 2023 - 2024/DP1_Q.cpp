//
// Created by Сергей on 14.07.2024.
//
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

const ll mod = 1000000007;
int cc(int n, int k) { // оптимальное решение с использованием массива преф сумм
    vector<ll> dp(n + 1, 0);
    vector<ll> pref_sum(n + 1, 0);
    pref_sum[0] = 1;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i - k <= 0) {
            dp[i] = (pref_sum[i - 1]) % mod;
        } else {
            dp[i] = dp[i] = (pref_sum[i - 1] - pref_sum[i - k - 1]) % mod;
        }
        pref_sum[i] = pref_sum[i - 1] + dp[i];
    }
    return dp[n];
}

int countWaysToReach(int n, int k) { // рещение праивльное но тайм лимит на 23 тесте не оптимальное
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }
    return dp[n];
}


int main() {
    /*for (int i = 1; i < 10000; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (cc(i, j) != countWaysToReach(i, j)) {
                cout << i << " " << j << '\n';
            }
        }
    }*/
    cout << countWaysToReach(33, 6) << '\n' << cc(33, 6);
}

// 2 1000
//Количество способов: 107579939