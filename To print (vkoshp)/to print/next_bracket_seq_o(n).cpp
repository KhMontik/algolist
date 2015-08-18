#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string s, ans;
int i, k, n, c1, c2;

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> s; n = s.length();
	string ans = "No Solution";
	for (i = n - 1, c1 = 0, c2 = 0; i >= 0; i--)
	{
		if (s[i] == '(')
			c1++;
		else
			c2++;
		if (s[i] == '(' && c1 < c2)
		{
			ans = s.substr(0, i) + ')';
			for (k = 0; k < c1; k++) ans += '(';
			for (k = 1; k < c2; k++) ans += ')';
			break;
		}
	}
	cout << ans;
}
