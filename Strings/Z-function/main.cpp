/*
Calculating Z-function O(N)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

const int N = 5000;
int z[N];
char s[N];
int n;

void calc_z () {
   memset (z,0,sizeof(z));
   int l = 0, r = 0;
   z[0] = n;
   for (int i = 1; i < n; i++) {
      if (z[i-l]+i <= r) z[i] = z[i-l];
      else {
         l = i;
         if (i > r) r = i;
         for (z[i] = r-i; r < n; r++, z[i]++)
            if (s[r] != s[z[i]]) break;
         r--;
      }
   }
}
int main ()
{
   scanf ("%s", s);
   n = strlen(s);
   s[n] = '@';
   calc_z();
   return 0;
}

