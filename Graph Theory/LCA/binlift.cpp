/*
Least Common Ancestor Problem
On-Line solution using binary lift algorithm O(MlogN)
Khamitbekov Madi
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std; 

const int N = 500001;

int up[N][20];
int lvl[N];

int main ()
{
   freopen ("lca.in", "r", stdin);
   freopen ("lca.out", "w", stdout);
   
   char tmp[50];
   int m;
   int x, y;
   scanf ("%d", &m);
   lvl[0] = 0;
   for (int i = 0; i < 20; i++) up[0][i] = 0;
   for (int i = 0; i < m; i++)  {
      scanf ("%s %d %d\n", &tmp, &x, &y);
      x--, y--;
      if (tmp[0] == 'A') {
         up[y][0] = x;
         lvl[y] = lvl[x] + 1;
         for (int j = 1; j < 20; j++) up[y][j] = up[up[y][j-1]][j-1];
      }else {  
         if (lvl[x] < lvl[y]) swap (x,y);
         for (int j = 19; j >= 0; j--)
            if (lvl[up[x][j]] >= lvl[y]) x = up[x][j];
         if (x == y) {
            printf ("%d\n", x+1);
            continue;
         }
         for (int j = 19; j >= 0; j--)
            if (up[x][j] != up[y][j]) x = up[x][j], y = up[y][j];
         x = up[x][0];
         y = up[y][0];
         printf ("%d\n", x+1);
      }
   } 
   return 0;
}
