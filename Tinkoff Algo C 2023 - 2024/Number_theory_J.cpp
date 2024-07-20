#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 2;
    int k = 0;
    if (n %i) {
        int j = 3;
        while (j*j < n + 1) {
            if (!(n % j)) {
                k = 1;
                i = j;
                break;
            }
            j += 2;
        }
    } else {
        k = 1;
    }
    if (k) {
        cout << (i - 1) * (n / i) << " " << n / i;
    } else {
        cout << 1 << " " << n - 1;
    }
}

