//
// Created by Сергей on 24.06.2024.
//
#include <iostream>
#include "queue"
#include "vector"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > result;
    vector<pair<int, int> > p;
    int h, m, t;
    for (size_t i = 0; i < n; ++i) {
        cin >> h >> m >> t;
        if (p.empty()) {
            p.push_back(make_pair(h, m));
            result.push_back(make_pair(h + int((m + 20) / 60), ((m + 20) % 60)));
            continue;
        } else if ((h * 60 + m - p.back().first * 60 - p.back().second) > 19) {
            p.clear();
            p.push_back(make_pair(h, m));
            result.push_back(make_pair(h + int((m + 20) / 60), (m + 20) % 60));
            continue;
        } else if ((h * 60 + m - p.front().first * 60 - p.front().second) > 19) {
            int c = 0;
            while ((h * 60 + m - p.front().first * 60 - p.front().second) > 19) {
                p.erase(p.begin());
                c++;
            }
            if (t >= int(p.size() + c)) {
                p.push_back(make_pair(h, m));
                result.push_back(make_pair(p.front().first + int((m + 20 * (c+p.size())) / 60), ((p.front().second + 20 * (c+p.size())) % 60)));
                continue;
            } else {
                result.push_back(make_pair(h, m));
                continue;
            }
        }
        if (t >= int(p.size())) {
            p.push_back(make_pair(h, m));
            result.push_back(make_pair(p.front().first + int((m + 20 * p.size()) / 60), ((p.front().second + 20 * p.size()) % 60)));
        } else {
            result.push_back(make_pair(h, m));
        }
    }
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i].first << " " << result[i].second << "\n";
    }
}