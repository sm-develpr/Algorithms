//
// Created by Сергей on 27.03.2024.
//
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stack<char> a;
        for (size_t i = 0; i < s.size(); ++i) {
            if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {
                a.push(s[i]);
            } else {
                if (a.empty()) {
                    a.push('1');
                    break;
                }
                if (((s[i] == ']') && (a.top() == '[')) || ((s[i] == '}') && (a.top() == '{')) || ((s[i] == ')') && (a.top() == '('))) {
                    a.pop();
                } else {
                    break;
                }
            }
        }
        if (a.empty()) {
            cout << "yes";
        } else {
            cout << "no";
        }
}

