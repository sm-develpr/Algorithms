//
// Created by Сергей on 02.04.2024.
//
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
    string a;
    getline(cin, a);
    vector<int> A(a.size());
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '+') {
            int y = A.back();
            A.pop_back();
            y += A.back();
            A.pop_back();
            A.push_back(y);
        }
        if (a[i] == '-') {
            int y = A.back();
            A.pop_back();
            int x = A.back();
            A.pop_back();
            A.push_back(x - y);
        }
        if (a[i] == '*') {
            int y = A.back();
            A.pop_back();
            y *= A.back();
            A.pop_back();
            A.push_back(y);
        }
        if (a[i] == '/') {
            int y = A.back();
            A.pop_back();
            int x = A.back();
            A.pop_back();
            A.push_back(x / y);
        } else if (isdigit(a[i])) {
            A.push_back(a[i] - '0');
        }
    }
    cout << A.back();
}