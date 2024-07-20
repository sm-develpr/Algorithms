//
// Created by Сергей on 06.07.2024.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool flag = true;

void f(int counter, int n, vector<int> res) {
    if (n == 0 && flag && counter == 0) {
        for (int i : res) {
            cout << i << " ";
        }
        flag = false;
        return;
    } else if (n < 0) {
        return;
    } else if (!flag) {
        return;
    }
    for (int i = 0; i < int(sqrt(n)) + 1; ++i) {
        if (counter != 0) {
        vector<int> res1 = res;
        res1.push_back(i);
        f(counter - 1, n - i * i, res1);}
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> res;
    f(4, n, res);
}
