//
// Created by Сергей on 06.07.2024.
//
#include <iostream>
using namespace std;
/*
int N = 0;

void f(int counter, int n) {
    if (n == 0) {
        N++;
        return;
    }
    if (counter == 2) {
        f(0, n-1);
    } else {
        f(0, n-1);
        f(counter+1, n-1);
    }
}
int main() {
    int n;
    cin >> n;
    f(0, n);
    cout << N;
}
// 001 010 100 110 011 101 0002

*/
int main() {
    int n;
    cin >> n;
    n--;
    if (n + 1 == 1) {
        cout << 2;
    } else {
    int dp[41][4];
    dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][2] + dp[i - 1][1];
        dp[i][2] = dp[i - 1][1] + dp[i - 1][3];
        dp[i][3] = dp[i - 1][1];
    }
    int s = 0;
    for (int i = 0; i < 4; ++i) {
        s += dp[n - 1][i];
    }
    cout << s;
}
}
