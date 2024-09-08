//
// Created by Сергей on 20.07.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > ot(n);
    vector<pair<int, int> > sost;
    vector<int> tochki(m);
    for (int i = 0; i < n; ++i) {
        cin >> ot[i].first >> ot[i].second;
        sost.push_back(make_pair(min(ot[i].first, ot[i].second), -1));
        sost.push_back(make_pair(max(ot[i].first, ot[i].second), 1));
    }
    for (int i = 0; i < m; ++i) {
        cin >> tochki[i];
        sost.push_back(make_pair(tochki[i], 0));
    }
    std::sort(sost.begin(), sost.end());
    vector<pair<int, int> > res;
    int cnt = 0;
    for (size_t i = 0; i < sost.size(); ++i) {
        if (sost[i].second == -1) {
            cnt++;
        } else if (sost[i].second == 0) {
            res.push_back(make_pair(sost[i].first, cnt));
        } else {
            cnt--;
        }
    }
    vector<int> rere(m);
    for (int i = 0; i < m; ++i) {
        int j = std::find(tochki.begin(), tochki.end(), res[i].first) - tochki.begin();
        tochki[j] = 1e9 - 1;
        rere[j] = res[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cout << rere[i] << " ";
    }
}
// блять люди не берите, написано хуево, но зашло