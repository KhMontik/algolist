#include <iostream>

using namespace std;
long a[11111], n;

int quicksort(long *it, long l, long r)
{
  int i, j;
  int x;
  i=l;j=r;
  x=it[(l+r)/2];
   do
   {
    while (i<r && it[i]<x)i++;
    while (j>l && it[j]>x)j--;
     if (i<=j)
     {
      swap(it[i],it[j]);
      i++;j--;
     }
   }while(i<=j);

  if (j>l) quicksort(it, l, j);
  if (i<r) quicksort(it, i, r);
   
   
}
int main()
{
 freopen ("input.txt", "r", stdin);
 freopen ("output.txt", "w", stdout);
 int i;
 cin >> n;
 for (i=1; i<=n; i++) cin >> a[i];
 quicksort (a, 1, n);
 for (i=1; i<=n; i++) cout << a[i] << " ";
 return 0;
}