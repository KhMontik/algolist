// Jury
#include <iostream>
#include <string>
#define base 10
#define bl 1

using namespace std;

class Long {
	public:
	int a[100000], n;
	void operator = (const int &q) {
		int x = q;
		n = 0;
		while (x) {
			a[n++] = x % base;
			x /= base;
		} 
	}

	void operator = (const Long &x) {
		n = x.n;
		for (int i = 0; i < n; i++) 	a[i] = x.a[i];
	}

	bool operator == (const Long &x) {
		if (x.n != n)	return 0;
		for (int i = 0; i < n; i++) 
			if (x.a[i] != a[i])	return 0;
		return 1;
	}

	bool operator < (const Long &x) {
		if (n > x.n)	return 0;
		if (n < x.n)	return 1;
		for (int i = n-1; i >= 0; i--) {
			if (a[i] < x.a[i])	return 1;
			if (a[i] > x.a[i])	return 0;				
		}
	}

	void operator -= (const Long &x) {
		int i, r = 0;
		for (i = 0; i < n; i++) {
			a[i] = a[i] - (r + (x.n < i ? 0 : x.a[i]) );
			if (a[i] < 0) {
				a[i] += base;
				r = 1;
			} 
			else	r = 0;
		}

		while (a[n-1] == 0 && n-1 > 0)	n--;
	}

	void operator *= (const int &x) {
		int i, r = 0, y;
		for (i = 0; i < n; i++) {
			y = a[i]*x+r;
			a[i] = y%base;
			r = y/base;
		}
		while (r) {
			a[n++] = r % base;
			r /= base; 
		}
		
		while (a[n-1] == 0 && n-1 > 0)	n--;
	}
	
	void Mult (const Long &x, const Long &y) {
		int i, j, s = 0, k;
		n = x.n + y.n;
		for (i = 0; i < n; i++)	a[i] = 0;
                for (i = 0; i < x.n; i++) {
                	for (j = 0; j < y.n; j++) {
                		k = i+j;
                		s = x.a[i] * y.a[j];
                		while (s > 0) {
                			s += a[k];
          	 	     		a[k++] = s%base;
          	 	     		s/=base;
                		}
                	}
                }
	}

	void print (){
		while (a[n-1] == 0 && n-1 > 0)	n--;                              
		cout << a[n-1];
		for (int i = n-2; i >= 0; i--) {
			cout.width (bl);
			cout.fill ('0');
			cout << a[i];
		}
	} 
};

int main ()
{
	freopen ("mod.in", "r", stdin);
	freopen ("mod.out", "w", stdout);

	int p, q, r = 1;

	Long m, n, s, R, w;

	cin >> q;
	cin >> p;
	n = q;
	m = 1;            
	while (q > 1) {  
		if (q % 2 == 1) {
			s.Mult (m, n);
			m.n = p;
			for (int i = 0; i < p; i++)	m.a[i] = s.a[i];	
			q--;
		}          
		q /= 2;
		s.Mult (n, n);
		n.n = p;
		for (int i = 0; i < p; i++)	n.a[i] = s.a[i];	
	}
	R.Mult(m, n);

	R.n = p;
	
	R.print ();
                                
                                
        return 0;
}

