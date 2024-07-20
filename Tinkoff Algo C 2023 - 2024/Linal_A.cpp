//
// Created by Сергей on 01.07.2024.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lapl(n);
    for (int i = 0; i < n; ++i) {
        cin >> lapl[i];
    }
    vector<int> res(n, -1);
    stack<int> a;
    for (int i = 0; i < n; ++i) {
        while (!a.empty() && lapl[a.top()] > lapl[i]) {
            res[a.top()] = i;
            a.pop();
        }
        a.push(i);
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
}