
//
// Created by Сергей on 18.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;
vector<int> sz;
vector<int> pred;
vector<int> clz;
vector<int> table;
/*
void make_set(int a) {
    sz[a] = 1;
    pred[a] = a;
    if (a + 1 < int(table.size()) && table[a + 1] == 0) {
        clz[a] = a + 1;
    } else if (a + 1 >= int(table.size())) {
        if (table[1] == 0) {
            clz[a] = 1;
        } else {
            clz[a] = clz[1];
        }
    } else if (a + 1 < int(table.size()) && table[a + 1] == 1) {
        clz[a] = clz[a + 1];
    }
}

int get(int a) {
    return (a == pred[a]) ? a : pred[a] = get(pred[a]);
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) {
        return;
    }
    if (sz[a] < sz[b]) {
        sz[b] += sz[a];
        pred[a] = b;
        if (table[clz[a]] == 1) {
            clz[b] = clz[b];
            clz[a] = 0;
        } else if (table[clz[b]] == 1) {
            clz[b] = clz[a];
            clz[a] = 0;
        } else {
            clz[b] = max(clz[a], clz[b]);
            clz[a] = 0;
        }
    } else {
        sz[a] += sz[b];
        pred[b] = a;
        if (table[clz[a]] == 1) {
            clz[a] = clz[b];
        } else if (table[clz[b]] == 1) {
            clz[a] = clz[a];
        } else {
            clz[a] = max(clz[a], clz[b]);
        }
        clz[b] = 0;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, pos;
    cin >> n;
    sz.resize(n + 1, 0);
    pred.resize(n + 1, 0);
    clz.resize(n + 1);
    table.resize(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> pos;
        if (table[pos] == 0) {
            cout << pos << " ";
            make_set(pos);
            table[pos] = 1;
            if (pos > 0 && table[pos - 1] == 1) {
                unite(pos - 1, pos);
            }
            if (pos + 1 < int(table.size()) && table[pos + 1] == 1) {
                unite(pos + 1, pos);
            }
        } else if (table[pos] == 1) {
            int l = clz[get(pos)];
            if (table[l] == 1) {
                while (table[l] != 0) {
                    l = clz[get(l)];
                }
            }
            table[l] = 1;
            make_set(l);
            if (l > 0 && table[l - 1] == 1) {
                unite(l - 1, l);
            }
            if (l + 1 < int(table.size()) && table[l + 1] == 1) {
                unite(l + 1, l);
            }
            cout << l << " ";
        }
    }
}*/

#define ll int
using namespace std;
vector<ll> p, r, mx;

ll get(ll x) {
    ll k = x;
    while (p[x] != x) {
        x = p[x];
    }
    while (p[k] != k) {
        k = p[k];
        p[k] = x;
    }
    return x;
}

void join(ll x, ll y) {
    x = get(x), y = get(y);
    if (r[x] < r[y]) {
        swap(x, y);
    }
    p[y] = x;
    if (r[x] == r[y]) {
        r[x] += 1;
    }
    mx[x] = max(mx[x], mx[y]);
}

int main() {
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        p.push_back(i);
        mx.push_back(i);
        r.push_back(0);
    }
    vector<ll> used(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        a -= 1;
        ll pos;
        if (used[a] == 0) {
            pos = a;
        } else if (mx[get(a)] < n - 1) {
            pos = mx[get(a)] + 1;
        } else if (used[0] == 0) {
            pos = 0;
        } else {
            pos = mx[get(0)] + 1;
        }
        cout << pos + 1 << ' ';
        used[pos] = 1;
        if (pos - 1 >= 0 && used[pos - 1] == 1) {
            join(pos, pos - 1);
        }
        if (pos + 1 < n && used[pos + 1] == 1) {
            join(pos, pos + 1);
        }
    }
}