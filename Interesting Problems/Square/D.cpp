#include <iostream>

using namespace std;

int main ()
{
 freopen ("d.in", "r", stdin);
 freopen ("d.out", "w", stdout);

 int a[110][110], k, s, n, i, j, h, w, c=0;

 cin >> n >> k >> s;

 for (i=1; i<=n; i++)
 {
  for (j=1; j<=n; j++)a[i][j]=0;
 }

 
for (i=1; i<=n; i++)
{
 for (j=1; j<=n; j++)cout << a[i][j] << " ";
 cout << endl;
}

 return 0;
}