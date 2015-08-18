/*
DP on Suffix Automaton
Sum of lengths of different substrings O(N)
Khamitbekov Madi
*/
#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

const int N = 300007;
char s[N<<1];

struct node {
   int link, len;
   int nx[30];
   node () {
      memset (nx, -1, sizeof (nx));
   }
}a[2*N];
int sz = 1, last;
inline void add (char ch) {
   int newl = sz++;
   a[newl].len = a[last].len + 1;
   int i = last;
   int j = (ch-'a');
   assert (j >= 0 && j < 26);
   while (i >= 0 && a[i].nx[j] == -1) a[i].nx[j] = newl, i = a[i].link;
   if (i == -1) a[newl].link = 0;       // situation 1
   else {
      int q = a[i].nx[j];
      if (a[i].len+1 == a[q].len) {   // situation 2a
         a[newl].link = q;
      }else {                         // situation 2b
         int ss = sz++;
         memcpy (a[ss].nx, a[q].nx, sizeof(a[q].nx));
         a[ss].len = a[i].len + 1;
         int x = i;
         while (x >= 0 && a[x].nx[j] == q) a[x].nx[j] = ss, x = a[x].link;
         a[ss].link = a[q].link;
         a[q].link = ss;
         a[newl].link = ss;
      }
   }
   last = newl;
}

char t[N];
int q[N];
long long d[N], d1[N];
long long calc1 (int v) {
   if (d1[v] != -1) return d1[v];
   d1[v] = 0;
   for (int i = 0; i < 26; i++)
      if (a[v].nx[i] != -1) 
         d1[v] += calc1(a[v].nx[i]) + 1;
   return d1[v];
}
long long calc (int v) {
   if (d[v] != -1) return d[v];
   d[v] = 0;
   for (int i = 0; i < 26; i++)
      if (a[v].nx[i] != -1) 
         d[v] += calc(a[v].nx[i])+calc1(a[v].nx[i])+1; 
   return d[v];
}
int main ()
{
   freopen ("diff.in", "r", stdin);
   freopen ("diff.out", "w", stdout);
   
   a[0].link = -1;
   a[0].len = 0;
   scanf ("%s", t);
   int ls = strlen(t);
   for (int i = 0; i < ls; i++)  add (t[i]);
   memset (d, -1, sizeof(d));
   memset (d1, -1, sizeof(d1));
   cout << calc1(0) << "  " << calc (0);
   return 0;
}

