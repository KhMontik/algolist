#define base 100
#define bl 2

using namespace std;

class Long {
	public:
	int n, a[1000];
	void in () {                    
		string s;
		cin >> s;
		n = (s.length()+bl-1)/bl;

		for (int i = 0; i < s.length(); i++) {
		        int x = s[s.length()-i-1]-'0';
			if (i % bl == 0)	a[i/bl] = x;
			else {
				for (int j = 0; j < i % bl; j++)
					x *= 10;
				a[i/bl] += x;

			}
		}
				         	
	}
	void operator = (const int &x) {
		n = 0;
		a[n++] = x;
	}
	void operator = (const Long &x) {
		n = x.n;
		for (int i = 0; i < n; i++)	a[i] = x.a[i];
	}
	bool operator <= (const Long &x) {
		if (n < x.n) return 1;
		if (n > x.n) return 0;
		for (int i = n-1; i >= 0; i--) {
			if (a[i] < x.a[i]) return 1;
			if (a[i] > x.a[i]) return 0;
		}
		return 1;
	}
	bool operator == (const Long &x) {
		if (n != x.n) return 0;
		for (int i = 0; i < n; i++)	
			if (a[i] != x.a[i]) return 0;
		return 1;
	}
	void operator /= (const int &x) {
		int y, r = 0;
		for (int i = n-1; i >= 0; i--) {
			y = r*base+a[i];
			a[i] = (y/x);
			r = (y%x);	
		}
		while (a[n-1] == 0 && n > 1) n--;
	}
	void operator += (const Long &x) {
		int r = 0;
		for (int i = 0; i < max(n, x.n); i++) {
			a[i] = r + (i < n ? a[i] : 0) + (i < x.n ? x.a[i] : 0);
			if (a[i] >= base) {
				a[i] -= base;
				r = 1;
			}
			else r = 0;
		}
		n = max (n, x.n);
		if (r)	a[n++] = 1;
	}
	void operator -= (const Long &x) {
		int r = 0;
		for (int i = 0; i < n; i++) {
			a[i] = a[i] - r - (i < x.n ? x.a[i] : 0);
			if (a[i] < 0) {
				a[i] += base;
				r = 1;
			}
			else r = 0;
		}
		n = max (n, x.n);
		if (r)	a[n++] = 1;
		while (a[n-1] == 0 && n > 1) n--;

	}
	void out () {
		while (a[n-1] == 0 && n > 1) n--;
		cout << a[n-1];
		for (int i = n-2; i >= 0; i--){
		        cout.width(bl);
		        cout.fill('0');
			cout << a[i];	
		}
	}

	void Mult (Long A, Long B) {
		n = A.n + B.n;
		for (int i = 0; i < n; i++) a[i] = 0;
		for (int i = 0; i < A.n; i++) 
			for (int j = 0; j < B.n; j++)
				a[i+j] += A.a[i]*B.a[j];
		int r = 0;
		for (int i = 0; i < n; i++) {
			a[i] += r;
			if (a[i] >= base) {
				r = a[i]/base;
				a[i] %= base;
			}else r = 0;
		}	
		while (r) {
			a[n++] = r%base;
			r /= base;
		}
		while (a[n-1] == 0 && n > 1) n--;
	}	

}