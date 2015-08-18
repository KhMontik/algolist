/*
Simple Floyd Algorithm O(V^3)
Khamitbekov Madi
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define inf 1e+100
long double a[200][200];
int n;
int main ()
{
   freopen ("floyd.in", "r", stdin);
   freopen ("floyd.out", "w", stdout);
   
   cin >> n;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++){
         cin >> a[i][j];
         if (a[i][j] == 0 && i != j) a[i][j] = inf;
         if (i == j && a[i][j] > 0) a[i][j] = 0;
      }
   for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++) 
            if (a[i][j] > a[i][k] + a[k][j])   a[i][j] = a[i][k] + a[k][j];
   for (int i = 0;i < n; i++) {
      for (int j = 0; j < n; j++)   cout << a[i][j] << " ";
      cout << endl;
   }
   return 0;
}

