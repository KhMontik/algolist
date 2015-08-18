#include <iostream>
#include <math.h>
#include <utility>
#define inf 999999999
#define d first
#define i second
#define mk make_pair

using namespace std;

struct pt {int x, y;}P[52000000];

long long dis (pt a, pt b){ return ((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y));}

long long a[5050][5050], d[5050], n;
bool  b[5050];
int p[5050];
class heap {
	public:
	int n;
	pair <int, int> h[100000];

	void clear () {n = 0;}
	int ext () {
		int  r = h[0].i;
		h[0] = h[--n];
		int l = 0, i = 0;
		do {
			if (i*2+1 < n && h[i*2+1].d < h[l].d) l = i*2+1;
			else	l = i;
			if (i*2+2 < n && h[i*2+2].d < h[l].d) l = i*2+2;
			if (i != l) {
				swap (h[i], h[l]); 
				i = l; 
				swap (p[h[i].i] , p[h[l].i]); 
			}
			else	break;
		}while (true);
		return r;
	}
	void ins (pair <int , int> x) {
		h[n].d = x.d;
		h[n++].i = x.i;
		int i = n-1;
		while (h[(i-1)/2].d > x.d && i > 0){swap(h[(i-1)/2], h[i]); i = (i-1)/2;}
		h[i].d = x.d;
		h[i].i = x.i;
		p[x.i] = i;
	}
	void update (int x, int key) {
		h[p[x]].d = key;
		int i = p[x];
		while (h[(i-1)/2].d > key && i > 0){swap(h[(i-1)/2], h[i]); i = (i-1)/2;}
		h[i].d = key;
		h[i].i = x;
		p[x] = i;
	}
	void print () {
		for (int i = 0; i < n; i++)	cout << h[i].d << " ";
		cout << endl; 
	}
	bool emp () {return (n > 0);}
};
void Prim (int v)
{
	fill (d, d+n+1, inf);
	fill (b, b+n+1, 0);
	fill (p, p+n+1,-1);
	int i, x = v;

	d[v] = 0;
	heap h;
	h.ins (mk (d[v], v));
	b[v] = 1;
	do {    
		if (x != -1) {
			for (i = 0; i < n; i++)
				if (!b[i] && a[x][i] < d[i] && a[x][i] > 0){
					d[i] = a[x][i];    
					h.update (i, d[i]);
				}
		}
		b[x] = 1;
		x = -1;                                       /*
		for (i = 0; i < n; i++)                       
			if ((x == -1 || d[i] < d[x]) && !b[i])	x = i;*/
		x = h.ext();     	
	}while (x != -1);                                             
}

int main ()
{
	freopen ("Prim.in", "r", stdin);
	freopen ("Prim.out", "w", stdout);

	int k = 0, i, j; 
	double s = 0;

	scanf ("%d", &n);
	for (i = 0; i < n; i++) scanf ("%d %d", &P[i].x, &P[i].y);

	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			a[i][j] = dis (P[i], P[j]);
			a[j][i] = dis (P[i], P[j]);
			if (i == j)	a[i][j] = -1;
		}
	}

	Prim (0);

	for (i = 0; i < n; i++) {
		if (d[i] != inf)
			s += sqrtl(d[i]);
	}
	printf ("%.10f\n", s);

	
	return 0; 
}


