#include<bits/stdc++.h>
#define EPS 1e-9
#define mx 5007
using namespace std;

int sgn(double x) {
    if (fabs(x) < EPS) {
        return 0;
    }
    if (x < 0) {
        return -1;
    }
    return 1;
}

struct PT {
    double x, y;
    PT() {};
    PT(double _x, double _y) {
        x = _x;
        y = _y;
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }

    double operator ^ (const PT &b) const {
        return x * b.y - y * b.x;
    }

    bool operator == (PT b) const {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }

    bool operator < (PT b) const {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : (x < b.x);
    }

    PT operator - (const PT &b) const {
        return PT(x - b.x, y - b.y);
    }

    PT operator + (const PT &b) const {
        return PT(x + b.x, y + b.y);
    }

    PT operator / (const double &k) const {
        return PT(x / k, y / k);
    }

    double operator * (const PT &b) const {
        return x * b.x + y * b.y;
    }

    double distance(PT p) {
        return hypot(x - p.x, y - p.y);
    }

    double len() {
        return hypot(x, y);
    }

    double len2() {
        return x * x + y * y;
    }

    double rad(PT a, PT b) {
        PT p = *this;
        return fabs(atan2( fabs((a - p) ^ (b - p)), (a - p) * (b - p) ));
    }

    PT operator * (const double &k) const {
        return PT(x * k, y * k);
    }

    PT trunc(double r) {
        double l = len();
        if (!sgn(l)) {
            return *this;
        }
        r /= l;
        return PT(x * r, y * r);
    }
};

struct Line {
    PT s, e;
    Line(PT _s, PT _e) {
        s = _s;
        e = _e;
    }

    double length() {
        return s.distance(e);
    }

    double dispointtoline(PT p) {
        return fabs((p - s) ^ (e - s)) / length();
    }

    PT lineprog(PT p) {
        return s + ( ((e - s) * ((e - s) * (p - s))) / ((e - s).len2()) );
    }
};

struct Circle {
    PT p;
    double r;
    Circle() {}

    Circle(PT _p, double _r) {
        p = _p;
        r = _r;
    }

    int pointcrossline(Line v, PT &p1, PT &p2) {
        if (!(*this).relationline(v)) {
            return 0;
        }
        PT a = v.lineprog(p);
        double d = v.dispointtoline(p);
        d = sqrt(r * r - d * d);
        if (sgn(d) == 0) {
            p1 = a;
            p2 = a;
            return 1;
        }
        p1 = a + (v.e - v.s).trunc(d);
        p2 = a - (v.e - v.s).trunc(d);
        return 2;
    }

    int relation(PT b) {
        double dst = b.distance(p);
        if (sgn(dst - r) < 0) {
            return 2;
        }
        else if (sgn(dst - r) == 0) {
            return 1;
        }
        return 0;
    }

    int relationline(Line v) {
        double dst = v.dispointtoline(p);
        if (sgn(dst - r) < 0) {
            return 2;
        }
        else if (sgn(dst - r) == 0) {
            return 1;
        }
        return 0;
    }

    double areatriangle(PT a, PT b) {
        if (sgn((p - a) ^ (p - b)) == 0) {
            return 0.0;
        }
        PT q[5];
        int len = 0;
        q[len++] = a;
        Line l(a, b);
        PT p1, p2;
        if (pointcrossline(l, q[1], q[2]) == 2) {
            if (sgn( (a - q[1]) * (b - q[1]) ) < 0) {
                q[len++] = q[1];
            }
            if (sgn( (a - q[2]) * (b - q[2]) ) < 0) {
                q[len++] = q[2];
            }
        }
        q[len++] = b;
        if (len == 4 && sgn( (q[0] - q[1]) * (q[2] - q[1]) ) > 0) {
            swap(q[1], q[2]);
        }
        double res = 0;
        for (int i = 0; i < len - 1; ++i) {
            if (relation(q[i]) == 0 || relation(q[i + 1]) == 0) {
                double arg = p.rad(q[i], q[i + 1]);
                res += r * r * arg / 2.0;
            }
            else {
                res += fabs((q[i] - p) ^ (q[i + 1] - p)) / 2.0;
            }
        }
        return res;
    }
};

struct Polygon {
    int n;
    PT p[mx];

    void input(int _n) {
        n = _n;
        for (int i = 0; i < n; ++i) {
            p[i].input();
        }
    }

    double areacircle(Circle c) {
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            if (sgn( (p[j] - c.p) ^ (p[i] - c.p) ) >= 0) {
                ans += c.areatriangle(p[i], p[j]);
            }
            else {
                ans -= c.areatriangle(p[i], p[j]);
            }
        }
        return fabs(ans);
    }

    double getarea() {
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (p[i] ^ p[(i + 1) % n]);
        }
        return fabs(sum) / 2;
    }

};

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        int n;
        scanf("%d", &n);

        Polygon pn;
        pn.input(n);

        double area= pn.getarea();

        PT cen;
        scanf("%lf %lf", &cen.x, &cen.y);

        double lagbe;
        scanf("%lf", &lagbe);

        lagbe= (area*lagbe)*0.01;

        double l= 0.0, r= 5000;

        for( int i=1;i<=100;i++ )
        {
            double mid= (l+r)/2;
            Circle c( cen, mid );

            double ekhon= pn.areacircle(c);

            if( ekhon-lagbe<-EPS )
                l= mid;
            else
                r= mid;
        }

        printf("Case %d: %.0f\n", t, r);
    }
}
