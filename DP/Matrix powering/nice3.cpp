/*
problem nice3
Powering Matrix of edges between profiles
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

const int N = 50;
#define one(x,i) (((x)&(1<<(i))) != 0)
struct Long {
   int a[300], n;
   void in () {
      string s;
      cin >> s;
      n = 0;
      for (int i = s.length()-1; i >= 0; i--) a[n++] = int(s[i]-'0');
   }
   void cl () {
      while (a[n-1] == 0 && n > 1) n--;
   }
   void operator -= (const int &x) {
      int r = x;
      for (int i = 0; i < n; i++) {
         a[i] = a[i] - r;
         r = 0;
         while (a[i] < 0) a[i] += 10, r++;
      }
      cl();
   }
   void operator /= (const int &x) {
      int r = 0, y;
      for (int i = n-1; i >= 0; i--) {
         y = (r*10+a[i]);
         a[i] = y/x;
         r = y%x;
      }
      cl();
   }
   void out () {
      cl();
      for (int i = n-1; i >= 0; i--)   cout << a[i];
      cout << endl;
   }
}pw;


int mod;
int res[N][N];
struct matrix {
   int a[N][N];
   int n;
   void operator *= (const matrix &b) {
      memset (res,0,sizeof(res));
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
               res[i][j] += ((a[i][k]%mod)*(b.a[k][j]%mod))%mod;
               res[i][j] %= mod;
            }
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++) a[i][j] = res[i][j];
   }
   void ones () {
      memset (a,0,sizeof(a));
      for (int i = 0; i < n; i++) a[i][i] = 1;
   }
   void out (){
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++)   cout << a[i][j] << " ";
         cout << endl;
      }
      cout << endl;
   }
}a, r;

int main ()
{
   freopen ("nice3.in", "r", stdin);
   freopen ("nice3.out", "w", stdout);
   
   int m;
   pw.in(), cin >> m >> mod;
   int mm = 1<<m;  
   a.n = mm; 
   for (int i = 0; i < mm; i++)   
      for (int j = 0; j < mm; j++) {
         bool ok = 1;
         for (int k = 1; k < m; k++) {
            int ww = one(i,k)+one(i,k-1)+one(j,k)+one(j,k-1);
            if (ww%4 == 0) {ok = 0;break;}
         }
         if (ok) a.a[i][j] = 1;
      }
   r.n = mm;
   r.ones();
   pw -= 1;
   while (pw.n > 1 || pw.a[0] > 0) {
      if (pw.a[0]&1) {
         pw -= 1;
         r *= a;
      }else {
         pw /= 2;
         a *= a;
      }
   } 
   long long ans = 0;
   for (int i = 0; i < mm; i++)
      for (int j = 0; j < mm; j++) 
         ans += r.a[i][j], ans %= mod;
   cout << ans;
   return 0;
}

