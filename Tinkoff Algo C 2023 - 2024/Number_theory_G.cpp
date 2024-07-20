//
// Created by Сергей on 19.07.2024.
//
#include <iostream>
using namespace std;
int euclidean(int n, int m) {
    while (m != 0) {
        int t = m;
        m = n % m;
        n = t;
    }
    return n;
}
int nok(int n, int m) {
    return n / euclidean(n, m) * m;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << nok(n, m);
}