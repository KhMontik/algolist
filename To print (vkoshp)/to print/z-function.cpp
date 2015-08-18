void calc_z (const char * s, vector<int> & z)
{
	int len = (int) strlen (s);
	z.resize (len);

	int l = 0, r = 0;
	for (int i=1; i<len; ++i)
		if (z[i-l]+i <= r)
			z[i] = z[i-l];
		else
		{
			l = i;
			if (i > r) r = i;
			for (z[i] = r-i; r<len; ++r, ++z[i])
				if (s[r] != s[z[i]])
					break;
			--r;
		}
}