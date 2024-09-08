//
// Created by Сергей on 10.08.2024.
//
#include <iostream>
#include <vector>
using namespace std;
#define MAX 100010
#define LOGMAX 18
vector<int> g[MAX];
int d[MAX], f[MAX];
int up[MAX][LOGMAX];
int timer;
int l;

void dfs (int v, int p = 0, int len = 0)
{
    int i, to;
    d[v] = timer++;

    up[v][0] = p;
    for(i = 1; i <= l; i++)
        up[v][i] = up[up[v][i-1]][i-1];

    for(i = 0; i < g[v].size(); i++)
    {
        to = g[v][i];
        if (to != p) dfs (to, v, len + 1);
    }
    f[v] = timer++;
}

int Parent(int a, int b)
{
    return (d[a] <= d[b]) && (f[a] >= f[b]);
}
int LCA (int a, int b)
{
    if (Parent(a, b)) return a;
    if (Parent(b, a)) return b;
    for (int i = l; i >= 0; i--)
        if (!Parent(up[a][i], b)) a = up[a][i];
    return up[a][0];
}
int main() {
    int n, m, a1, a2, x, y, z, v, sum = 0, l, i = 0;
    scanf("%d %d",&n,&m);
    l = 1;
    while ((1 << l) <= n)  l++;
    for(i = 1; i <= n - 1; i++)
    {
        scanf("%d",&v);
        g[v].push_back(i);
        g[i].push_back(v);
    }
    int timer = 0;
    dfs(0);
    scanf("%d %d",&a1,&a2);
    scanf("%lld %lld %lld",&x,&y,&z);
    v = sum = 0;
    for(i = 0; i < m; i++)
    {
        v = LCA((a1 + v) % n, a2);
        sum += v;
        a1 = (x * a1 + y * a2 + z) % n;
        a2 = (x * a2 + y * a1 + z) % n;
    }
    printf("%lld\n",sum);
}