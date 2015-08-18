#include <iostream>
using namespace std;
const int base = 10000;

struct BigInteger {
	
	int num[10000];

	BigInteger()
	{
		memset(num,0,sizeof(num));
	}
		
	BigInteger(long long x)
	{
		memset(num,0,sizeof(num));
		if (x==0) {
			num[0]=1;
			num[1]=0;
		}
		while (x>0) {
			num[++num[0]]=x%base;
			x/=base;
		}	
	}                   

	BigInteger operator+(const BigInteger &a) {
		BigInteger res;
		res.num[0] = max(num[0],a.num[0]);
		
		for (int i=1;i<=res.num[0];i++) {
		
			res.num[i+1]+= (res.num[i] + num[i] + a.num[i])/base;
			res.num[i] = (res.num[i] + num[i] + a.num[i])%base;
		
		}		 

		if (res.num[res.num[0]+1]) res.num[0]++;

		return res;
	}


	//this  < a -1
	//this  ==a 0
	//this > a 1
	int compare(const BigInteger &a) 
	{
		if (num[0] < a.num[0])	return -1;
		if (num[0] > a.num[0])	return 1; 

		for (int i=num[0];i>=1;i--)
		if (num[i] < a.num[i])	return -1; else
		if (num[i] > a.num[i])	return 1; 
		return 0;

	}

	bool operator<( BigInteger &a)
	{
		return (compare(a) == -1);
	}

	bool operator>( BigInteger &a)
	{
		return (compare(a) == 1);
	}

	bool operator==( BigInteger &a)
	{
		return (compare(a) == 0);
	}
	
	bool operator!=( BigInteger &a)
	{
		return (compare(a) != 0);
	}



	BigInteger operator-(const BigInteger &a)
	{
		BigInteger res;
		res.num[0] = num[0];
		for (int i=1;i<=res.num[0];i++)
		{
			res.num[i]+=num[i] - a.num[i];
			if (res.num[i]<0) {
				res.num[i+1]--;
				res.num[i]+=base;
			}
		}                		
		while (res.num[0]>1 && !res.num[res.num[0]]) res.num[0]--;

		return res;
	
	}
	
	BigInteger operator*(const BigInteger &a)
	{
		BigInteger res;
		res.num[0] = num[0]+a.num[0];
		for (int i=1;i<=num[0];i++)
		for (int j=1;j<=a.num[0];j++)  {
			res.num[i+j] += (res.num[i+j-1] + a.num[j]*num[i])/base;
			res.num[i+j-1] = (res.num[i+j-1] + a.num[j]*num[i])%base;
		}
		while (res.num[0] > 1 && !res.num[res.num[0]])  res.num[0]--;
		return res;

	}

	BigInteger shift(int sp) {
		BigInteger res;
		res.num[0]=sp;
		for (int i=1;i<=num[0];i++) res.num[++res.num[0]] = num[i];
		return res;
	}


	int FindBin(BigInteger &a,BigInteger &b,int sp)
	{
		int l =0 ,r=base;
		BigInteger bs = b.shift(sp);

		while (r-1 > l) {
			                         
			int m= (l+r)/2;
			
			int comp= a.compare(bs*BigInteger(m));
			
			if (comp == 0) {
				 a = BigInteger(0); 	
				 return m;
			} 
			if (comp == 1) l=m; else r=m;

		}


		a=a-bs*l;
		return l;

	}

	BigInteger operator/( BigInteger &b)
	{
		BigInteger a;
		for (int i=1;i<=num[0];i++) a.num[i]=num[i];
		a.num[0]=num[0];

		int comp = a.compare(b);

		if (comp == 0) return BigInteger(1); else
		if (comp == -1) return BigInteger(0); else
		{

			
			int sp = a.num[0] - b.num[0];			
			
			while (a.compare(b.shift(sp)) == -1)  sp--;

			BigInteger res;
			for (int i=sp+1;i>=1;i--) res.num[i] = FindBin(a,b,i-1);
			res.num[0]=sp+1;
			return res;
		}
	}


	void read()
	{
		char ch='a';
		while (!isdigit(ch)) ch=getchar();

		do {
			for (int i=num[0];i>=1;i--) {
				num[i+1] += (num[i]*10)/base;
				num[i] = (num[i]*10)%base;
			}
			num[1] = num[1] + ch-48;
			if (num[num[0]+1]) num[0]++;
			ch=getchar();
		}while (isdigit(ch));

		if (num[0]==0) num[0]=1;

	}
	
	void print()
	{
		printf("%d",num[num[0]]);
		for (int i=num[0]-1;i>=1;i--)
		printf("%04d",num[i]);
	}

	void println()
	{
		print();
		putchar('\n');
	}

};



int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	BigInteger n;
	n.read();

	BigInteger l = BigInteger(0) , r = n;
	
	BigInteger two = BigInteger(2);
	
	while (r-1 > l) {
		BigInteger m = (l+r)/two;
		if (m*m < n) l=m; else
		r=m;

	}
	if (r*r < n || r*r==n) r.println(); else
	l.println();

	return 0;
}
