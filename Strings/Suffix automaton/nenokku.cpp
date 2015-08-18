/*
Suffix automaton
Adding words, checking existing of words
O(N) Total
Khamitbekov Madi
*/
#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <cassert>

using namespace std;

const int N = 150000;
char s[N<<1];

struct node {
   int link, len;
   int nx[30];
   node () {
      memset (nx, -1, sizeof (nx));
   }
}a[3*N+7];

int sz = 1, last;
inline void add (char ch) {
   int newl = sz++;
   a[newl].len = a[last].len + 1;
   int i = last;
   int j = (ch-'a');
   //cerr << ss << " " << sz << endl;
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


int main ()
{
   a[0].link = -1;
   a[0].len = 0;
   char ch[2];
   int c;
   int v, ls;
   bool bad = 0;
   while (scanf ("%s%s", ch,s) > 0) {
      ls = strlen(s);
      if (ch[0] == '?') {
         v = 0;
         bad = 0;
         for (int i = 0; i < ls; i++) { 
            c = (s[i] >= 'a' ? s[i]-'a' : s[i]-'A');
            if (a[v].nx[c] == -1) {
               bad = 1;break;
            }
            v = a[v].nx[c];
         }
         printf (bad ? "NO\n" : "YES\n");
      }else {
         for (int i = 0; i < ls; i++)  {
            assert (s[i] >= 'A' && s[i] <= 'z');
            add ((s[i] >= 'a' ? s[i] : s[i]+'a' - 'A'));
         }
      }
   }/**/   
   return 0;
}

