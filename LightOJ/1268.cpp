#include <bits/stdc++.h>
#define int unsigned int
#define ll long long
using namespace std;

struct matrix
{
	int mat[55][55];
	int row, col;

	matrix()
	{
//        memset(mat,0,sizeof mat);
	}
	matrix(int a, int b)
	{
		row = a, col = b;
		memset(mat, 0, sizeof mat);
	}

	matrix operator*(const matrix &p) const
	{
		assert(col == p.row);
		matrix temp;
		temp.row = row;
		temp.col = p.col;
		for (int i = 0; i < temp.row; i++)
		{
			for (int j = 0; j < temp.col; j++)
			{
				int sum = 0;
				for (int k = 0; k < col;  k++)
				{
					sum += ((mat[i][k]) * (p.mat[k][j]));
					// sum %= MOD;
				}
				temp.mat[i][j] = sum;
			}
		}
		return temp;
	}
	matrix operator+ (const matrix &p) const
	{
		assert(row == p.row && col == p.col);
		matrix temp;
		temp.row = row;
		temp.col = col;
		for (int i = 0; i < temp.row; i++)
		{
			for (int j = 0; j < temp.col; j++)
				temp.mat[i][j] = ((mat[i][j]) + (p.mat[i][j]));
		}
		return temp;
	}

	matrix identity()
	{
		matrix temp;
		temp.row = row;
		temp.col = col;
		memset(temp.mat, 0, sizeof(temp.mat));

		for (int i = 0; i < row; i++)
			temp.mat[i][i] = 1;
		return temp;
	}

	void show()
	{
//        printf("-----------------------------\n");
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				printf("%d ", mat[i][j]);
			printf("\n");
		}
//        printf("-----------------------------\n");
	}

};

matrix pow(matrix a, ll p)
{
	matrix ret(a.row, a.col);
	ret = ret.identity();
	while (p)
	{
		if (p & 1)ret = (ret * a);
		a = (a * a);
		p >>= 1;  
	}
	return ret;
}



//kmp
const static int mx = 55;
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

std::vector<char> v;

int build_automata_solve(int m)
{
	int n = strlen(s);

	matrix mat(n + 5, n + 5), adj(n + 5, n + 5);

	for ( int i = 0; i < n; i++ )
		for ( auto c : v )
		{
			if ( i and s[i] != c )
				mat.mat[i][c - 'a'] = mat.mat[lps[i - 1]][c - 'a'];
			else
				mat.mat[i][c - 'a'] = i + (s[i] == c);

			// cout<<i<<" "<<c<<" "<<mat.mat[i][c - 'a']<<endl;
		}

	for ( int i = 0; i < n; i++ )
		for ( auto c : v )
			adj.mat[i][mat.mat[i][c - 'a']]++;
	
	adj.mat[n - 1][n] = 0;
	// adj.show();
	adj = pow(adj, m);
	int ans= 0;

	for ( int i = 0; i <= n; i++ )
		ans+= adj.mat[0][i];

	return ans;
}

int32_t main()
{
	int tc;
	scanf("%d", &tc);

	for ( int t = 1; t <= tc; t++ )
	{
		int n;
		scanf("%d", &n);

		scanf("%s", s);
		v.clear();

		int x = strlen(s);

		for ( int i = 0; i < x; i++ )
			v.push_back(s[i]);

		scanf("%s", s);

		memset(lps, 0, sizeof(lps));
		build_lps(strlen(s));
		int ans= build_automata_solve(n);

		printf("Case %d: %u\n", t, ans);
	}
}
