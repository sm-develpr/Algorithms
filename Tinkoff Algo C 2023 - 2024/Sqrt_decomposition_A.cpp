//
// Created by Сергей on 22.08.2024.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int max_n = 1e5 + 1;
const int c = 380;
int sqn;

struct block {
    int l, r;
    int maxim;
    int size_mas;
    vector<int> a;
    block(vector<int> b, int left, int right) {
        l = left;
        r = right;
        a = b;
        size_mas = b.size();
        maxim = b[0];
        for (size_t i = 1; i < b.size(); ++i) {
            if (maxim < b[i]) {
                maxim = b[i];
            }
        }
    }
    int max_l(int cl) {
        int maxi = a[cl];
        for (size_t i = cl; i < a.size(); ++i) {
            if (maxi < a[i]) {
                maxi = a[i];
            }
        }
        return maxi;
    }

    int max_r(int cr) {
        int maxo = a[cr];
        for (int i = 0; i < cr; ++i) {
            if (maxo < a[i]) {
                maxo = a[i];
            }
        }
        return maxo;
    }

    int maxik(int ll, int rr) {
        int maxik = a[ll];
        for (int i = ll; i < rr + 1; ++i) {
            if (maxik < a[i]) {
                maxik = a[i];
            }
        }
        return maxik;
    }
};

struct sqrt_dec {
    vector<block> sqd;
    void build(vector<int> mas) {
        int l = 0;
        bool flag = true;
        vector<int> tmp;
        for (int r = 0; r < int(mas.size()); ++r) {
            flag = true;
            tmp.push_back(mas[r]);
            if ((r + 1) % sqn == 0 && r != 0) {
                flag = false;
                sqd.push_back(block(tmp, l, r));
                tmp.clear();
                l = r + 1;
            }
        }
        if (flag) {
            sqd.push_back(block(tmp, l, mas.size() - 1));
        }
    }
    int maxim(int l, int r) {
        int cl, cr, s, e;
        l--;
        r--;
        cl = l % sqn;
        cr = r % sqn;
        s = l / sqn;
        e = r / sqn;
        if (s == e) {
            return sqd[s].maxik(cl, cr);
        }
        int res = max(sqd[s].max_l(cl), sqd[e].max_r(cr));
        for (int i = s + 1; i < e; ++i) {
            res = max(res, sqd[i].maxim);
        }
        return res;
    }
    sqrt_dec(vector<int> mas) {
        build(mas);
    }
};

int main() {
    int n, k, l, r;
    cin >> n;
    sqn = int(sqrt(n)) + 1;
    vector<int> mas(n);
    for (int i = 0; i < n; ++i) {
        cin >> mas[i];
    }
    cin >> k;
    sqrt_dec s = sqrt_dec(mas);
    while (k--) {
        cin >> l >> r;
        if (l > r) {
            swap(l, r);
        }
        cout << s.maxim(l, r) << ' ';
    }
}