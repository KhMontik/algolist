/*
Prefix-function O(N)
Khamitbekov Madi
*/
#pragma linker (comment, '/STACK: 64000000')
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <string.h>

using namespace std;

char a[200][200];
char s[10000];
int main ()
{
   int p[10000];
   int n;
   gets (s);n = strlen(s);
   p[0] = 0;
   for (int i = 1; i < n; i++) {
      int j = p[i-1];
      while (j > 0 && s[i] != s[j]) j = p[j-1];
      if (s[i] == s[j]) j++;
      p[i] = j;
   }
   return 0;
}
