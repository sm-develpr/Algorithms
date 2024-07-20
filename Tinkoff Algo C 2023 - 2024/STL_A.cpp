//
// Created by Сергей on 29.06.2024.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, string> > synom(n);
    for (int i = 0; i < n; ++i) {
        cin >> synom[i].first >> synom[i].second;
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (synom[i].first == s) {
            cout << synom[i].second;
            break;
        } else if (synom[i].second == s) {
            cout << synom[i].first;
        }
    }
}