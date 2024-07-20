//
// Created by Сергей on 02.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, last, now, minimum = 10e8;
    cin >> n >> k;
    vector<int> m(n, 0);
    cin >> last;
    for (int i = 1; i < n; ++i) {
        cin >> now;
        if (last < now) {
            m[i] = m[i - 1] + 1;
        } else {
            m[i] = m[i - 1];
        }
        last = now;
    }
    for (int i = k - 1; i < n; ++i) {
        if (m[i] - m[i - k + 1] < minimum) {
            minimum = m[i] - m[i - k + 1];
        }
    }
    cout << minimum;
}