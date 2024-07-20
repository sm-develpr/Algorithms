//
// Created by Сергей on 21.06.2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> train1(n);
    vector<int> tupik;
    vector<pair<int, int> > res;
    for (int i = 0; i < n; ++i) {
        cin >> train1[i];
    }
    int num_train = 1;
    int i = -1;
    while (i < n - 1) {
        int counter = 0;
        do {
            counter++;
            i++;
            tupik.push_back(train1[i]);
        } while (train1[i] != num_train);

        res.push_back(make_pair(1, counter));
        counter = 0;
        while (!tupik.empty() && tupik[tupik.size() - 1] == num_train) {
            num_train++;
            tupik.pop_back();
            counter++;
        }
        res.push_back(make_pair(2, counter));
    }
    if (tupik.empty()) {
        cout << res.size() << "\n";
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i].first << " " << res[i].second << "\n";
        }
    } else {
        cout << 0;
    }
}