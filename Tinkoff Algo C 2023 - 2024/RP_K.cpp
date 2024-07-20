//
// Created by Сергей on 05.07.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool flag = true;
void f(int n, int k, vector<int> a, vector<int> res) {
    if (k == 0 && flag) {
        cout << "Yes" << '\n' << res.size() << '\n';
        for (int re : res) {
            cout << re << " ";
        }
        flag = false;
        return;
    }
    for (int i : a) {
        if (k - i >= 0) {
            vector<int> b = a;
            b.erase(std::find(b.begin(), b.end(), i));
            vector<int> res1 = res;
            res1.push_back(i);
            f(n, k - i, b, res1);
            if (!flag) {
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a;
    vector<int> res;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        a.push_back(y);
        a.push_back(y);
        sum += y;
        sum +=y;
    }
    if (sum >= k) {
        f(n, k, a, res);
        if (flag) {
            cout << "No";
        }
    } else {
        cout << "No";
    }
}