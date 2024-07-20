//
// Created by Сергей on 25.03.2024.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(const string& a, const string& b) {
    return a + b > b + a;
}
int main() {
    string n;
    vector<string> a;
    while (cin >> n) {
        a.push_back(n);
    }

    sort(a.begin(), a.end(), compare);
    string result;
    for (size_t i = 0; i < a.size(); ++i) {
        result += a[i];
    }
    cout << result;
}