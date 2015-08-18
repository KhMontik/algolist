/*
Simple linear function
Find n-th value of function with matrix powering O(k^3logN)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

const int N = 50;

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
               res[i][j] += (a[i][k]*b.a[k][j])%mod;
               res[i][j] %= mod;
            }
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++) a[i][j] = res[i][j];
   }
   void out (){
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++)   cout << a[i][j] << " ";
         cout << endl;
      }
      cout << endl;
   }
}a, r;
int x[N];
int main ()
{
   freopen ("rng.in", "r", stdin);
   freopen ("rng.out", "w", stdout);
  
   int n;
   cin >> n >> mod;
   for (int i = n-1; i >= 0; i--) cin >> a.a[n-1][i];
   cin >> a.a[n-1][n];
   for (int i = 0; i < n; i++) cin >> x[i];
   for (int i = 0; i < n-1; i++) a.a[i][i+1] = 1;
   a.a[n][n] = 1;
   a.n = n+1;
   for (int i = 0; i <= n; i++) r.a[i][i] = 1;
   r.n = n+1; 
   pw.in();
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
   long long ans=0;
   for (int i = 0; i < n; i++) 
      ans += (r.a[0][i]*x[i])%mod, ans %= mod;
   ans += r.a[0][n];
   ans %= mod;
   cout << ans;
   
   return 0;
}

