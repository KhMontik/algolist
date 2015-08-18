#include <iostream>
#include <cstdio>

using namespace std;

const int N = 50000;
const int maxs = 32401;
const int lunch = 4*3600;
const int start = 5*3600;
int n;
int d[N];
int s[N], t[N];
int T[N];
int main ()
{;
   freopen ("buratino.in", "r", stdin);
   freopen ("buratino.out", "w", stdout);
   int h,m,ss,tt;
   scanf ("%d\n", &n);
   for (int i = 0; i < maxs; i++) t[i] = N;
   for (int i = 0; i < n; i++) {
      scanf ("%d:%d:%d %d", &h,&m,&ss, &tt); h -= 9;
      s[i] = 3600*h+60*m+ss;
      t[s[i]] = tt;
      T[s[i]] = tt;
   }
   
   for (int i = 0; i < maxs; i++) {
      if (T[i]) t[i] = T[i];
      if (i+t[i] < maxs && (i < lunch && i+t[i] <= lunch) || ( i >= start && i+t[i] >= start)){
          d[i+t[i]] = max(d[i+t[i]], d[i] + 1), t[i+t[i]] = t[i];
      } 
      d[i+1] = max(d[i+1], d[i]), t[i+1] = t[i];
   }
   cout << d[maxs-1];   
   return 0;
}

