#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;


typedef long long ll;
const int N = 200500;

int h, q;
long long l[N], r[N];
int lvl[N], ans[N];

struct Tree{
    int l, r, c;
    bool sg;
    long long sum;
    Tree(){
        l = r = 0;
        sg = 0;
        sum = 0;
        c = 0;
    }
}t[N*52];
int sz = 2;

void push (int v, ll tl, ll tr){
    if (!t[v].sg)return;
    
    t[v].sum = (tr-tl+1)*1LL*t[v].c;

    if (tl != tr){
        if (!t[v].l) t[v].l = sz++;
        if (!t[v].r) t[v].r = sz++;
        t[t[v].l].sg = 1; t[t[v].l].c = t[v].c;
        t[t[v].r].sg = 1; t[t[v].r].c = t[v].c;
    }
    t[v].sg = 0;
}


void color (ll l, ll r, int x, int v = 1, ll tl = (1LL<<(h-1)), ll tr = (1LL<<h)-1){
    push(v,tl,tr);
    if (l <= tl && r >= tr){
        t[v].c = x;
        t[v].sg = 1;
        push(v,tl,tr);
        return;
    }
    if (l > tr || tl > r) return;
    if (!t[v].l) t[v].l = sz++;
    if (!t[v].r) t[v].r = sz++;
    ll tm = (tl+tr)>>1;
    color(l,r,x,t[v].l,tl,tm);
    color(l,r,x,t[v].r,tm+1,tr);
    t[v].sum = t[t[v].l].sum + t[t[v].r].sum;
}

ll getSum(ll l, ll r, int v = 1, ll tl = (1LL<<(h-1)), ll tr = (1LL<<h)-1){
    push(v,tl,tr);
    if (l <= tl && r >= tr)
        return t[v].sum;
    if (l > tr || tl > r) return 0;
    ll res = 0;
    ll tm = (tl+tr)>>1;
    if (t[v].l) res += getSum(l,r,t[v].l,tl,tm);
    if (t[v].r) res += getSum(l,r,t[v].r,tm+1,tr);
    return res;
}

ll getId(int v = 1, ll id = 1, ll tl = (1LL<<(h-1)), ll tr = (1LL<<h)-1){
    if (tl == tr) return id;
    ll tm = (tl+tr) >> 1;
    if (t[v].sum != 1) cout << "Bad " << v << " " << t[v].sum << endl;
    if (t[v].l && t[t[v].l].sum == 1) return getId(t[v].l,id<<1,tl,tm);
    else if(t[v].r)                             return getId(t[v].r,(id<<1) + 1,tm+1,tr);
    else return -1;
}

int main()
{
    int cc = 1;
    cin >> h >> q;
    for (int i = 0; i < q; i++){
        cin >> t;
        if (t == 1){
            cin >> l >> r;
            if (getSum(l,r) != 0)
                cout << "0\n";
            else{
                cout << "1\n";
                color(l,r,cc++);
            }
        }else{
            cin >> x;
            cout << getL(x) << " " << getR(x);
        }
    }

    return 0;
}
