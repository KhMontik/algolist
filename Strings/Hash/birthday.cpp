#include <iostream>
#include <set>
#include <cstdio>
#include <utility>
#include <string.h>

using namespace std;

typedef unsigned long long ull;

const int pr1 = 997;
const int pr2 = 1000000007;
set < pair <ull, ull> > ans;

int main ()
{
   freopen ("birthday.in", "r", stdin);
   freopen ("birthday.out", "w", stdout);

   char s[20000];   
   ull h1 = 0, h2 = 0;
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      scanf ("%s", &s);
      int sl = strlen(s);
      h1 = h2 = 0;
      for (int j = 0; j < sl; j++)
         h1 = h1*pr1+(s[j]-96), h2 = h2*pr2+(s[j]-96);
      ans.insert ( make_pair (h1, h2) );
   }
   cout << ans.size();
   return 0;
}
