#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

const int N = 20007;
const int M = 200007;

vector <int> a[N], id[N];
bool u[N];
int sz = 0, tin[N], fup[N];
int c = 1;
bool ok[M];
void dfs (int x, int pr = -1) {
        u[x] = 1;
        tin[x] = fup[x] = c++;
        for (int i = 0; i < a[x].size(); i++) {
                int j = a[x][i];
                if (j == pr) continue;
                if (u[j]) fup[x] = min(fup[x], tin[j]);
                else {
                        dfs (j, x);
                        fup[x] = min (fup[x], fup[j]);
                        if (tin[x] < fup[j]) ok[id[x][i]] = 1;
                }
        }
}

map < pair <int, int> , int> un;
int main ()
{
        freopen ("bridges.in", "r", stdin);
        freopen ("bridges.out", "w", stdout);

        int n, m, x, y;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
                scanf ("%d%d", &x, &y);
                x--, y--;
                a[x].push_back (y);id[x].push_back (i);
                a[y].push_back (x);id[y].push_back (i);
        }
        for (int i = 0; i < n; i++)
                if (!u[i]) dfs (i);
        for (int i = 0; i < n; i++)
                for (int j = 0; j < a[i].size(); j++)
                        un[ make_pair (min(i,a[i][j]), max(i, a[i][j]))]++;
        for (int i = 0; i < n; i++)
                for (int j = 0; j < a[i].size(); j++)
                        if (ok[id[i][j]] && un[make_pair (min(i,a[i][j]), max(i, a[i][j]))] > 2) ok[id[i][j]] = 0;
        sz = 0;
        for (int i = 0; i < m; i++)
                if (ok[i])
                        sz++;
        cout << sz << endl;
        for (int i = 0; i < m; i++)
                if (ok[i])
                printf ("%d\n", i+1);
        return 0;
}
