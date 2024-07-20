//
// Created by Сергей on 18.06.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long > p(n);
    long long sum = 0;
    long long max = 99;
    for (long long i = 0; i < n; ++i) {
        cin >> p[i];
        sum += p[i];
        if (max < p[i]) {
            max = p[i];
        }
    }
    if (sum < k) {
        cout << 0;
    } else {
        long long l = 1;
        long long r =  1e9;
        while (r - l > 1) {
            long long couter = 0;
            long long mid = (r + l)/2;
            for (long long i = 0; i < n; ++i) {
                couter += p[i] / mid;
            }
            if (couter < k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << l;
    }
}