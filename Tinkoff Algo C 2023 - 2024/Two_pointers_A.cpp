//
// Created by Сергей on 25.03.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    int m;
    cin >> n >> m;
    vector<long long> statements(n);
    for (long long i = 0; i < n; ++i) {
        cin >> statements[i];
    }

    long long left = 0;
    long long right = 1;
    long long counter = 0;
    while (left != n-1 && right != n) {
        if (statements[right] - statements[left] <= m) {
            right++;
        } else {
            left++;
            counter+= n - right;
        }
    }
    cout << counter;
}