#include <bits/stdc++.h>
using namespace std;


//kmp
const static int mx = 1000010;
char s[mx], ss[mx];
int lps[mx];
void build_lps(int n)
{
	lps[0] = 0;
	for (int i = 1; i < n; i++)
	{
		int j = lps[i - 1];
		while (j > 0 && s[i] != s[j])j = lps[j - 1];
		if (s[i] == s[j])j++;
		lps[i] = j;
	}
}
int find_occ(int n, int m) //pattern length, text length
{
	build_lps(n);
	int i = 0, j = 0, c = 0;
	while (j < m)
	{
		if (s[i] == ss[j])
		{
			i++, j++;
			if (i == n)c++, i = lps[i - 1];
		}
		else
		{
			if (i == 0)j++;
			else i = lps[i - 1];
		}
	}
	return c;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case %d: \n", i);
		scanf("%s %s", ss, s);
		printf("%d\n", find_occ(strlen(s), strlen(ss)));
	}
	return 0;
}