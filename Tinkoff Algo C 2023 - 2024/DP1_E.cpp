//
// Created by Сергей on 07.07.2024.
//
#include "iostream"
#include <vector>
using namespace std;


/*int counter = 0;

void f(bool flag, int  n) {
    if (n == 0) {
        counter++;
        return;
    }
    if (!flag) {
        f(true, n - 1);
    }
    f(false, n - 1);
    f(false, n - 1);
}

int main() {
    unsigned int start_time =  clock();
    int n;
    cin >> n;
    f(false, n);
    cout << counter << "\n";
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << search_time;
}*/

#include <iostream>
using namespace std;

int main() {
    int n, i, s = 0;
    cin >> n;
    int a[20][3];
    a[0][0] = a[0][1] = a[0][2] = 1;
    for (i = 1; i < n; i++) {
        a[i][0] = a[i-1][1] + a[i-1][2];
        a[i][2] = a[i][1] = a[i-1][0] + a[i-1][1] + a[i-1][2];
    }
    for (i = 0; i < 3; i++)
        s += a[n - 1][i];
    cout << s << '\n';
    return 0;
}