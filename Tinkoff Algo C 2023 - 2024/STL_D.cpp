#include <iostream>
#include <set>

using namespace std;

int main() {
    int n1, cur;
    cin >> n1;
    set<int> s1;
    for (int i = 0; i < n1; i++) {
        cin >> cur;
        s1.insert(cur);
    }
    int n2;
    cin >> n2;
    set<int> s2;
    for (int i = 0; i < n2; i++) {
        cin >> cur;
        s2.insert(cur);
    }
    set<int> out;
    for (set<int>::iterator it = s1.begin(); it != s1.end(); ++it) {
        if (s2.find(*it) == s2.end()) {
            out.insert(*it);
        }
    }
    for (set<int>::iterator it = s2.begin(); it != s2.end(); ++it) {
        if (s1.find(*it) == s1.end()) {
            out.insert(*it);
        }
    }
    cout << out.size() << endl;
    for (set<int>::iterator it = out.begin(); it != out.end(); ++it) {
        cout << *it << " ";
    }
}