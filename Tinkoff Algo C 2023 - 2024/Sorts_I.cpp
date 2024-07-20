//
// Created by Сергей on 24.03.2024.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<char, int> a;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        a[s[i]]++;
    }
    char j ='[';
    for (auto item : a) {
        if (item.second % 2 != 0) {
            if (j > item.first) {
                j = item.first;
            }
            item.second--;
        }
    }
    string result;
        for (auto item : a) {
            for (int i = 0; i < item.second / 2; ++i) {
                result+=item.first;
            }
        }

        string result2;
        result2 = result;
        sort(result2.rbegin(), result2.rend());
        if (j != '[') {
            result += j;
        }
        result += result2;
        cout << result;
}