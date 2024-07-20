//
// Created by Сергей on 29.06.2024.
//
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct ld {
    string surname;
    string name;
    string clas;
    string dat_b;
    ld(string a, string b, string c, string d) {
        surname = a;
        name = b;
        clas = c;
        dat_b = d;
    }
};

bool comp(ld a, ld b) {
    char alpha1 = a.clas[a.clas.size() - 1];
    char alpha2 = b.clas[b.clas.size() - 1];
    a.clas.resize(a.clas.size() - 1);
    b.clas.resize(b.clas.size() - 1);
    if (stoi(a.clas) < stoi(b.clas)) {
        return true;
    } else if (stoi(a.clas) > stoi(b.clas)) {
        return false;
    } else if (alpha1 == alpha2) {
            return a.surname < b.surname;
    } else {
        return alpha1 < alpha2;
    }
}

int main() {
    int n;
    cin >> n;
    vector<ld> a;
    string q, w, e, r;
    for (int i = 0; i < n; ++i) {
        cin >> q >> w >> e >> r;
        a.push_back(ld(q, w, e, r));
    }
    sort(a.begin(), a.end(), comp);
    for (int i = 0; i < n; ++i) {
        cout << a[i].clas << " " << a[i].surname << " " << a[i].name << " " << a[i].dat_b << '\n';
    }
}

