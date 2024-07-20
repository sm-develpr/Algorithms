//
// Created by Сергей on 26.03.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define int int64_t

int32_t main() {
    int n;
    cin >> n;
    int max_el = -1e9;
    vector<pair<int, int> > cows(n);
    map<int, int> a;

    for (int i = 0; i < n; ++i) {
        cin >> cows[i].first >> cows[i].second;
        a[cows[i].second]++;
        if (cows[i].second > max_el) {
            max_el = cows[i].second;
        }
    }

    int dif_n = a.size();
    bool flag = false;
    sort(cows.begin(), cows.end());
    int ans = 1e18;
    int l = 0, r = 0;
    while (l < n && r < n) {
        int dif = 0;
        vector<int> b(abs(max_el)+1);
        while (r < n && dif != dif_n) {
            if (b[cows[r].second] == 0) {
                dif++;
            }
            b[cows[r].second]++;
            r++;
        }
        if (dif == dif_n) {
            flag = true;
        }
        r--;
        while (l < n) {
            if (b[cows[l].second] <= 1) {
                break;
            } else {
                b[cows[l].second]--;
                l++;
            }
        }
        if (flag && cows[r].first - cows[l].first < ans) {
            ans = cows[r].first - cows[l].first;
        }
        flag = false;
        l++;
        r = l;
    }

    cout << ans;
}