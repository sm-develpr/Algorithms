//
// Created by Сергей on 24.03.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int min, k;
    cin >> min >> k;
    if (k != 0) {
        vector<int> a(k);
        vector<int> pyram;
        int count = 0;
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }

        sort(a.rbegin(), a.rend());
        if (a[0] >= min) {
            count++;
            pyram.push_back(a[0]);
            for (int i = 1; i < k; ++i) {
                if ((pyram[pyram.size() - 1] - a[i] > 2) && a[i] >= min) {
                    count++;
                    pyram.push_back(a[i]);
                }
            }
            cout << count;
        } else {
            cout << count;
        }
    }
    else {
        cout << 0;
    }
}