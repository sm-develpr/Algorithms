#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
using namespace std;

int main() {
    while (true) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string s;
        getline(cin, s);
        int couutm = 0;
        string num = "";
        bool flag = false;
        for (size_t i = 0; i < s.size(); ++i) {
            while (s[i] != ' ' && i != s.size()) {
                num += s[i];
                i++;
                flag = true;
            }
            if (flag) {i--;}
            if (!num.empty()) {couutm += stoi(num);}

            flag = false;

            num = "";
        }
        cout << couutm << " ";

    }
}