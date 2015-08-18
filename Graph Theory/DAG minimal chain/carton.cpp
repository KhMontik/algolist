#include <algorithm>
#include <iostream>
#include <string.h>
#include <utility>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>   
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

#define abs(x) ((x) > 0 ? (x) : -(x))
#define all(v) (v).begin(), (v).end()
#define sq(x) ((x)*(x))
#define len length()
#define pb push_back
#define mp make_pair
#define s second
#define inf 777777
#define f first
#define sz size() 

bool ok = 0;
struct A {
	int x, y, z;
	void make (int a, int b, int c) {
		vector <int> w;
		w.pb (a), w.pb (b), w.pb (c);
		sort (all(w));
		x = w[2];
		y = w[1];
		z = w[0];
	}
	bool ok (const A &a) {
		return (x < a.x && y < a.y && z < a.z);
	}   
	bool operator < (const A &a) const {
		return (x < a.x && y < a.y && z < a.z);
	}   

}a[1111];
            
int res = 0;
vector <int> h[1111], g[1111];
bool u[1111];
int p[1111];
      
bool dfs (int v) {
	if (u[v]) return 0;
	u[v] = 1;
	for (int i = 0; i < h[v].sz; i++) {
		int j = h[v][i];
		if (p[j] == -1 || dfs(p[j])) {p[j] = v;return 1;}
	}
	return 0;
}
void dfs1 (int v) {
	u[v] = 1;
	for (int i = 0; i < g[v].sz; i++) 
		if (!u[g[v][i]]) dfs1 (g[v][i]);
}

int main ()
{
	freopen ("carton.in", "r", stdin);
	freopen ("carton.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y ,z;
		cin >> x >> y >> z;
		a[i].make (x,y,z);
	}
	int r = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (a[i].ok(a[j])) h[i].pb (j); 
		p[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) u[j] = 0;
		dfs (i); 
	}
	                          
	for (int i = 0; i < n ;i++) 
		if (p[i] != -1) res++;
	/*u[i] = 0;//,		cout << i+1 << " " << p[i]+1 << endl;
	                            
	for (int i = 0; i < n; i++) 
		if (p[i] != -1)  
			 g[p[i]].pb(i);//, cout << p[i] << " " << i << endl;
	for (int i = 0; i < n; i++) 
		if (!u[i])/* cout << i << " i \n",*/ //dfs1(i), res++;//, cout << endl;		
	cout << n-res;
	return 0;                   
}
    
