//
// Created by Сергей on 20.06.2024.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int counter = 0;
    int n;
    cin >> n;
    vector<int> balls(n);
    for (int i = 0; i < n; ++i) {
        cin >> balls[i];
    }
    vector<int> res(0);
    int uk = balls.size();
    int i = 0;
    if (n >= 3) {
        while (i < uk) {
            if (res.size() > 1) {
                if (balls[i] == res[res.size() - 1] && res[res.size() - 1] == res[res.size() - 2]) {
                    bool flag = true;
                    int y = balls[i];
                    res.pop_back();
                    res.pop_back();
                    counter += 2;
                    while (balls[i] == y) {
                        i++;
                        counter++;
                        flag = false;
                    }
                    if (flag) {
                        i++;
                    }
                } else {
                    res.push_back(balls[i]);
                    i++;
                }
            } else {
                res.push_back(balls[i]);
                i++;
            }
        }
        cout << counter;
    } else {
        cout << 0;
    }
}