/*
RMQ offline O(N+M)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;
const int N = 25007;
const int M = 2000000;
unsigned int A, B;
int p[N], r[N], g[N];
unsigned int a[N];
int st[N];
int he[M], nx[M];
unsigned int key[M];
unsigned int get (int i) {
   unsigned int res;
   res = (unsigned int)(i+1)*A+B;
   if (i >= n) res %= n;
   return res;
}
int fs (int x) {
   if (x != p[x]) p[x] = fs (p[x]);
   return p[x];
}
void un (int x, int y, int z) {
   if (r[x] > r[y]) p[y] = x, g[x] = z;
   else             p[x] = y, g[y] = z;
   if (r[x] == r[y]) r[y]++;
}
int main ()
{
   freopen ("rmq.in", "r", stdin);
   freopen ("rmq.out", "w", stdout);
   unsigned long long res = 0;
   while (cin >> n >> m >> A >> B) {
       int ff = 0;
       if (n == 0) break;
       res = 0;
       int sz = 0;
       for (int i = 0; i < n; i++)  a[i] = get(i), p[i] = i, r[i] = 0, g[i] = i, he[i] = -1;
       for (int i = n; i < n+m+m; i+=2) {
            int mn = min (get(i+1), get(i));
            int mx = max (get(i), get(i+1));
            nx[ff] = he[mx], key[ff] = mn, he[mx] = ff++;
            //cout << get(i) << " " << get(i+1) << endl;
       }   
       for (int i = 0; i < n; i++) {
         while (sz > 0 && a[st[sz-1]] > a[i]) sz--, un(fs(st[sz]), fs(i), i);
         st[sz++] = i;
         for (int j = he[i]; j != -1; j = nx[j]) {
            res += a[g[fs(key[j])]];
   //         printf ("l = %d, r = %d, ans = %u\n", q[i][j]+1, i+1, a[g[fs(q[i][j])]]);
         }           
       }  
       cout << res << "\n";     
   }
   return 0;
}

