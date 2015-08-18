#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

struct node{
	node* l;
	node* r;
	int y, val, sz;
};

typedef node* pnode;
pnode L, R, M, root, _x;
int get (pnode v) { if (!v) return 0; return v->sz;}
void calc (pnode v) {
	if (!v) return;
	v->sz = get(v->l) + get(v->r) + 1; 
}
int key (pnode v) {
	return get(v->l)+1;
}

void split (pnode v, int x, pnode &l, pnode &r) {
	if (!v) {l=r=0;return;}
	if (key(v) < x){
		l=v;
		split(v->r,x-key(v),v->r,r);
	}else {
		r=v;
		split(v->l,x,l,v->l);
	}
	calc(l);calc(r);
}
pnode merge (pnode a, pnode b) {
	if (!a || !b) return !a ? b : a;
	pnode res;
	if (a->y > b->y) {
		res = a;
		res->r = merge(res->r,b);
	}else{
		res = b;
		res->l = merge(a,res->l);
	}
	calc(res);
	return res;
}
void add (int x) {
	_x = new node;
	_x->val = x;
	_x->y = rand();
	_x->sz=1;
	root = merge(root,_x);
}
void out (pnode v) {
	if (!v) return;
	out(v->l);
	cout << v->val << " ";
	out(v->r);
}
int main ()
{
	freopen ("movetofront.in", "r", stdin);
	freopen ("movetofront.out", "w", stdout);
	srand (time(0));
	int n, k;
	L = new node;
	R = new node;
	M = new node;
	root = new node;
	root = NULL;
	cin >> n >> k;
	for (int i = 0; i < n; i++) add (i+1);
	//split(root,1,L,R);root = merge(L,R);
	//for (int i = 1; i <= n; i++) {
	//	split(root,i,L,R);
	//	out(L), cout << "  "; out(R), cout << endl;
	//	root = merge(L,R);
	//}
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf ("%d%d", &x,&y);x++,y++;
	//	cout << "was : " , out(root), cout << endl;
		split(root,y,L,R);
	//	cout << "splitted by " << y << ": ", out (L), cout << "  ", out(R), cout << endl;
		split (L, x-1, L, M);
	//	cout << "splitted by " << x-1 << ": ", out (L), cout << "  ", out(M), cout << "  ", out(R), cout << endl;
		L = merge (M,L);
	//	cout << "merged : ", out(L), cout << "  ", out(R), cout << endl;
		root = merge(L,R);
	//	cout << "merged : ", out(root) , cout << endl;
	}	
	out(root);
	
	return 0;
}

