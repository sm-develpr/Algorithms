//
// Created by Сергей on 17.07.2024.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, y;
    cin >> n >> y;
    string a;
    cin >> a;
    vector<vector<int> > dp(n, vector<int>(n, -1));
    for (int i = n - 1; i >= 0; --i) {
        int k = i;
        int j = 0;
        do {
            int size = a.size() - k - j;
            if (size == 1) {
                dp[k][j] = 0;
            } else if (size == 3 || size == 2) {
                if (a[a.size() - 1 - j] != a[k]) {
                    dp[k][j] = 1;
                } else {
                    dp[k][j] = 0;
                }
            } else {
                if (a[a.size() - 1 - j] == a[k]) {
                    dp[k][j] = dp[k + 1][j + 1];
                } else {
                    dp[k][j] = dp[k + 1][j + 1] + 1;
                }
            }
            k--;
            j++;
        } while (k != -1);
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        int j = 0;
        int k = i;
        while (k != -1) {
            if (dp[k][j] <= y && dp[k][j] >= 0) {
                ans++;
            }
            j++;
            k--;
        }
    }
    cout << ans;
}