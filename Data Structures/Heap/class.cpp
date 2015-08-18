#include <iostream>

using namespace std;

class heap {
	int i;
	public:
	int h[777777], n;
        
        void ins (int x) {
        	h[n++] = x;
        	int i = n-1;
        	while (i > 0 && x < h[(i-1)/2]) {swap (h[i], h[(i-1)/2]); i = (i-1)/2;}
        	h[i] = x;
        }
        int ext () {
        	int res = h[0];
        	h[0] = h[--n];
        	int i = 0, l = 0;
        	do {
	      		if (h[i*2+1] < h[l] && i*2+1 < n)	l = i*2+1;
	      		else l = i;
        		if (h[i*2+2] < h[l] && i*2+2 < n)	l = i*2+2;
        		if (i != l){	swap (h[i], h[l]);i = l;}
        		else	break;   	
        	}while (true);
        	return res;
        }
        int getmin () {return h[0];}
        void clear () {n = 0;}
        void print () {
        	for (i = 0; i < n; i++)	cout << h[i] << " ";
        	cout << endl;
        }
} h;

int main()
{
	freopen ("heap.in", "r", stdin);
	freopen ("heap.out", "w", stdout);
	
	int n, i, x;
	h.clear();

	cin >> n;

	for (i = 0; i < n; i++) cin >> x, h.ins (x);
	for (i = 0; i < n; i++) cout << h.ext() << " ";

	h.print();
	return 0;
}
