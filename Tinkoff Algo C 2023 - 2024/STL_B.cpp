//
// Created by Сергей on 29.06.2024.
//
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    vector<int> res;
    deque<pair<int, int> > minum;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (i < k) {
            minum.push_back(make_pair(nums[i], i));
        }
    }
    sort(minum.begin(), minum.end());
    res.push_back(minum.front().first);
    for (int i = k; i < n; ++i) {
        while (!minum.empty() && minum.back().first >= nums[i]) {
            minum.pop_back();
        }
        minum.push_back(make_pair(nums[i], i));
        while (minum.front().second <= i - k) {
            minum.pop_front();
        }
        res.push_back(minum.front().first);
    }
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
}