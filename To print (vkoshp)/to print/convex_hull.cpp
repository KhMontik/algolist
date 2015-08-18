#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

#define N 21000
#define sqr(n) (n) * (n)

double perimetr;
int n, i, m, top = -1;

struct pt // point
{
	int x, y;
	double w; // angle
} p[N];

double dist(pt a, pt b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

bool cmp(pt a, pt b)
{
	return a.w < b.w || a.w == b.w && dist(p[0], a) < dist(p[0], b);
}

bool ccw(pt a, pt b, pt c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) <= 0;
}

int main()
{
	freopen("convex.in", "r", stdin);
	freopen("convex.out", "w", stdout);
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
		if (p[m].y > p[i].y || p[m].y == p[i].y && p[m].x > p[i].x) m = i;
	}

	swap(p[0], p[m]);

	for (i = 0; i < n; i++)
		p[i].w = atan2(p[i].y - p[0].y, p[i].x - p[0].x);

	sort(p + 1, p + n, cmp);

	p[n] = p[0];

	for (i = 0; i <= n; i++)
	{
                while (i > 1 && i != n && top && ccw(p[top - 1], p[top], p[i])) top--;
		p[++top] = p[i];
	}

	for (i = 0; i < top; i++) perimetr += dist(p[i], p[i + 1]);

	printf("%.10lf", perimetr);
}
