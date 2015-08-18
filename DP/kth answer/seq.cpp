#include <iostream>
#include <cstdio>

using namespace std;

const int N = 55;

long long d[N];
string c[4] = {"00", "01", "10", "11"};
int n;
void print (int i, int len, long long k) {
      if (len == 0) return;
      if (len == 1) {
         printf ("%d", k);
         return;
      }
      if (len == 2) {
         cout << c[k];
         return; 
      }
      if (k >= d[len-3]) k -= d[len-3];
      else            {printf ("001"), print(i+3, len-3,k);return;}
      if (k >= d[len-2]) k -= d[len-2];
      else            {printf ("01"), print(i+2, len-2,k);return;}
      printf ("1"), print(i+1,len-1,k);
}

int main ()
{
   freopen ("seq.in", "r", stdin);
   freopen ("seq.out", "w", stdout);
   long long k;   
   int t;
   scanf ("%d\n", &t);
   d[0] = 1;
   d[1] = 2;
   d[2] = 4;
   for (int i = 3; i < N; i++)
      d[i] = d[i-1] + d[i-2] + d[i-3];
   for (int tt = 0; tt < t; tt++) {
      cin >> n >> k;
      print (0,n,k-1);puts("");
   }
   
   return 0;
}

