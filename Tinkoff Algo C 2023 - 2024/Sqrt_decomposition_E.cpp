//
// Created by Сергей on 22.08.2024.
//
#include <iostream>
#include <vector>
#include <cmath>
int sqn;
using namespace std;

struct block {
    int cz = 0;
    vector<int> num;
    int l, r;
    block(vector<int> &a, int le, int ri) {
        num = a;
        l = le;
        r = ri;
        for (size_t i = 0; i < a.size(); ++i) {
            if (num[i] == 0) {
                cz++;
            }
        }
    }
    int lz(int k) {
        int count = 0;
        for (size_t i = k; i < num.size(); ++i) {
            if (num[i] == 0) {
                count++;
            }
        }
        return count;
    }
    int rz(int k) {
        int count = 0;
        for (size_t i = 0; i < k + 1; ++i) {
            if (num[i] == 0) {
                count++;
            }
        }
        return count;
    }
    int sz(int le, int ri) {
        int coutn = 0;
        for (int i = le; i < ri + 1; ++i) {
            if (num[i] == 0) {
                coutn++;
            }
        }
        return coutn;
    }
};

struct sqrtdec {
    vector<block> sqd;
    sqrtdec(vector<int>& num) {
        bool flag = true;
        vector<int> tmp;
        int l = 0;
        for (int k = 0; k < int(num.size()); ++k) {
            flag = true;
            tmp.push_back(num[k]);
            if ((k + 1) % sqn == 0 && k != 0) {
                sqd.push_back(block(tmp, l, k));
                tmp.clear();
                flag = false;
                l = k + 1;
            }
        }
        if (flag) {
            sqd.push_back(block(tmp, l, num.size() - 1));
        }
    }
    int count_z(int l, int r) {
        int res = 0;
        l--;
        r--;
        int cl = l % sqn;
        int cr = r % sqn;
        int st = l / sqn;
        int en = r / sqn;
        if (st == en) {
            return sqd[st].sz(cl, cr);
        }
        res += sqd[st].lz(cl);
        res += sqd[en].rz(cr);
        for (int i = st + 1; i < en; ++i) {
            res += sqd[i].cz;
        }
        return res;
    }
};

int main() {
    int n, m, f, s;
    cin >> n;
    sqn = int(sqrt(n)) + 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sqrtdec r = sqrtdec(a);
    cin >> m;
    while (m--) {
        cin >> f >> s;
        cout << r.count_z(f, s) << " ";
    }
}
