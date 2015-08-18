#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 18; 

vector <int> a[N+N];
int d[1<<N];
int n;

#define one(x,i) ((x)&(1<<(i)))
int main ()
{
   freopen ("network.in", "r", stdin);
   freopen ("network.out", "w", stdout);
   
   char ch;
   cin >> n;   
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
         cin >> ch;
         if (ch == 'Y') a[i].push_back (j); 
      }
   int j = 0;
   for (int mask = 0; mask < (1<<n); mask++) {
         if (mask == 1<<(j+1)) j++;
         if (!one(mask,j)) continue;
         for (int c = 0; c < a[j].size(); c++) {
            if (!one(mask,a[j][c])) continue;
            int nm = mask^(1<<j); nm ^= (1<<a[j][c]);
            d[mask] = max(d[mask], d[nm] + 1);
         }
   }
   cout << d[(1<<n)-1]*2;
   return 0;
}
