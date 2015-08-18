/*
Almaty KTL Typical Exam
Problem C: route
Author: Khamitbekov Madi
*/
#include <iostream>

using namespace std;

const int MAXN = 1000010;
const int MAXM = 1000010;

int nx[MAXM], h[MAXN], p[MAXN], f[MAXM], t[MAXM], w[MAXM], e[MAXM];

void qs (int *q, int l, int r)
{
	int x = q[(l+r)/2], i=l, j=r;

		do 
		{
			while (q[i] < x && i < r) i++;
			while (q[j] > x && j > l) j--;

			if (i <= j)
			{
				swap (f[i], f[j]);
	                        swap (q[i], q[j]);
				swap (t[i], t[j]);
				i++;
				j--;
			}	
		}while (i <= j);
	if (i<r) qs (q,i,r);
	if (j>l) qs (q,l,j);	
}

void un (int x, int y) 
{
	if (h[x] > h[y])
		p[y] = x;
	else    p[x] = y;
	if (h[x] == h[y])
		h[y]++; 	
}
int fs (int x)
{
	if (x!=p[x])
		p[x] = fs (p[x]);
	return p[x];
}

int main()
{
 freopen ("route.in", "r", stdin);
 freopen ("route.out", "w", stdout);

 int q, i, j, m, n, res = -1;

 cin >> n >> m;
                 

 for (i=0; i<=1000000; i++)
 	e[i]=-1; 
 
 for (i=0; i<m; i++)
 {   
	scanf ("%i %i %i", &f[i], &t[i], &w[i]);
        --f[i];
        --t[i];
        nx[i] = e[w[i]];
	e[w[i]] = i;
 }

 for (i=0; i<m; i++)
 {
 	p[i] = i;
 	h[i] = 1;
 } 	

 //qs (w, 1, m);

	for (j = 0; j <= 1000000; j++) 
	{
		i = e[j];
		while (i != -1) 
		{
 			int x = fs (f[i]);
 			int y = fs (t[i]);
  
        		if (x != y)
        		{
         			un (x, y);
         			if ( w[i] < res )
         	 		res = w[i];
        		}	
  			if (fs(0) == fs(n-1))
  			{
  		 		res = w[i];
  				break; 
  			}
  			i = nx[i];
  	       }
  	       if (res != -1)break;
  	}
 printf ("%i", res);
               
 return 0;
}
