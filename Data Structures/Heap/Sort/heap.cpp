#include <iostream>

using namespace std;

int hs = 1, h[121212], p[1212212];

void heapify (int x)
{
	int l = x*2;
	int r = x*2+1;
	int m;
	if (l <= hs && h[l] < h[x]) 	m = l;
	else			        m = x;
	if (r <= hs && h[r] < h[m])	m = r;
	if (m != x)
	{
		swap (h[x],h[m]);
		heapify (m);
	}
}
int h_ext ()
{
	int m;
	if (hs < 1)return 0;
	m = h[1];
	h[1] = h[hs];
	hs--;
	heapify (1);
	return m;
}
void h_ins (int x)
{
	hs++;
	int i = hs;
	while (i > 1 && p[i] < x)
	{
		h[i] = h[i/2];
		i /= 2;
	}
  	h[i] = x;	
}
void build (int *a, int l)
{
	hs = l;
	for (int i=l/2; i>=1; i--)
		heapify(i);
}
void heapsort(int *a)
{
	build (a);
	for (int i=hs; i>=2; i--) 
	{
		swap (a[1],a[i]);
		hs--;
		heapify(a,1);
	}
}

int main()
{
 freopen ("heap.in", "r", stdin);
 freopen ("heap.out", "w", stdout);

 int i, x, n, q[121112];

 cin >> n;

 for (i=1; i<=n; i++)
 {
 	cin >> h[i];
 }

 build (h, n);

 for (i=1; i<=n; i++)
 	cout << h[i] << " ";

 return 0;
}
