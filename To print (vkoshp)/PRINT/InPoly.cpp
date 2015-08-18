// In polygon?
struct pt {
    int x, y;
    void in () {
        scanf ("%d %d", &x, &y);
    }
} t, p[21200];
int n;

int VM (pt a, pt b, pt c) {
	int d = (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
	if (d > 0)	return 1;
	if (d == 0)	return 0;
	return 2;
}
bool inpoly (pt a) {
	int d, v = VM (p[0], p[1], a);
	if (v == 0)	return 0;

	for (int i = 2; i < n; i+=2) {
		d = VM (p[i-1], p[i], a);
		if (d != v)	return 0;
	}

	d = VM (p[n-1], p[0], a);
	if (d != v)	return 0;
	return 1;
}