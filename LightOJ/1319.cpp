#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ext_gcd ( ll A, ll B, ll *X, ll *Y ) {
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}


/**
    A CRT solver which works even when moduli are not pairwise coprime
    1. Add equations using addEquation() method
    2. Call solve() to get {x, N} pair, where x is the unique solution modulo N.
    Assumptions:
        1. LCM of all mods will fit into long long.
*/
class ChineseRemainderTheorem {
    typedef long long vlong;
    typedef pair<vlong, vlong> pll;

    /** CRT Equations stored as pairs of vector. See addEqation()*/
    vector<pll> equations;

public:
    ChineseRemainderTheorem()
    {}
    void clear() {
        equations.clear();
    }

    /** Add equation of the form x = r (mod m)*/
    void addEquation( vlong r, vlong m ) {
        equations.push_back({r, m});
    }
    pll solve() {
        if (equations.size() == 0) return { -1, -1}; /// No equations to solve

        vlong a1 = equations[0].first;
        vlong m1 = equations[0].second;
        a1 %= m1;
        /** Initially x = a_0 (mod m_0)*/

        /** Merge the solution with remaining equations */
        for ( int i = 1; i < equations.size(); i++ ) {
            vlong a2 = equations[i].first;
            vlong m2 = equations[i].second;

            vlong g = __gcd(m1, m2);
            if ( a1 % g != a2 % g ) return { -1, -1}; /// Conflict in equations

            /** Merge the two equations*/
            vlong p, q;
            ext_gcd(m1 / g, m2 / g, &p, &q);

            vlong mod = m1 / g * m2;
            vlong x = ( (__int128)a1 * (m2 / g) % mod * q % mod + (__int128)a2 * (m1 / g) % mod * p % mod ) % mod;

            /** Merged equation*/
            a1 = x;
            if ( a1 < 0 ) a1 += mod;
            m1 = mod;
        }
        return {a1, m1};
    }
};

ChineseRemainderTheorem CRT;

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t=1;t<=tc;t++)
    {
        CRT.clear();

        int n;
        scanf("%d", &n);

        for( int i=0;i<n;i++ )
        {
            int r, p;
            scanf("%d %d", &r, &p);

            CRT.addEquation(p,r);
        }

        printf("Case %d: ", t);

        ll ans= CRT.solve().first;

        if(ans<0)
            printf("Impossible\n");
        else
            printf("%lld\n", ans);
    }
}