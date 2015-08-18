E:\olymp\algo\data structure\aho korasik.cpp
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
#define pb push_back

struct aho_korasik {
	int link, pr, cnt, ch[100], symbol;
} aho[81000];

string s;
int n, m;

void add(const string &s)
{
	int i, u, v = 0, l = s.length();
	for (i = 0; i < l; i++)
	{
		u = s[i] - 31;
		if (aho[v].ch[u]) v = aho[v].ch[u]; else {
			aho[v].ch[u] = ++n;
			aho[n].pr = v;
			aho[n].symbol = u;
			v = n;
		}
	}
	aho[v].cnt++;
}

int getlink(int v, int u) {
	while (!aho[v].ch[u] && v) v = aho[v].link;
	return aho[v].ch[u];
}

void build() { //bfs
	int i, v, u;
	vector<int> q;
	q.pb(0);
	for (i = 0; i < q.size(); i++) {
		v = q[i];
		if (aho[v].pr) aho[v].link = getlink(aho[aho[v].pr].link, aho[v].symbol);
		aho[v].cnt += aho[aho[v].link].cnt;
		for (u = 1; u <= 96; u++)
			if (aho[v].ch[u]) q.pb(aho[v].ch[u]);
	}
}

int calc(const string &s) {
	int i, r = 0, v = 0, u, l = s.length();
	for (i = 0; i < l; i++) {
        u = s[i] - 31;
		while (!aho[v].ch[u] && v) v = aho[v].link;
		v = aho[v].ch[u];
		r += aho[v].cnt;
	}
	return r;
}

int main() {
	freopen("console2.in", "r", stdin);
	freopen("console2.out", "w", stdout);
	scanf("%d\n", &m);
	while (m--) {
		getline(cin, s);
		add(s);
	}

	build();

	while (getline(cin, s)) {
		m = calc(s);
		if (m) cout << s << endl;
	}
}
