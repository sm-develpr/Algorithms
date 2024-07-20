//
// Created by Сергей on 26.03.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> line(n);
    for (int i = 0; i < n; ++i) {
        cin >> line[i];
    }

    int ans = line[0],
            ans_l = 0,
            ans_r = 0,
            sum = 0,
            min_sum = 0,
            min_pos = -1;
    for (int r = 0; r < n; ++r) {
        sum += line[r];
        int cur = sum - min_sum;
        if (cur > ans) {
            ans = cur;
            ans_l = min_pos + 1;
            ans_r = r;
        }

        if (sum < min_sum) {
            min_sum = sum;
            min_pos = r;
        }
    }
    if (n == 1) {
        cout << 1 << " " << 1 << " " << line[0];
    } else {
        cout << ans_l + 1   << " " << ans_r + 1   << " " << ans;
    }
}