// Solution by Khamitbekov Madi
#include <iostream>
#include <string>
#include <cstdio>
#define bl 1
#define base 10
#define l length()

using namespace std;

class Long {
	int i;
	public: 
	int a[20000], n;

	void in () {
		string s;
		cin >> s;

		n = (s.l+bl-1) / bl;
		for (i = 0; i < s.l; i++) {
			int x = s[s.l-1-i]-'0';
			if (i % bl) 	a[i/bl] = x;
			else {
				for (int j = 0; j < i%bl; j++)	x*=10;
				a[i/bl] += x;
			}	
		}

	}

	void operator = (const int &x) {
		n = 0;
		int r = x;
		while (r) {
			a[n++] = r%base;
			r /= base;
		}  	
	}

	void operator = (const Long &x) {
		n = x.n;
		for (i = 0; i < n; i++) 	a[i] = x.a[i];
	}

	void operator += (const Long &x) {
		int r = 0;
		for (i = 0; i < max(n, x.n); i++)   {
			a[i] = r + (i < n ? a[i] : 0) + (i < x.n ? x.a[i] : 0);
			if (a[i] >= base)  {
				a[i] -= base;
				r = 1;
			}
			else	r = 0;
		}
		n = max (n, x.n);
		if (r) 	a[n++] = 1;
	}

	void operator *= (const int &x) {
		int y, r = 0;
		for (i = 0; i < n; i++) {
			y = a[i]*x+r;
			a[i] = y%base;
			r = y/base;			
		}
		while (r) {
			a[n++] = r % base;
			r /= base;
		}
	}


	void operator -= (const Long &x) {
		int r = 0;
		for (i = 0; i < n; i++) {
			a[i] -= r+(x.n > i ? x.a[i] : 0);
			if (a[i] < 0) {
				a[i] += base;
				r = 1;
			} 
			else	r = 0;
		}
		while (a[n-1] == 0 && n > 1) n--;
	}

	void operator /= (const int &x) {
		int y;
		;
	}


	bool operator == (const Long &x) {
		if (x.n != n)	return 0;
		for (i = 0; i < n; i++) 
			if (a[i] != x.a[i])	return 0;
		return 1;
	}


	void Mult (const Long &x, const Long &y) {
		int s = 0, k, j;
	        n = x.n + y.n;
	        for (i = 0; i < n; i++)	a[i] = 0;
		for (i = 0; i < x.n; i++) {
			for (j = 0; j < y.n; j++) {
				k = i+j;  
				s = x.a[i] * y.a[j];
				while (s) {
					s += a[k];
					a[k++] = s%base;
					s /= base;
				}
			}
		}
	}


	bool operator < (const Long &x) {
		if (n < x.n)	return 1;
		if (n > x.n)	return 0;
		for (i = 0; i < n; i++) {
			if (a[i] < x.a[i])	return 1;
			if (a[i] > x.a[i])	return 0;
		}
		return 1;
	}

	void operator /= (const int *x) {
		int y;
		for (i = n-1; i >= 0; i--) {
			y = r*base+a[i];
			a[i] /= y%base;
			r = y/base;
		}	
	}                           

	void out () {
		while (a[n-1] == 0 && n > 1) n--;
		cout << a[n-1];
		for (i = n-2; i >= 0; i--) { 
		        cout.width (bl);
		        cout.fill('0');
			cout << a[i];
		}
		cout << endl;
	}

}A;

Long Pow (int x, int y) {
	Long a;
	a = 1;
	while (y) {
		a *= x;
		y--;
	}
	return a;
}

Long FastPow (int x, int y) {
	Long a, b, c;
	a = 1;
	b = x;
	while (y) {
		if (y & 1) {
			c.Mult (a, b);
			a = c;
		}
		y>>=1;
		c.Mult(b, b);
		b = c;
	}
	return a;
}


int main ()
{
	freopen ("ab.in", "r", stdin);
	freopen ("ab.out", "w", stdout);

	int b;
	A.in();
	cin >> b;
	A /= b;
	A.out();

	return 0;
}

