#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct PT{
    double x, y;
    PT(){x = y = 0; }
    PT(double _x, double _y) {x = _x, y = _y; }
    PT operator-(const PT &a) const{
        return PT(x - a.x, y - a.y);
    }
    PT operator+(const PT &a) const{
        return PT(x + a.x, y + a.y);
    }
    PT operator*(double a) const{
        return PT(x * a, y * a);
    }
    PT operator/(double a) const{
        return PT(x / a, y / a);
    }
    double val()
    {
        return sqrt(x * x + y * y);
    }
    PT unit()
    {
        return (*this) / val();
    }
    void scan()
    {
        scanf("%lf %lf", &x, &y);
    }
    void print()
    {
        printf("(%.10f, %.10f)", x, y);
    }
};

vector<PT>ret(10007), p;

double dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}
double dist2(PT p, PT q)
{
    return dot(p-q,p-q);
}
double distPoint(PT p, PT q)
{
    return sqrt(dot(p-q,p-q));
}
double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}

int sign( PT p, PT q, PT r )
{
    double val= (q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);

    val=-val;

    if(val<0)
        return 1;
    if(val>0)
        return 2;
    return 0;
}

bool cmp( PT a, PT b )
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

void bord()
{
    int k=0, n= p.size();
    sort(p.begin(),p.end(),cmp);

    for(int i=0; i<n; i++)
    {
        while(k>=2 and sign(ret[k-2], ret[k-1], p[i])!=2)
            k--;
        ret[k++]= p[i];
    }
    int t= k;
    for(int i=n-2; i>=0; i--)
    {
        while(k>t and sign( ret[k-2], ret[k-1], p[i] )!=2)
            k--;
        ret[k++]= p[i];
    }

    ret.resize(k-1);
}

int main()
{
    while(1)
    {
        int n;
        scanf("%d", &n);

        if(!n)
            return 0;

        p.resize(n);

        for( int i=0;i<n;i++ )
            p[i].scan();

        if(n<3)
        {
            printf("0.0000\n");
            continue;
        }

        ret.resize(n+7);
        bord();

        if( ret.size()<3 )
        {
            printf("0.0000\n");
            continue;
        }

        int i= 0, j= 1, i2= 1, j2= 1;
        double ans =4e18;

        n= ret.size();

        for( ;i<n;i++ )
        {
            while( cross( ret[(i+1)%n]-ret[i], ret[j]-ret[i] )<=cross( ret[(i+1)%n]-ret[i], ret[(j+1)%n]-ret[i] ) )
                j= (j+1)%n;
            while( dot( ret[(i+1)%n]-ret[i], ret[i2]-ret[i] )<=dot( ret[(i+1)%n]-ret[i], ret[(i2+1)%n]-ret[i] ) )
                i2= (i2+1)%n;
            if(!i)
                j2= i2;
            while( dot( ret[(i+1)%n]-ret[i], ret[j2]-ret[i] )>=dot( ret[(i+1)%n]-ret[i], ret[(j2+1)%n]-ret[i] ) )
                j2= (j2+1)%n;

            double a= cross( ret[(i+1)%n]-ret[i], ret[j]-ret[i] );
            double b= (dot( ret[(i+1)%n]-ret[i], ret[i2]-ret[i] )-dot( ret[(i+1)%n]-ret[i], ret[j2]-ret[i] ));
            double len_squared= dot( ret[(i+1)%n]-ret[i], ret[(i+1)%n]-ret[i] );
            double area= (a*b)/len_squared; /// dividing by len_squared will yield the area, because it unnecessarily occurs twice
            ans= min( ans, area );
        }

        printf("%.4f\n", ans);
    }
}
