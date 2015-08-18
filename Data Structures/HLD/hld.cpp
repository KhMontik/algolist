/*
Heavy-light decomposition
Problem #1553 at acm.timus.ru
    I V X -> Update vertex V's value to X
    G U V -> Maximal value on path between U and V
Madi Khamitbekov
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1<<17;

int n;
vector <int> a[N];

// LCA
int up[N][19];
int lvl[N];

//DFS
bool u[N];
int tin[N], tout[N];
int timer;

//HLD
int sz[N];
int heavy[N];
int path[N];
int id[N];
vector <int> p[N];
int ps = 0;
int L[N], R[N];

//Interval Tree
int mx[N+N];

void upd (int v, int x) {
    #ifdef debug
    printf ("updated(%d) += %d\n", v+1,x);
    #endif

    v += N;
    mx[v] += x; v>>=1;
    while (v) {
        mx[v] = max(mx[v+v],mx[v+v+1]);
        v >>= 1;
    }
}
int get (int l, int r) {
    if (l > r) swap(l,r);
    #ifdef debug
    printf ("[%d;%d] ",l+1,r+1);
    #endif
    
    l += N;
    r += N;
    int ret = 0;
    while (l <= r) {
        if (l%2==1) ret = max (ret, mx[l]), l++;
        if (r%2==0) ret = max (ret, mx[r]), r--;
        l >>= 1;
        r >>= 1;
    }
    #ifdef debug
    printf ("=%d\n", ret);
    #endif

    return ret;
}

void dfs (int x, int pr = -1, int lv = 0) {
    if (pr != -1) {
        up[x][0] = pr;
        for (int i = 1; i < 18; i++)
            up[x][i] = up[up[x][i-1]][i-1];
    }
    sz[x] = 1;
    tin[x] = timer++;
    u[x] = 1;
    lvl[x] = lv;
    for (int i = 0; i < a[x].size(); i++) {
        int j = a[x][i];
        if (!u[j]) {
            dfs(j,x,lv+1);
            sz[x] += sz[j];
        }
    }
    tout[x] = timer++;
}
void hld (int x) {
    u[x] = 1;
    bool end = 1;
    for (int i = 0; i < a[x].size(); i++) {
        int j = a[x][i];
        if (!u[j]){ 
            hld(j);
            if (sz[j]+sz[j] >= sz[x]) {
                end = 0;
                path[x] = path[j];
                id[x] = p[path[x]].size();
                p[path[x]].push_back(x);
            }
        }
    }
    if (end) {
        path[x] = ps;
        p[ps].push_back(x);
        id[x] = 0;
        ps++;
    }
}

bool upper(int a, int b) {
    return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int lca (int a, int b) {
    if (lvl[a] < lvl[b]) swap(a,b);
    for (int i = 17; i >= 0; i--)
        if (lvl[up[a][i]] >= lvl[b]) a = up[a][i];
    if (a == b) return a;
    for (int i = 17; i >= 0; i--)
        if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
    return up[a][0];
}


void update (int v, int x) {
    upd(L[path[v]]+id[v],x);
}

int ans (int x, int y) {
    //printf ("ans(%d;%d) = ", x+1,y+1);
    int v = lca(x,y);
    int ret = 0;
    //printf ("ans(%d;%d) and ans(%d;%d)\n", x+1,v+1,y+1,v+1);

    while (path[x] != path[v]) ret = max(ret, get(id[x]+L[path[x]],R[path[x]])), x = up[p[path[x]].back()][0];
    ret = max (ret, get(id[x]+L[path[x]], id[v]+L[path[v]]));
    while (path[y] != path[v]) ret = max(ret, get(id[y]+L[path[y]],R[path[y]])), y = up[p[path[y]].back()][0];
    ret = max (ret, get(id[y]+L[path[y]], id[v]+L[path[v]]));
    return ret;
}

int main()
{
    int x, y;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y; x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(0);
    memset(u,0,sizeof(u));
    memset(heavy,-1,sizeof(heavy));
    hld(0);
    
    R[0] = p[0].size()-1;
    for (int i = 1; i < ps; i++) L[i] = R[i-1] + 1, R[i] = L[i]+p[i].size()-1;
    /*
    for (int i = 0; i < ps; i++) {
        printf ("Path %d: \n", i+1);
        printf ("Segment [%d;%d] in interval Tree\n", L[i], R[i]);
        printf ("verteces: ");
        for (int j = 0; j < p[i].size(); j++)   printf ("%d ", p[i][j]+1);
        puts("");
    }
    for (int i = 0; i < n; i++) {
        printf ("Vertex %d:\n", i+1);
        printf ("In path # %d, id=%d\n", path[i], id[i]);
        printf ("Pos in RMQ %d\n", L[path[i]]+id[i]);
        puts("");
    }
*/
    char ch;
    int q;
    cin >> q;
    while (q--) {
        cin >> ch >> x >> y; 
        if (ch == 'I') update(x-1,y);
        else           cout << ans(x-1,y-1) << endl;
    }
    return 0;
}
