#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
template<class T>
class matrix
{
    typedef vector<vector<T>> mat;
public:
    mat I;
    matrix() {}
    matrix(int n)
    {
        vector<T> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            v[i] = 1;
            I.push_back(v);
            v[i] = 0;
        }
    }
    matrix(int r, int c, T val)
    {
        I.resize(r, vector<T> (c, val));
    }
    matrix(mat v)
    {
        I = v;
    }
    ~matrix()
    {
        I.clear();
    }
    inline void print()
    {
        for (int i = 0; i < I.size(); i++)
        {
            for (int j = 0; j < I[0].size(); j++)
                cout << I[i][j] << ' ';
            cout << endl;
        }
    }
    inline void push_back(vector<T> v)
    {
        I.push_back(v);
    }
    inline void push_back(int ind,int val)
    {
        I[ind].push_back(val);
    }
    inline matrix operator + (matrix const &obj)
    {
        assert(I.size() == obj.I.size() && I[0].size() == obj.I[0].size());
        matrix temp;
        for (int i = 0; i < I.size(); i++)
        {
            vector<T> v;
            for (int j = 0; j < I[0].size(); j++)
            {
                if(mod!=0)
                    v.push_back((I[i][j] + obj.I[i][j])%mod);
            }
            temp.I.push_back(v);
        }
        return temp;
    }
    inline void operator = (const matrix & obj )
    {
        I = obj.I;
    }
    inline matrix operator * (matrix const &obj)
    {
        assert(I[0].size() == obj.I.size());
        matrix temp(I.size(), obj.I[0].size(), 0);
        for (int i = 0; i < I.size(); i++)
        {
            for (int j = 0; j < obj.I[0].size(); j++)
            {
                for (int k = 0; k < I[0].size(); k++)
                {
                    temp.I[i][j] += I[i][k] * obj.I[k][j];
                    temp.I[i][j] %= mod;
                }
            }
        }
        return temp;
    }
    inline matrix operator * (T const &obj)
    {
        matrix temp(I.size(), I[0].size(), 0);
        for (int i = 0; i < I.size(); i++)
        {
            for (int j = 0; j < I[0].size(); j++)
            {
                temp.I[i][j] = I[i][j] * obj;
                temp.I[i][j] %= mod;
            }
        }
        return temp;
    }
    inline matrix operator % (T const &obj)
    {
        matrix temp=I;
        for (int i = 0; i < I.size(); i++)
        {
            for (int j = 0; j < I[0].size(); j++)
            {
                temp.I[i][j] = temp.I[i][j] % obj;
            }
        }
        return temp;
    }
};

template<class TT>
inline TT Pow(TT a, long long b)
{
    TT x=a,ret=TT(a.I.size());
    while(b>0)
    {
        if(b&1)
            ret=(ret*x)%mod;
        x=(x*x)%mod;
        b>>=1;
    }
    return ret;
}

int main()
{
    matrix<ll> arr,brr;
    brr.push_back({1});
    brr.push_back({1});
    brr.push_back({1});

    arr.push_back({1,4,7});
    arr.push_back({2,5,8});
    arr.push_back({3,6,9});

    int t;
    scanf("%d",&t);
    for(int I=1; I<=t; I++)
    {
        int n;
        scanf("%d", &n);
        n--;

        matrix<ll>qq= arr;
        qq=Pow(qq,n);
        qq=(qq*brr)%mod;
        printf("%lld\n", (qq.I[0][0]+qq.I[1][0]+qq.I[2][0])%mod );
    }
    return 0;
}



