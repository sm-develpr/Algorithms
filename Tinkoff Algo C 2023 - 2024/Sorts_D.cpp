//
// Created by Сергей on 23.03.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > contestants;
    int num_contestant;
    int points;
    for (int i = 0; i < n; ++i) {
        cin >> num_contestant >> points;
        contestants.push_back(make_pair(num_contestant, points));
    }
    sort(contestants.begin(), contestants.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        return tie(a.second, b.first) > tie(b.second, a.first);
    });
    for (int i = 0; i < n; ++i) {
        cout << contestants[i].first << " " << contestants[i].second << "\n";
    }
}
