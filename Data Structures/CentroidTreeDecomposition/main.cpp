#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

const int N = 1<<17;
const int K = 17;

int n, m;
vector <int> a[N];


//CTD
bool marked[N], u[N][K];
int was[N], ws;
int d[N];


void dfs (int x){
    for (int i = 0; i < a[x].size(); i++) 
        if (d[a[x][i]] < 0) d[a[x][i]] = d[x] + 1, dfs (d[a[x][i]]);
}

int centroid(int layer) {
    int x = -1;
    for (int i = 0; i < n; i++){
        if (!u[i][layer] && !marked[i]) x = i;
        d[i] = -N;
    }
    assert(x != -1);
    d[x] = 0;
    dfs (x);
    x = -1;
    for (int i = 0; i < n; i++){
        if (x == -1 || d[i] > d[x]) x = i;
        d[i] = -N;
    }
    dfs (x);
    x = -1;
    for (int i = 0; i < n; i++)
        if (x == -1 || d[i] > d[x]) x = i;
    return x;
}
void calc (int v, int layer) {
    u[v][layer] = 1;
}

void build (int layer){
    for (int i = 0; i < n; i++) {
        if (!u[i][layer] && !marked[i]) {
            int cntr = centroid();
            calc (cntr,layer);
            marked[cntr] = 1;
            build(layer+1);
            marked[cntr] = 0;
        }
    }
}

int main()
{
    int x, y, z;
    scanf ("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf ("%d%d", &x, &y); x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    build (0);
    return 0;
}
