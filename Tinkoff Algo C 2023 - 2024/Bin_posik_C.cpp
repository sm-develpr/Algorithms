//
// Created by Сергей on 16.06.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> first(n);
    for (int i = 0; i < n; ++i) {
        cin >> first[i];
    }
    sort(first.begin(), first.end());
    cin >> k;
    vector<int> second(k);
    vector<int> result(k);
    for (int i = 0; i < k; ++i) {
        cin >> second[i];
        int r = n;
        int l = 0;
        while (r - l > 1) {
            int mid = (l + r)/2;
            if (first[mid] > second[i]) {
                r = mid;
            } else {
                l = mid;
            }
        }

        if (first[l] != second[i]) {
            result[i] = 0;
            continue;
        }
        result[i] = l;
        r = n - 1;
        l = -1;
        while (r - l > 1) {
            int mid = (l + r)/2;
            if (first[mid] < second[i]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (result[i] == r) {
            result[i] = 1;

        } else {
            result[i] = result[i] - l;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << result[i] << " ";
    }
}
