//
// Created by Сергей on 14.07.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> sost(n, 0);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sost[i] == 0) {
            int minu = 0;
            if (i == 0) {
                minu = a[i + 1] - a[i];
                sum += minu;
                sost[i + 1]++;
            } else if (i == n - 1) {
                sum += a[i] - a[i - 1];
            } else {
                minu = min(a[i] - a[i - 1], a[i + 1] - a[i]);
                if (minu == a[i + 1] - a[i]) {
                    sum += minu;
                    sost[i + 1]++;
                } else {
                    sum += minu;
                }
            }
        }
    }
    cout << sum;
}