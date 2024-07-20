//
// Created by Сергей on 30.06.2024.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <algorithm>
#include <cassert>
using namespace std;

struct abit {
    string name;
    string surname;
    int num_bith;
    int month_bith;
    int year_bith;
    int rating;
    int count_univers;
    vector<string> university;
    abit(string n, string nm, int a, int b, int c, int d, int e, vector<string> t) {
        name = n;
        surname = nm;
        num_bith = a;
        month_bith = b;
        year_bith = c;
        rating = d;
        count_univers = e;
        university = t;
    }
};

bool comp(abit a, abit b) {
    if (a.rating != b.rating) {
        return a.rating > b.rating;
    }
    if (a.year_bith != b.year_bith) {
        return a.year_bith < b.year_bith;
    }
    if (a.month_bith != b.month_bith) {
        return a.month_bith < b.month_bith;
    }
    if (a.num_bith != b.num_bith) {
        return a.num_bith < b.num_bith;
    }
    return a.surname < b.surname || (a.surname == b.surname && a.name < b.name);
}
int main() {
    int n;
    cin >> n;
    map<string, int> uni;
    string y;
    for (int i = 0; i < n; ++i) {
        cin >> y;
        cin >> uni[y];
    }
    int k;
    cin >> k;
    vector<abit> a;
    string name, surname;
    int num_bith, month_bith, year_bith, rating, count_univers;
    for (int i = 0; i < k; ++i) {
        cin >> name >> surname >> num_bith >> month_bith >> year_bith >> rating >> count_univers;
        vector<string> l(count_univers);
        for (int j = 0; j < count_univers; ++j) {
            cin >> l[j];
        }
        a.push_back(abit(name, surname, num_bith, month_bith, year_bith, rating, count_univers, l));
    }
    map<string, vector<string>> result;
    for (auto i = uni.begin(); i != uni.end(); ++i) {
        result[i->first].push_back("");
    }

    sort(a.begin(), a.end(), comp);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].count_univers; ++j) {
            if (uni[a[i].university[j]] != 0) {
                result[a[i].university[j]].push_back(a[i].name + " " + a[i].surname);
                uni[a[i].university[j]]--;
                break;
            }
        }
    }

    for (auto i = result.begin(); i != result.end(); ++i) {
        cout << i->first << "    ";
        for (int j = 0; j < i->second.size(); ++j) {
            cout << i->second[j] << '\t';
        }
        cout << '\n';
    }
}

// Добавить сортировку в конце