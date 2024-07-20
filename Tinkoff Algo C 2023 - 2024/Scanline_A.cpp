//
// Created by Сергей on 20.07.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > ot(n);
    vector<pair<int, int> > sost(2*n);
    for (int i = 0; i < n; ++i) {
        cin >> ot[i].first >> ot[i].second;
        sost.push_back(make_pair(ot[i].first, -1));
        sost.push_back(make_pair(ot[i].second, 1));
    }
    std::sort(sost.begin(), sost.end());
    int cnt = 0;
    int max_cnt = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (sost[i].second == -1) {
            cnt++;
            if (cnt > max_cnt) {
                max_cnt = cnt;
            }
        } else {
            cnt--;
        }
    }
    cout << max_cnt;
}