#include <iostream>
#include <set>
#include <cstdio>
#include <utility>
#include <string.h>

using namespace std;

const int N = 100500;

int main ()
{
   freopen ("palindr.in", "r", stdin);
   freopen ("palindr.out", "w", stdout);
   
   string s;
   char s1[2*N];
   cin >> s;
   long long res = 0;
   int d[N];
   int n = s.length();
   int l = 0, r = -1;
   int c = 0;
   
   for (int i = 0; i < n; i++) {
      if (i > r)d[i] = 0;
      else d[i] = min(d[l+r-i], r-i)+1;
      while (i+d[i] < n && i-d[i] >= 0 && s[i+d[i]] == s[i-d[i]]) d[i]++;
      if (d[i])d[i]--;
      if (i+d[i] > r) l = i-d[i], r = i+d[i];
      res += d[i];
   }
   l = 0, r = -1;
   for (int i = 0; i < n; i++) {
      if (i > r)  d[i] = 0;
      else        d[i] = min(d[l+r-i+1], r-i+1)+1;
      while (i+d[i]-1 < n && i-d[i] >= 0 && s[i+d[i]-1] == s[i-d[i]]) d[i]++;
      if (d[i])d[i]--;
      res += d[i];
      if (i+d[i]-1 > r) l = i-d[i], r = i+d[i]-1;
   }

   cout << res;
   return 0;
}
