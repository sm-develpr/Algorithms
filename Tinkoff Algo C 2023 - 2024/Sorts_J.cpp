//
// Created by Сергей on 24.03.2024.
//
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    for (size_t i = 0; i < a.size(); ++i) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> l(k);
    for (size_t i = 0; i < k; ++i) {
        cin >> l[i];
    }

    sort(a.begin(), a.end());
    sort(l.begin(), l.end());
    size_t aptr = 0;
    size_t lptr = 0;
    int count = 0;
    while (lptr < l.size() && aptr < a.size()) {
        if (l[lptr] <= a[aptr]) {
            lptr++;
            count++;
        }
        aptr++;
    }
    cout << count;
}