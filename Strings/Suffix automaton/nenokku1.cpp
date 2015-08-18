#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 100500;

struct node {
	int nx[30];
	int link, len;
	node (){
		memset(nx,-1,sizeof(nx));
	}
}t[2*N];

int sz = 1;
int last = 0;

void add (char c) {
	int j = c-'a';
	int v = sz++;
	t[v].len = t[last].len + 1;	
	int x = last;
	while (t[x].nx[j] == -1 && x != -1) t[x].nx[j] = v, x = t[x].link;
	if (x == -1) t[v].link = 0;
	else {
		int q = t[x].nx[j];
		if (t[x].len+1 == t[q].len) t[v].link = q;
		else {
			int clone = sz++;
			t[clone] = t[q];
			t[clone].len = t[x].len + 1;
			t[q].link = clone;
			while (t[x].nx[j] == q && x != -1) t[x].nx[j] = clone, x = t[x].link; 
			t[v].link = clone;
		}
	}
	last = v;
}

int main ()
{
	freopen ("nenokku.in", "r", stdin);
	freopen ("nenokku.out", "w", stdout);

	t[0].link = -1;
	t[0].len = 0;
	char type[2], s[N];

	while (scanf ("%s%s", type, s) > 0) {
	        int n = strlen(s);
		if (type[0] == '?') {
			bool ok = 1;
			int v = 0;
			for (int i = 0; i < n; i++) {
				int j = (tolower(s[i])-'a');
				if (t[v].nx[j] == -1) {ok = 0;break;}
				v = t[v].nx[j];	
			}
			puts(ok ? "YES" : "NO");
		}else {
			for (int i = 0; i < n; i++) add (tolower(s[i]));
		}	
	}

	return 0;
}
