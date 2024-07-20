//
// Created by Сергей on 24.03.2024.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a;
    cin >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b) {
        cout << "YES";
    } else {
        cout << "NO";
    }

}