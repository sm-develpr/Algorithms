//
// Created by Сергей on 05.08.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

/*
struct versh {
    int f, s, c;
    versh(int fe, int se, int ce) {
        f = fe;
        s = se;
        c = ce;
    }
};

void get_cycle(vector<int> from, int v) {
    vector<int> res;
    res.push_back(v);
    for (int cycleV = from[v]; cycleV != v; cycleV = from[cycleV]) {
        res.push_back(cycleV);
    }
    res.push_back(v);
    reverse(res.begin(), res.end());
    cout << "YES" << '\n';
    cout << res.size() << '\n';
    for (auto i : res) {
        cout << i << " ";
    }
    exit(0);
}

int main() {
    int n, y;
    cin >> n;
    vector<versh> g;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cin >> y;
            if (y != INF && i != j) {
                g.push_back(versh(i, j, y));
            }
        }
    }
    vector<int> from(n + 1, -1);
    vector<int> dist(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        for (auto e : g) {
            if (dist[e.s] > dist[e.f] + e.c) {
                dist[e.s] = max(-INF, dist[e.f] + e.c);
                from[e.s] = e.f;
            }
        }
    }
    for (auto e : g) {
        if (dist[e.s] > dist[e.f] + e.c) {
            from[e.s] = e.f;
            for (int i = 0; i < n - 1; ++i) {
                e.s = from[e.s];
            }
        }
        get_cycle(from, e.s);
    }
    cout << "NO";
}*/
struct edge {
    edge(ll i, ll i1, ll i2) {
        a = i;
        b = i1;
        cost = i2;
    }

    int a, b, cost;
};

ll n, m;
vector<edge> e;
const ll INF = 100000;

void solve() {
    vector<ll> d(n + 1, 0);
    vector<ll> p(n + 1, -1);
    ll x = -1;
    for (ll i = 0; i < n; ++i) {
        x = -1;
        for (ll j = 0; j < m; ++j)
            if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost);
                p[e[j].b] = e[j].a;
                x = e[j].b;
            }
    }

    if (x == -1) {
        cout << "NO";
    } else {
        ll y = x;
        for (ll i = 0; i < n; ++i)
            y = p[y];

        vector<ll> path;
        for (ll cur = y; ; cur = p[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1)  break;
        }
        reverse(path.begin(), path.end());

        cout << "YES" << '\n';
        cout << path.size() << '\n';
        for (ll i : path)
            cout << i << ' ';
    }
}
int main() {
    ll y;
    cin >> n;
    for (ll i = 1; i < n + 1; ++i) {
        for (ll j = 1; j < n + 1; ++j) {
            cin >> y;
            if (y != INF || i != j) {
                e.push_back(edge(i, j, y));
            }
        }
    }
    m = e.size();
    solve();
}
// это пиздец блять помогите нахуй, я три дня блять занимаюсь этой задачей, какая это поебота блять
// на информатиксе на последнем 21 тесте неправильный форммат вывода
// на acmp на 21 тесте ошибка выполнения
// и на ебаном тинькофе ошибка на 21 тесте с НЕПРАВИЛЬНЫМ ОТВЕТОМ СУКА!!!!

// это пищдец пойду вешаться