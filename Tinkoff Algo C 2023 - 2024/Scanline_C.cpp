//
// Created by Сергей on 22.07.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    vector<pair<int, int> > events;
    int n;
    cin >> n;
    int h1, m1, s1, h2, m2, s2;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        if (h1 == h2 && m1 == m2 && s1 == s2) {
            cnt++;
            continue;
        } else if (h1 > h2 || (h1 == h2 && m1 > m2) || (h1 == h2 && m1 == m2 && s1 > s2)) {
            events.push_back(make_pair(h1 * 3600 + m1 * 60 + s1, 1));
            events.push_back(make_pair(86400, -1));
            events.push_back(make_pair(0, 1));
            events.push_back(make_pair(h2 * 3600 + m2 * 60 + s2, -1));
        } else {
            events.push_back(make_pair(h1 * 3600 + m1 * 60 + s1, 1));
            events.push_back(make_pair(h2 * 3600 + m2 * 60 + s2, -1));
        }
    }
    std::sort(events.begin(), events.end());
    int ans = 0;
    for (size_t i = 0; i < events.size(); ++i) {
        if (events[i].second == 1) {
            cnt++;
            if (cnt == n) {
                ans += events[i + 1].first - events[i].first;
            }
        } else {
            cnt--;
        }
    }
    if (cnt == events.size()) {
        cout << 86400;
    } else {
        cout << ans;
    }
}