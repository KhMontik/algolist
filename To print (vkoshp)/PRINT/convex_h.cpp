// CONVEX HULL
struct pt {
	int x, y;
	void operator = (const pt &a) {
		x = a.x;
		y = a.y;
	}
	int dis (const pt &a) {
		return ((x-a.x)*(x-a.x) + (y-a.y)*(y-a.y));
	}
	pt operator - (const pt &a) const{
		pt r;
		r.x = x-a.x;
		r.y = y-a.y;
		return r;
	}
	int operator * (const pt &a) const{
		return (x*a.y - a.x*y);
	}
};

int x;


int VM (pt a, pt b) 
{
	return (a.x*b.y - b.x*a.y);
}


bool cmp (pt a, pt b)
{
	return (VM (a, b) > 0 || (VM(a, b) == 0 && a.x*a.x+a.y*a.y < b.x*b.x+b.y*b.y));
}
vector<int> convex_h (pt *q, int n){
	pt m, a[21000];
	int i, j;	
	   x = -1;


	for (i = 0; i < n; i++)a[i] = q[i];
	
	int r[21000];
                                        	r[0] = 0;
	int k = 0;
                               
	for (i = 1; i < n;) {
		if ( k == 0 || ((a[r[k]]-a[r[k-1]])*(a[i]-a[r[k]])) > 0 )
		{
			r[++k] = i;
			++i;
		}
		else
		{
			k--;
		}
	}
	vector <int> res;
	for (i = 0; i <= k; i++)res.push_back(r[i]);
	return res;
}              