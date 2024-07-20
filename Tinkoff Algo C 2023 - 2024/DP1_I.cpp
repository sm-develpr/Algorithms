/*
//
// Created by Сергей on 12.07.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int counte = 0;
int r = 0;

void f(int prev, int n) {
    if (n == 0) {
        counte++;
    }
    for (int i = 1; i < prev; ++i) {
        if (n - i < 0) {
            break;
        }
        if (n <= (((i + 1) * i / 2))) {
            r++;
            f(i, n - i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    f(n + 1, n);
    cout << counte;
    cout << r;
}*/
#include <iostream>
#include <vector>
using namespace std;

int main() {

}