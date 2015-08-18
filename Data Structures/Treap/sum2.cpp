#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
	node* l;
	node* r;
	long long sum;
	int y, key;
	node()
	{
		l = r = 0;
		sum = key = 0;
		y = rand()<<16|rand();
	}
};

typedef node* pnode;

pnode L, M, R, _x, root;

long long sum (pnode v) { return !v ? 0 : v->sum;}
void upd (pnode v) {
	if (!v) return;
	v->sum = sum(v->l) + sum(v->r) + (long long)v->key;
}
void split (pnode v, int x, pnode &l, pnode &r) {
	if (!v) {l = r = 0;return;}
	if (v->key < x) l = v, split(v->r,x,v->r,r);
	else	        r = v, split(v->l,x,l,v->l);
	upd(l), upd(r);
}
pnode merge (pnode a, pnode b) {
	if (!a || !b) return a ? a : b;
	pnode v;
	if (a->y < b->y) v = a, v->r = merge(a->r,b);
	else		 v = b, v->l = merge(a,b->l);
	upd(v);
	return v;
}               
bool _find (int x) {
	bool ret = 1;
	split(root,x,L,R);
	split(R, x+1, M, R);
	if (!M) ret = 0;
	root = merge( L,merge(M,R));
	return ret;
}

void add (int x) {
	if (_find(x)) return;
	_x = new node;
	_x -> key = x;
	_x -> sum = x;
	split(root,x,L,R);
	root = merge(merge(L,_x),R);	
}

long long get (int l, int r) {
	long long ret = 0;
	split(root,r+1,L,R);
	split(L,l,L,M);
	ret = sum(M);
	root = merge(merge(L,M),R);
	return ret;
}

int main()
{
	freopen ("sum2.in", "r", stdin);
	freopen ("sum2.out", "w", stdout);
	srand(347237145);	
	int m, x, y;
	long long res = 0;
	cin >> m;
	char tmp[23];
	for (int i = 0; i < m; i++) {
		scanf ("%s", tmp);
		if (tmp[0] == '+')	scanf ("%d", &x), add((res+x)%1000000000), res = 0;
		else			scanf ("%d%d", &x, &y), res = get(x,y), printf("%I64d\n", res);
	}

	return 0;
}
