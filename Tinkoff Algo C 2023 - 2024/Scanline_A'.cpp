//
// Created by Сергей on 22.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

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
    vector<pair<int, int> > sost;
    for (int i = 0; i < n; ++i) {
        cin >> ot[i].first >> ot[i].second;
        sost.push_back(make_pair(ot[i].first, -1));
        sost.push_back(make_pair(ot[i].second, 1));
    }
    std::sort(sost.begin(), sost.end());
    vector<pair<int, int> > res;
    int cnt = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (sost[i].second == -1) {
            if (cnt == 0) {
                res.push_back(make_pair(sost[i].first, 0));
            }
            cnt++;
        } else {
            cnt--;
            if (cnt == 0) {
                res.back().second = sost[i].first;
            }
        }
    }
    cout << res.size() << '\n';
    for (auto & re : res) {
        cout << re.first << " " << re.second << '\n';
    }
}