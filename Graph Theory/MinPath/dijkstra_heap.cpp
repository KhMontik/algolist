#include <iostream>
#include <vector>
#include <utility>
#define i second
#define d first
#define pb push_back
#define sz size()
#define mk make_pair

using namespace std;

const int inf = 32500;
int p[11000];

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

vector < int > a[2010], W[2010];

int n, m;
int d[11100];
bool b[11100];

void Dijkstra (int v) {
	fill (d, d+n+1, inf);
	fill (b, b+n+1, 0);
	d[v] = 0;

	heap h;

	for (int i = 0; i < a[v].sz; i++) d[a[v][i]] = min (W[v][i], d[a[v][i]]), h.ins ( mk (d[a[v][i]], a[v][i]) );
        

	int x = -1;
	b[v] = 1;

	do{
		if (x != -1){
		        b[x] = 1;
			for (int i = 0; i < a[x].sz; i++) 
				if (!b[a[x][i]] && (d[a[x][i]] > d[x] + W[x][i])) {
					d[a[x][i]] = d[x] + W[x][i];
					h.update (a[x][i], d[a[x][i]]);
				}
		}
		b[x] = 1;
		x = -1;
	
/*	for (int i = 0; i < a[v].sz; i++)
			if (!b[a[v][i]] && (d[a[v][i]] != inf) && (x == -1 || d[a[v][i]] < d[x]))	x = a[v][i];
	*/x = h.ext();
	}while (x != -1);
}               


int main()
{
	freopen ("dijkstra.in", "r", stdin);
	freopen ("dijkstra.out", "w", stdout);
	
	int i, f, t, w;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> f >> t >> w;
		f--;t--;
		a[f].pb (t);
		W[f].pb (w);
	}
        Dijkstra (0);

        cout << ((d[n-1] == inf) ? -1 : d[n-1]);

	return 0;
}
