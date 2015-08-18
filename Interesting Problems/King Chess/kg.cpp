#include <iostream>

using namespace std;

int main()
{
  freopen ("input.txt", "r", stdin);
  freopen ("output.txt", "w", stdout);

  char a[15][15];
  int ws=0, bs=0, xs=-1, ys=-1, i, j, x, y, x1, y1, wp=0, bp=0, k1=0, k2=0;
  int wt=0, bt=0, f=0, F=0, xS=0, yS=0, xt, yt, xT, yT, xf, yf, xF, yF, xs, ys, xS1, yS1;
  bool w=false, b=false;

  for (i=0; i<8; i++)
  {
   for (j=0; j<8; j++)
   {
    cin >> a[i][j];
    if (a[i][j]=='K')
    {
     x=i;
     y=j;
     k1++;
    }
    if (a[i][j]=='k')
    {
     x1=i;
     y1=j;
     k2++;
    }
    if (a[i][j]=='s')
    {
    ws++;
    xs=i;
    ys=j;
     if (xs==-1 && ys==-1)
     {
      xs=i;
      ys=j;
     }
     else
     {
      if ((xs+i)%2==(ys+j)%2)goto error;
     }
    }
    if (a[i][j]=='S')
    {
    bs++;
    xS1=i;
    yS1=j;
     if (xS==-1 && yS==-1)
     {
      xS=i;
      yS=j;
     }
     else
     {
      if ((xS+i)%2==(yS+j)%2)goto error;
     }
    }
    if (a[i][j]=='f')
    {
     f++;
     xf=i;
     xy=j;
    }
    if (a[i][j]=='F')
    {
     F++;
     xF=i;
     yF=j;
    }
    if (a[i][j]=='t')
    {
     bt++;  
     xt=i;
     yt=j;
    }
    if (a[i][j]=='T')
    {
     wt++;
     xT=i;
     yT=j;
    }
    if (a[i][j]=='p')bp++;
    if (a[i][j]=='P')wp++;
   }
  }
 if (a[1][7]=='P' && xT!=0 && yT!=7)goto error;
 if (a[1][0]=='P' && xT!=0)goto error;
 
 if (x==x1+0 && y==y1+1)goto error;
 if (x==x1+1 && y==y1+1)goto error;
 if (x==x1+1 && y==y1+0)goto error;
 if (x==x1+1 && y==y1-1)goto error;
 if (x==x1+0 && y==y1-1)goto error;
 if (x==x1-1 && y==y1-1)goto error;
 if (x==x1-1 && y==y1+0)goto error;
 if (x==x1-1 && y==y1+1)goto error;
 if (k1!=1 || k2!=1)goto error;
 if (f>1 || F>1)goto error;
 if (wt>2 || bt>2)goto error;
 if (ws>2 || bs>2)goto error;
 if (wp>8 || bp>8)goto error;
 
 //kon'

 if (a[x+1][y+2]=='l')w=true;
 if (a[x+1][y-2]=='l')w=true;
 if (a[x-1][y+2]=='l')w=true;
 if (a[x-1][y-2]=='l')w=true;
 if (a[x+2][y+1]=='l')w=true;
 if (a[x+2][y-1]=='l')w=true;
 if (a[x-2][y-1]=='l')w=true;
 if (a[x-2][y+1]=='l')w=true;
 
 if (a[x1+1][y1+2]=='L')b=true;
 if (a[x1+1][y1-2]=='L')b=true;
 if (a[x1-1][y1+2]=='L')b=true;
 if (a[x1-1][y1-2]=='L')b=true;
 if (a[x1+2][y1+1]=='L')b=true;
 if (a[x1+2][y1-1]=='L')b=true;
 if (a[x1-2][y1-1]=='L')b=true;
 if (a[x1-2][y1+1]=='L')b=true;

 //vertcal ve horizontal whiteGG                     
 for (i=x-1; i>=0; i--)
 {
  if (a[i][y]!='.')
  {
   if (a[i][y]=='t' || a[i][y]=='f')w=true;
   else break;
  }
 }
 for (i=x+1; i<8; i++)
 {
  if (a[i][y]!='.')
  {
   if (a[i][y]=='t' || a[i][y]=='f')w=true;
   else break;
  }
 }
for (i=y-1; i>=0; i--)
 {
  if (a[x][i]!='.')
  {
   if (a[x][i]=='t' || a[x][i]=='f')w=true;
   else break;
  }
 }
for (i=y+1; i<8; i++)
 {
  if (a[x][i]!='.')
  {
   if (a[x][i]=='t' || a[x][i]=='f')w=true;
   else break;
  }
 }


 //black V ve H             

 for (i=x1-1; i>=0; i--)
 {
  if (a[i][y1]!='.')
  {
   if (a[i][y1]=='T' || a[i][y1]=='F')b=true;
   else break;
  }
 }
 for (i=x1+1; i<8; i++)
 {
  if (a[i][y1]!='.')
  {
   if (a[i][y1]=='T' || a[i][y1]=='F')b=true;
   else break;
  }
 }
for (i=y1-1; i>=0; i--)
 {
  if (a[x1][i]!='.')
  {
   if (a[x1][i]=='T' || a[x1][i]=='F')b=true;
    else break;
  }
 }
for (i=y1+1; i<8; i++)
 {
  if (a[x1][i]!='.')
  {
   if (a[x1][i]=='T' || a[x1][i]=='F')b=true;
   else break;
  }
 }
 // peshka

 if (a[x+1][y-1]=='p')w=true;
 if (a[x+1][y+1]=='p')w=true;

 if (a[x1-1][y1-1]=='P')b=true;
 if (a[x1-1][y1+1]=='P')b=true;

 //dioganal

 for (i=x-1; i>=0; i--)
 {
  for (j=y-1; j>=0; j--)
  {
   if (a[i][j]!='.')           
   {
    if (a[i][j]=='s' || a[i][j]=='f')w=true;
    else break;
   }
  }
 }

 for (i=x+1; i<8; i++)
 {
  for (j=y+1; j<8; j++)
  {
   if (a[i][j]!='.')           
   {
    if (a[i][j]=='s' || a[i][j]=='f')w=true;
    else break;
   }
  }
 }


 for (i=x-1; i>=0; i--)
 {
  for (j=y+1; j<=8; j++)
  {
   if (a[i][j]!='.')           
   {
    if (a[i][j]=='s' || a[i][j]=='f')w=true;
    else break;
   }
  }
 }

 for (i=x+1; i<8; i++)
 {
  for (j=y-1; j>=0; j--)
  {
   if (a[i][j]!='.')           
   {
    if (a[i][j]=='s' || a[i][j]=='f')w=true;
    else break;
   }
  }
 }





 for (i=x1-1; i>=0; i--)
 {
  for (j=y1-1; j>=0; j--)
  {
   if (a[i][j]!='.')           
   {
    if (a[i][j]=='S' || a[i][j]=='F')b=true;
    else break;
   }
  }
 }

 for (i=x1+1; i<8; i++)
 {
  for (j=y1+1; j<8; j++)
  {
   if (a[i][j]!='.')           
   {
    if (a[i][j]=='S' || a[i][j]=='F')b=true;
    else break;
   }
  }
 }



 for (i=x1-1; i>=0; i--)
 {
  for (j=y1+1; j<=8; j++)
  {
   if (a[i][j]!='.')           
   {
    if (a[i][j]=='S' || a[i][j]=='F')b=true;
    else break;
   }
  }
 }

 for (i=x1+1; i<8; i++)
 {
  for (j=y1-1; j>=0; j--)
  {
   if (a[i][j]!='.')           
   {
    if (a[i][j]=='S' || a[i][j]=='F')b=true;
    else break;
   }
  }
 }

 if (w && b)goto error;
 if (w)goto whiteGG;
 if (b)goto blackGG;

 cout << "NO CHECK";
 return 0;
 error:
 cout << "ERROR";
 return 0;
 whiteGG:
 cout << "White king is in CHECK";
 return 0;
 blackGG:
 cout << "Black king is in CHECK";
 return 0;
}