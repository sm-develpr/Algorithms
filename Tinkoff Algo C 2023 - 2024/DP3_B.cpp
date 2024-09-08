//
// Created by Сергей on 23.08.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
const long long INT_m = 1e18;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> slimes(n);
    for (int i = 0; i < n; ++i) {
        cin >> slimes[i];
    }

    // Префиксные суммы
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + slimes[i - 1];
    }

    // DP таблица
    vector<vector<long long> > dp(n, vector<long long>(n, 0));

    // Пробегаем по всем длинам подстрок
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_m;

            // Находим минимальную стоимость разделения
            for (int k = i; k < j; ++k) {
                long long cost = dp[i][k] + dp[k + 1][j] + prefix_sum[j + 1] - prefix_sum[i];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // Минимальная стоимость для объединения всех слизней в одного
    cout << dp[0][n - 1] << endl;

    return 0;
}