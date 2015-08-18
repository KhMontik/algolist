#include <iostream>
#include <cstdio>
#include <string.h>
#include <map>

using namespace std;

typedef unsigned long long ull;

const int N = 10000;
const int pr = 31;
const int maxn = 600;
string str, t;
map <ull, int> id; 
int n = 0, sz = 1;
int a[maxn];
int d[maxn][maxn];

int calc (int l, int r) {
   if (l > r) return 0;
   if (d[l][r] != N) return d[l][r];
   if (l == r) return 1;
   if (l+1 == r) return (int)((a[l]!=-a[r] || a[l] < 0)*2);
   for (int i = l+1; i <= r; i++)
      if (a[l] > 0 && a[l] == -a[i]) d[l][r] = min (d[l][r], calc (l+1,i-1) + calc(i+1,r));
   d[l][r] = min(d[l][r],calc (l+1,r) + 1);  
   return d[l][r];
}
int main()
{
   freopen ("html.in", "r", stdin);
   freopen ("html.out", "w", stdout);
   
   for (int i = 0; i < maxn; i++)
      for (int j = 0; j < maxn; j++) d[i][j] = N;
   int cur;   
   while (cin >> str) {
      for (int it = 0; it < str.length(); it++) {
         if (str[it] == '<') {
            ull hash = 0;
            int t = (str[it+1] == '/');
            int st = it+t+1;
            for (it = st; str[it] != '>' && it < str.length(); it++)
                  hash = hash*pr+int(str[it]);
            if (!id[hash]) id[hash] = sz++, cur = sz-1;
            else           cur = id[hash];    
            if (!t) a[n++] = cur;
            else    a[n++] = -cur;
         }
      }
   }
   
   cout << calc (0,n-1);   
  // for (int i = 0; i < n; i++) {
  //    for (int j = 0; j < n; j++)   
  //       if (d[i][j] != N) cout << i+1 << " " << j+1 << " " << d[i][j] << endl;
   //}
   return 0;
}
//(][[])[{}]<[{]}>
