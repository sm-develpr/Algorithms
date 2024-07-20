//
// Created by Сергей on 19.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int gcd2(int n, int m) {
    while ((n > 1 || m > 1) && n != 0 && m != 0) {
        int r = n;
        n = m;
        m = r % m;
    }
    return max(n, m);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    cin >> nums[0];
    cin >> nums[1];
    int res;
    if (nums[1] > nums[0]) {
        res = gcd2(nums[1], nums[0]);
    } else {
        res = gcd2(nums[0], nums[1]);
    }
    for (int i = 2; i < n; ++i) {
        cin >> nums[i];
        if (res > nums[i]) {
            res = gcd2(res, nums[i]);
        } else {
            res = gcd2(nums[i], res);
        }
    }
    cout << res;
}