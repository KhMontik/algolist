#include <iostream>
#include <cstdio>

using namespace std;

const int nn = 1024;
typedef long long ll;


struct node {
        ll sum;
        int add;
}t[nn*nn*10];

void push (int v, int sz) {
        t[v].sum += t[v].add*1LL*sz;
        if (v < nn*nn) {
                t[4*v].add += t[v].add;
                t[4*v+1].add += t[v].add;
                t[4*v+2].add += t[v].add;
                t[4*v+3].add += t[v].add;
        }
        t[v].add = 0;
}
void upd (int l, int u, int r, int d, int add, int v = 1, int tl = 0, int tr = nn-1, int tu = 0, int td = nn-1) {
        push(v,(tr-tl+1)*(td-tu+1));
        if (l > r || u > d || l > tr || tl > r || u > td || tu > d) return;
        if (tl >= l && r >= tr && tu >= u && d >= td) {
                t[v].add += add;
                push(v,(tr-tl+1)*(td-tu+1));
                return;
        }
        int tm = (tl+tr) >> 1;
        int tmm = (tu+td) >> 1;
        upd (l,u,r,d,add,4*v,  tl,tm,tu,tmm);
        upd (l,u,r,d,add,4*v+1,tl,tm,tmm+1,td);
        upd (l,u,r,d,add,4*v+2,tm+1,tr,tu,tmm);
        upd (l,u,r,d,add,4*v+3,tm+1,tr,tmm+1,td);
        t[v].sum = t[4*v].sum+t[4*v+1].sum+t[4*v+2].sum+t[4*v+3].sum;
}
/*
-----
|1|3|
-----
|2|4|
-----
*/

ll get (int l, int u, int r, int d, int v = 1, int tl = 0, int tr = nn-1, int tu = 0, int td = nn-1) {
        push(v,(tr-tl+1)*(td-tu+1));
        if (l > tr || tl > r || u > td || tu > d) return 0;
        if (tl >= l && r >= tr && tu >= u && d >= td) return t[v].sum;
        int tm = (tl+tr) >> 1;
        int tmm = (tu+td) >> 1;
        return get (l,u,r,d,4*v,  tl,tm,tu,tmm)
              +get (l,u,r,d,4*v+1,tl,tm,tmm+1,td)
              +get (l,u,r,d,4*v+2,tm+1,tr,tu,tmm)
              +get (l,u,r,d,4*v+3,tm+1,tr,tmm+1,td);

}

int type, x, y, x1, y1, n, m, k, w;
void out () {
        for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++)
                        cout << get(i,j,i,j) << " ";
                cout << endl;
        }
        cout << "*****\n";
}
int main ()
{
        freopen ("segtree2d.in", "r", stdin);
        freopen ("segtree2d.out", "w", stdout);

        cin >> n >> m;
        cin >> k;

        for (int i = 0; i < k; i++) {
                scanf ("%d", &type);
                if (type == 1) scanf ("%d%d%d%d%d", &x, &y, &x1, &y1, &w), upd (x-1,y-1,x1-1,y1-1,w);
                else               scanf ("%d%d%d%d", &x, &y, &x1, &y1), printf ("%lld\n", get(x-1,y-1,x1-1,y1-1));
//                out();
        }
        return 0;
}
