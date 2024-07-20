//
// Created by Сергей on 26.03.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    vector<float> time(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        time[i] = (l * 1.0 / a[i]);
        cout << time[i] << " ";
    }

}