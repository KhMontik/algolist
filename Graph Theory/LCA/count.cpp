/*
Problem lca, lksh A 2011, day5
How many pairs (i,j) that have common ancestor
Oriented Graph
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int N = 16005;

int n, m;
vector <int> a[N], g[N];
vector <int> b[N];
bool bad[N];
int cnt[N];
int c[N];
int top[N];
int ts;
int cc;
long long d[N];
int sz[N];
long long dd[N];
bool u[N];

void tops (int v) {
    u[v] = 1;
    for (int i = 0; i < a[v].size(); i++)
        if (!u[a[v][i]]) tops (a[v][i]);
    top[ts++] = v;
}
void dfs (int v) {
    c[v] = cc;
    cnt[cc]++;
    for (int i = 0; i < g[v].size(); i++)
        if (!c[g[v][i]]) dfs (g[v][i]);
}

long long calc(int v) {
    if (d[v] != -1) return d[v]; 
    sz[v] = cnt[v];
    d[v] = 0;
    dd[v] = 0;
    for (int i = 0; i < b[v].size(); i++) {
        int j = b[v][i];
        if (j == v) continue;
        long long x = calc(j);
        sz[v] += sz[j];
        d[v] -= d[j];//+dd[j];
       // dd[v] += d[j]+dd[j];
 //       cout << x << endl;
    }
    d[v] += sz[v]*sz[v];
    /*
    for (int  i= 0; i < b[v].size(); i++) {
        int j = b[v][i];
        if (j == v) continue;
        calc1(j,j);
    }*/
    return d[v];
}

int main()
{       
    int x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        a[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        if (!u[i]) tops(i);
    for (int i = n-1; i >= 0; i--)
        if (!c[top[i]]) cc++, dfs(top[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < a[i].size(); j++) 
            if (c[i] != c[a[i][j]]) b[c[i]].push_back(c[a[i][j]]), bad[c[a[i][j]]]= 1;
    memset(d,-1,sizeof(d));
    memset(dd,-1,sizeof(dd));
    memset(u,0,sizeof(u));
    for (int i = 1; i <= cc; i++)
        if (d[i] == -1) calc(i);
    long long res = 0;
    for (int i = 1; i <= cc; i++) res += d[i];//, cout << i << " " << d[i] << " " << sz[i] << endl;
    cout << res;
    return 0;
}
