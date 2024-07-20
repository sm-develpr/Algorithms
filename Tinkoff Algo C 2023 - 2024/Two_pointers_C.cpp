//
// Created by Сергей on 25.03.2024.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > line_segment(n);
    vector<pair<int, int> > result;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        line_segment[i] = make_pair(a, b);
    }
    sort(line_segment.begin(), line_segment.end());
    int ptrleft = line_segment[0].first;
    int ptrright = line_segment[0].second;
    bool flag = true;
    for (int i = 1; i < n; ++i) {
        if (ptrright >= line_segment[i].first && ptrright <= line_segment[i].second) {
            ptrright = line_segment[i].second;
            flag = true;
        } else if (ptrright < line_segment[i].first) {
            result.push_back(make_pair(ptrleft, ptrright));

            ptrleft = line_segment[i].first;
            ptrright = line_segment[i].second;

            flag = true;
        } else if (ptrright > line_segment[i].second) {
            continue;
        } else {
            if (flag) {
            result.push_back(make_pair(ptrleft, ptrright));
            flag = false;
            }
        }
    }
    if (result.size() == 0) {
        result.push_back(make_pair(ptrleft, ptrright));
    } else if (result[result.size() - 1].second != ptrleft) {
        result.push_back(make_pair(ptrleft, ptrright));
    }

    cout << result.size() << "\n";
    for (pair<int, int> item : result) {
        cout << item.first << " " << item.second << "\n";
    }
}