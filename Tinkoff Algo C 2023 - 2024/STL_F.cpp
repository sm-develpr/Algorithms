//
// Created by Сергей on 29.06.2024.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct kavaler{
    string name;
    int high;
    int weight;
    kavaler(string a, int b, int c){
        name = a;
        high = b;
        weight = c;
    }
};

bool comp(kavaler a, kavaler b) {
    if (fabs(180 - a.high) > fabs(180 - b.high)) {
        return false;
    } else if (fabs(180 - a.high) < fabs(180 - b.high)) {
        return true;
    } else {
        if (a.weight > 75 && b.weight <= 75) {
            return false;
        } else if (b.weight > 75 && a.weight <= 75) {
            return true;
        } else {
            if (fabs(75 - a.weight) < fabs(75 - b.weight)) {
                return true;
            } else if (fabs(75 - a.weight) > fabs(75 - b.weight)) {
                return false;
            } else {
                return a.name < b.name;
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<kavaler> a;
    string name;
    int h, w;
    for (int i = 0; i < n; ++i) {
        cin >> name >> h >> w;
        a.push_back(kavaler(name, h, w));
    }
    sort(a.begin(), a. end(), comp);
    for (int i = 0; i < n; ++i) {
        cout << a[i].name << '\n';
    }
}