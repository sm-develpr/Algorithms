//
// Created by Сергей on 01.07.2024.
//
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    stack<ll> a;
    vector<ll> left_ans(n);
    left_ans[0] = -1;
    a.push(0);
    for (int i = 1; i < n; ++i) {
        while (!a.empty() && g[i] <= a.top().first) {
            a.pop();
        }
        if (!a.empty()) {
            left_ans[i] = a.top();
        } else {
            left_ans[i] = -1;
        }
        a.push(i);
    }
    stack<ll> b;
    vector<ll> right_ans(n);
    right_ans[n - 1] = n;
    a.push(0);
    for (int i = 1; i < n; ++i) {
        while (!a.empty() && g[i] <= a.top().first) {
            a.pop();
        }
        if (!a.empty()) {
            left_ans[i] = a.top();
        } else {
            left_ans[i] = -1;
        }
        a.push(i);
    }
    // заебался уже эту хуйню писать
}