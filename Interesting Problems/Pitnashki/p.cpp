#include <iostream>

using namespace std;


long long k=0, a[4][4], b[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
char R[100], t;
bool out=false;
void Mesto (long long x, long long y, long long c, char t)
{
bool Ok=true;
for (int i=0; i<4; i++)
{
 for (int j=0; j<4; j++)
 {
  if (a[i][j]!=b[i][j])Ok=false;
  cout << a[i][j] << " ";
 }
 cout << endl;
}
if (Ok || out)
 {
  out=true;
  R[k++]=t;
  return;
 }
 if (t=='U')swap(a[x][y],a[x+1][y]);
 if (t=='L')swap(a[x][y],a[x][y+1]);
 if (t=='D')swap(a[x][y],a[x-1][y]);
 if (t=='R')swap(a[x][y],a[x][y-1]);
 if (c<=50)
 {
  c++;
  if (x!=3)Mesto(x+1,y,c,'D');
  if (y!=3)Mesto(x,y+1,c,'R');
  if (y!=0)Mesto(x,y-1,c,'L');
  if (x!=0)Mesto(x-1,y,c,'U');
 }
 return;
}

int main()
{
 freopen ("input.txt", "r", stdin);
 freopen ("output.txt", "w", stdout);

 long long i, j, q, w, n[16];
 
 
 for (i=0; i<=15; i++)n[i]=0;
 for (i=0; i<4; i++)
 {
  for (j=0; j<4; j++)
  {
   cin >> a[i][j];
   if (a[i][j]==0)
   {
    q=i;
    w=j;
   }
   else n[a[i][j]]++;  
  }
 }
 for (i=1; i<=15; i++)
 {
  if (n[i]!=1)
  {
   cout << "ERROR";
   return 0;
  } 
 } 
 Mesto (q, w, 0, 'M');

 for (i=0; i<16; i++)
 {
  cout << R[i];
 }
 return 0;
}
