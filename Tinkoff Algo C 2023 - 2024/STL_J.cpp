//
// Created by Сергей on 30.06.2024.
//
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, set<string> >a;
    for (int i = 0; i < n; ++i) {
        string s;
        int k;
        cin >> s >> k;
        a[k].insert(s);
    }
    for (auto i = a.begin(); i != a.end(); ++i) {
        cout << i->first << " ";
        for (auto j = i->second.begin(); j != i->second.end(); ++j) {
            cout << *j << " ";
        }
        cout << '\n';
    }
}