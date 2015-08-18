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
	int a[2000000], n;

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


	bool operator == (const Long &x) {
		if (x.n != n)	return 0;
		for (i = 0; i < n; i++) 
			if (a[i] != x.a[i])	return 0;
		return 1;
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


	void out () {
		while (a[n-1] == 0 && n > 1) n--;
		for (i = n-1; i >= 0; i--) { 
		        cout.width (bl);
		        cout.fill('0');
			cout << a[i];
		}
		cout << endl;
	}

}A;

int main ()
{
	freopen ("ab.in", "r", stdin);
	freopen ("ab.out", "w", stdout);

	int b;
	A.in();
	cin >> b;

	A *= b;
	A.out();

	return 0;
}
