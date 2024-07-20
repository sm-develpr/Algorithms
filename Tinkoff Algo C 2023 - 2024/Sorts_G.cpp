//
// Created by Сергей on 24.03.2024.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    for (int item : nums) {
        cout << item << " ";
    }

}