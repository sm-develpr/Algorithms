//
// Created by Сергей on 18.06.2024.
//
#include <iostream>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    if (y > x) {
        swap(x,y);
    }
    n--;
    int l = 0;
    int r = n * x;
    while (r > l + 1) {
        int mid = (r + l)/2;
        if ((mid/x + mid/y) >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r + y;
}