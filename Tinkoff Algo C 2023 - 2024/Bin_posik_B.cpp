//
// Created by Сергей on 16.06.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    int ll, rr;
    cin >> n >> k;
    vector<int> first(n);
    vector<int> second(k);
    vector<int> result(k);
    for (int i = 0; i < n; ++i) {
        cin >> first[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> second[i];
        int r = n - 1;
        int l = 0;
        while (r - l > 1) {
            int mid = (l + r)/2 + 1;
            if (first[mid] >= second[i]) {
                r = mid;
            } else {
                l = mid;
            }

        }
        if (first[l] == second[i]) {
            ll = l;

        } else {
            ll = r;
        }
        r = n - 1;
        l = 0;
        while (r - l > 1) {
            int mid = (l + r)/2 + 1;
            if (first[mid] > second[i]) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (first[l] == second[i]) {
            rr = l;

        } else {
            rr = r;
        }
        result[i] = rr - ll + 1;
    }
    for (int i = 0; i < k; ++i) {
        cout << result[i] << " ";
    }
}