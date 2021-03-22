#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define P mod
using namespace std;

struct NTT {
    vector<int>A, B, w[2], rev;
    int M, G = 3;
    int Pow(int a, int b) {
        int res=1;
        for (;b; b>>=1,a=a*1LL*a%P) if (b&1) res=res*1LL*a%P;
        return res;
    }
    void init( int n ) {
        for (M=1; M<n; M<<=1);
        M<<=1;
        A.resize(M); B.resize(M);
        w[0].resize(M); w[1].resize(M);
        rev.resize(M);
        for (int i=0; i<M; i++) {
            int x=i, &y=rev[i];
            y=0;
            for (int k=1; k<M; k<<=1,x>>=1)
                (y<<=1)|=x&1;
        }
        int x=Pow(G,(P-1)/M),y=Pow(x,P-2);
        w[0][0]=w[1][0]=1;
        for (int i=1; i<M; i++) {
            w[0][i]=w[0][i-1]*1LL*x%P;
            w[1][i]=w[1][i-1]*1LL*y%P;
        }
    }
    void ntransform(vector<int> &a, int f) {
        for (int i=0; i<M; i++)
            if (i<rev[i]) swap(a[i],a[rev[i]]);
        for (int i=1; i<M; i<<=1)
            for (int j=0,t=M/(i<<1); j<M; j+=i<<1)
                for (int k=0,l=0; k<i; k++,l+=t) {
                    int x=a[j+k+i]*1ll*w[f][l]%P;
                    int y=a[j+k];
                    a[j+k+i]=y-x<0?y-x+P:y-x;
                    a[j+k]=y+x>=P?y+x-P:y+x;
                }
        if (f) {
            int x=Pow(M,P-2);
            for (int i=0; i<M; i++) a[i]=a[i]*1ll*x%P;
        }
    }
 
    void multiply( vector<int> &X, vector<int> &Y,
                  vector<int> &res) {
        init(max(X.size(), Y.size()));
        for( int i = 0; i < M; i++ ) A[i] = B[i] = 0;
        for( int i = 0; i < X.size(); i++ ) A[i] = X[i];
        for( int i = 0; i < Y.size(); i++ ) B[i] = Y[i];
        ntransform(A,0); ntransform(B,0);
        res.clear(); res.resize(M);
        for (int i=0; i<M; i++)
            res[i]=A[i]*1LL*B[i]%P;
        ntransform(res,1);
    }
    int bigMod(int x, int y) {
        int res = 1;
        while(y) {
            if(y & 1) res = 1ll*res*x%P;
            y >>= 1;
            x = 1ll*x*x%P;
        }
        return res;
    }
    void power(vector<int> &X, int n, vector<int> &res) { // X^n
        int deg = X.size()-1;
        deg = n * deg;
        init(deg + 1);
        for(int i = 0; i <= deg; i++) {
            if(i < X.size()) A[i] = X[i];
            else A[i] = 0;
        }
        ntransform(A,0);
        res.clear(); res.resize(M);
        for(int i = 0; i < M; i++) res[i] = bigMod(A[i], n);
        ntransform(res,1);
    }
};
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	n /= 2;

	int arr[k + 5];
	std::vector<int> v(11, 0);

	for ( int i = 0; i < k; i++ )
		cin >> arr[i], v[arr[i]]++;

	NTT ntt;
	vector<int>res;

	ntt.power( v, n, res );

	ll ans = 0;

	for ( auto x : res )
		ans = (ans + (1LL * x * x) % mod) % mod;

	cout <<	ans	<< "\n";
}
