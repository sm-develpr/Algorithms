//
// Created by Сергей on 21.06.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int q;
    vector<long long> value;
    vector<long long> min;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        long long a;
        cin >> a;
        if (a == 1) {
            cin >> a;
            value.push_back(a);
            while (min.size() > 0 && min[min.size() - 1] > a) {
                min.pop_back();
            }
            min.push_back(a);
        } else if (a == 2) {
            cout << value[0] << " ";
            if (min[0] == value[0]) {
                min.erase(min.begin());
            }
            value.erase(value.begin());

        } else if (a == 3) {
            cin >> a;
            cout << value[a - 1] << " ";
        } else if (a == 4) {
            cout << min[0] << " ";
        }
    }
}