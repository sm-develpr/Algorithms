//
// Created by Сергей on 29.07.2024.
//
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int AddOne(int n) {
    if (n / 1000 != 9) return n + 1000;
    return n;
}

int MinusOne(int n) {
    if (n % 10 != 1) return n - 1;
    return n;
}

int ShiftLeft(int n) {
    return (n % 1000) * 10 + n / 1000;
}

int ShiftRight(int n) {
    return (n % 10) * 1000 + n / 10;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> prev(10000);
    vector<bool> used(10000);
    deque<int> d;
    d.push_back(n);
    int (*Op[4])(int) = {AddOne, MinusOne, ShiftLeft, ShiftRight};
    used[n] = 1;
    int u;
    while (!d.empty()) {
        u = d.front();
        d.pop_front();
        if (m == u) {
            break;
        }
        for (int i = 0; i < 4; ++i) {
            int v = Op[i](u);
            if (!used[v]) {
                used[v] = 1;
                prev[v] = u;
                d.push_back(v);
            }
        }
    }
    vector<int> ans;
    while (n != u) {
        ans.push_back(u);
        u = prev[u];
    }
    ans.push_back(n);
    std::reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i << '\n';
    }
}
