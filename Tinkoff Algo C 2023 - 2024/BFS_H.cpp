//
// Created by Сергей on 29.07.2024.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    queue<pair<int, int> > q;
    vector<vector<pair<int, int> > > prev(n + 1, vector<pair<int, int> >(n + 1, make_pair(-1, -1)));
    q.push(make_pair(x1, y1));
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        if (v.first == x2 && v.second == y2) {
            break;
        }
        if (1 <= v.first - 2 && v.second + 1 <= n) {
            if (prev[v.first - 2][v.second + 1] == make_pair(-1, -1)) {
                prev[v.first - 2][v.second + 1] = v;
                q.push(make_pair(v.first - 2, v.second + 1));
            }
        }
        if (1 <= v.first - 2 && 1 <= v.second - 1) {
            if (prev[v.first - 2][v.second - 1] == make_pair(-1, -1)) {
                prev[v.first - 2][v.second - 1] = v;
                q.push(make_pair(v.first - 2, v.second - 1));
            }
        }
        if (1 <= v.first - 1 && 1 <= v.second - 2) {
            if (prev[v.first - 1][v.second - 2] == make_pair(-1, -1)) {
                prev[v.first - 1][v.second - 2] = v;
                q.push(make_pair(v.first - 1, v.second - 2));
            }
        }
        if (n >= v.first + 1 && 1 <= v.second - 2) {
            if (prev[v.first + 1][v.second - 2] == make_pair(-1, -1)) {
                prev[v.first + 1][v.second - 2] = v;
                q.push(make_pair(v.first + 1, v.second - 2));
            }
        }
        if (n >= v.first + 2 && 1 <= v.second - 1) {
            if (prev[v.first + 2][v.second - 1] == make_pair(-1, -1)) {
                prev[v.first + 2][v.second - 1] = v;
                q.push(make_pair(v.first + 2, v.second - 1));
            }
        }
        if (n >= v.first + 2 && n >= v.second + 1) {
            if (prev[v.first + 2][v.second + 1] == make_pair(-1, -1)) {
                prev[v.first + 2][v.second + 1] = v;
                q.push(make_pair(v.first + 2, v.second + 1));
            }
        }
        if (n >= v.first + 1 && n >= v.second + 2) {
            if (prev[v.first + 1][v.second + 2] == make_pair(-1, -1)) {
                prev[v.first + 1][v.second + 2] = v;
                q.push(make_pair(v.first + 1, v.second + 2));
            }
        }
        if (1 <= v.first - 1 && n >= v.second + 2) {
            if (prev[v.first - 1][v.second + 2] == make_pair(-1, -1)) {
                prev[v.first - 1][v.second + 2] = v;
                q.push(make_pair(v.first - 1, v.second + 2));
            }
        }
    }
    vector<pair<int, int> > ans;
    pair<int, int> a;
    a.first = x2;
    a.second = y2;
    ans.push_back(a);
    while (a != make_pair(x1, y1)) {
        if (a.first < 0 || a.second < 0) {
            cout << -1;
            exit(0);
        }
        a = prev[a.first][a.second];
        ans.push_back(a);
    }
    std::reverse(ans.begin(), ans.end());
    cout << ans.size() - 1 << '\n';
    /*for (auto [f, s] : ans) {
        cout << f << " " << s << '\n';
    }*/
}