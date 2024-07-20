//
// Created by Сергей on 25.03.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minfunc(int a, int b, int c, int d) {
    int ans = 1e9;
    if (a < ans) {
        ans = a;
    }
    if (b < ans) {
        ans = b;
    }
    if (c < ans) {
        ans = c;
    }
    if (d < ans) {
        ans = d;
    }
    return ans;
}

int maxfunc(int a, int b, int c, int d) {
    int ans = 0;
    if (a > ans) {
        ans = a;
    }
    if (b > ans) {
        ans = b;
    }
    if (c > ans) {
        ans = c;
    }
    if (d > ans) {
        ans = d;
    }
    return ans;
}

int main() {
    int a, b, c, d;
    cin >> a;
    vector<int> A(a);
    for (int i = 0; i < a; ++i) {
        cin >> A[i];
    }
    cin >> b;
    vector<int> B(b);
    for (int i = 0; i < b; ++i) {
        cin >> B[i];
    }
    cin >> c;
    vector<int> C(c);
    for (int i = 0; i < c; ++i) {
        cin >> C[i];
    }
    cin >> d;
    vector<int> D(d);
    for (int i = 0; i < d; ++i) {
        cin >> D[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());
    int maxr = 1000000000;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    int Aptr = 0, Bptr = 0, Cptr = 0, Dptr = 0;
    while (Aptr < a && Bptr < b && Cptr < c && Dptr < d) {
        int min_ptr = minfunc(A[Aptr], B[Bptr], C[Cptr], D[Dptr]);
        int max_ptr = maxfunc(A[Aptr], B[Bptr], C[Cptr], D[Dptr]);
        int dif = max_ptr - min_ptr;
        if (dif < maxr) {
            maxr = dif;
            a1 = A[Aptr];
            a2 = B[Bptr];
            a3 = C[Cptr];
            a4 = D[Dptr];
        }
        while (Aptr < a && min_ptr == A[Aptr]) {
            Aptr++;
        }
        while (Bptr < b && min_ptr == B[Bptr]) {
            Bptr++;
        }
        while (Cptr < c && min_ptr == C[Cptr]) {
            Cptr++;
        }
        while (Dptr < d && min_ptr == D[Dptr]) {
            Dptr++;
        }
    }
    cout << a1 << " " << a2 << " " << a3 << " " << a4;
}
