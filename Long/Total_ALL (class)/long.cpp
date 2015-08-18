#include <iostream>
#include <string>

using namespace std;

class Long 
{
	public:
	int a[100000], n;
		Long (const int &x){
			*this = x;
		}
		void operator = (const int &x){
			n = 0;
			a[n++] = x;
		}
		void operator = (const Long &x){
			n = x.n;
			for (int i = 0; i < n; i++)	a[i] = x.a[i];
		}
		void operator += (const int &x){
			int r = 0;
			a[r] += x;
			while (a[r] >= 10){
				a[r] -= 10;
				r++;
				n = max(n, r);
				a[r]++;
			}		
		}
		void operator += (const Long &x){
			int r = 0;
			for (int i = 0; i < max (n, x.n); i++){
				a[i] = r + (i < n ? a[i] : 0) + (i < x.n ? x.a[i] : 0);
				if (a[i] > 9){
					r = 1;
					a[i] -= 10; 
				} 
				else	r = 0;	
			}
			n = max (n, x.n);
			if (r) {
				a[n++] = 1;
			}
		}
		void operator *= (const int &x){
			int r = 0, i, y;
			for (i = 0; i < n; i++){
				y = a[i] * x + r;
				a[i] = y % 10;
				r = y / 10;
			}
			while (r){
				a[n++] = r%10;
				r /= 10;
			}
		}
		void out (){
			for (int i = n-1; i >= 0; i--)
					cout << a[i];
		}
};