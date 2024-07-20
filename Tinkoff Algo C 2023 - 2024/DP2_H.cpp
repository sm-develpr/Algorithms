//
// Created by Сергей on 18.07.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> prev(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }
    int pos = 0;
    int l = dp[0];
    for (int i = 1; i < n; ++i) {
        if (l < dp[i]) {
            l = dp[i];
            pos = i;
        }
    }
    vector<int> ans;
    while (pos != -1) {
        ans.push_back(a[pos]);
        pos = prev[pos];
    }
    cout << l << '\n';
    /*reverse(ans.begin(), ans.end());
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
*/
}