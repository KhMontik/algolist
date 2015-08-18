#include <iostream>

using namespace std;

class Long{
	public:

	int a[200000], n;
	void operator = (const int &x){
		n = 0;
		a[n++] = x;
	}
	void operator = (const Long &x){
		n = x.n;
		for (int i = 0; i < n; i++)	a[i] = x.a[i];
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
	void print()
	{
		while (a[n-1] == 0)	n--;
		for (int i = n-1; i >= 0; i--)
			cout << a[i];
	}

} A;

Long Pow (int x, int n)
{
	Long r;
	r = 1;
	for (int i = 0; i < n; i++)	r *= x;
	return r;
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int n;

	cin >> n;

	A = Pow (45, n);
	A.print();
	return 0;
}
