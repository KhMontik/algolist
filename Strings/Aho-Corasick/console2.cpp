/*
Aho-Corasick algorithm
Finding existing of word O(Length)
Building trie O(NK) K - const (26)
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <string.h>

using namespace std;

const int N = 80001;
const int K = 100;

struct node {
   int nx[K];
   int pr;
   char pch;
   int suff;
   bool end;
} a[N];
int sz = 1;
void add (int p, char ch) {
   a[p].nx[ch] = sz;
   memset (a[sz].nx, -1, sizeof (a[sz].nx));
   a[sz].pr = p;
   a[sz].pch = ch;
   sz++;
}
bool u[N];
queue <int> q;
char s[2000000];

void bfs () {
  q.push (0);
   u[0] = 1;
   while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int i = 0; i < K; i++) {
         if (a[x].nx[i] != -1 && !u[a[x].nx[i]]) {
            int cur = a[x].nx[i];
            q.push (cur);
            u[cur] = 1;
            int v = a[x].suff;
            while (a[v].nx[i] == -1 && v) v = a[v].suff;
            if (a[v].nx[i] == cur || a[v].nx[i] == -1) a[cur].suff = 0;
            else    a[cur].suff = a[v].nx[i];
            a[cur].end |= a[a[cur].suff].end;
            for (int j = 0; j < K; j++)
               if (a[a[cur].suff].nx[j] != -1 && a[cur].nx[j] == -1) a[cur].nx[j] = a[a[cur].suff].nx[j]; 
         }
      }
   }
 
}

void adds () {
   int ls = strlen(s);
      int v = 0;
      for (int j = 0; j < ls; j++) {
         char ch = s[j]-32;
         if (a[v].nx[ch] == -1)  add (v,ch);
         v = a[v].nx[ch];
      }
      if (v)
      a[v].end = 1;
}
bool ok () {
      int ls = strlen(s);
      int v = 0;
      for (int i = 0; i < ls; i++) {
         int j = s[i]-32, ov = v;
         while (a[v].nx[j] == -1 && v) v = a[v].suff;
         v = a[v].nx[j];
         a[ov].nx[j] = v;
         if (v == -1) v = 0;
         if (a[v].end)  return 1;
      }
      return 0;
}
int main ()
{  
   memset (a[0].nx, -1, sizeof(a[0].nx));
   a[0].suff = 0;
   int n;
   cin >> n;  
   gets(s);
   for (int i = 0; i < n; i++)  gets(s), adds();      
   bfs();
   while (gets(s)) 
      if (ok())puts(s);
   
   return 0;
}

