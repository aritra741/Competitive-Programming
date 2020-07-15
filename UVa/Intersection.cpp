#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x,y;
} base;

bool operator == (point a, point b)
{
    return a.x==b.x and a.y==b.y;
}

int area( point p, point q, point r )
{
    int x[]= {p.x, q.x, r.x};
    int y[]= {p.y, q.y, r.y};

    int a= 0;
    int j= 2;

    for(int i=0; i<3; i++)
    {
        a+=(x[j]+x[i])*(y[j]-y[i]);
        j= i;
    }

    if(a>0)
        return 1;
    if(a<0)
        return 2;
    return 0;
}

bool cmp( const point&a, const point&b )
{
    return area( base, a, b )==2;
}

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        point arr[5];
        point lineA,lineB;
        cin>>lineA.x>>lineA.y>>lineB.x>>lineB.y>>arr[0].x>>arr[0].y>>arr[1].x>>arr[1].y;

        if(arr[0]==arr[1] and lineA==lineB)
        {
            if(lineA==arr[0])
                cout<<"T\n";
            else
                cout<<"F\n";
            continue;
        }

        if(arr[0].x>arr[1].x)
            swap( arr[0].x, arr[1].x );
        if(arr[0].y<arr[1].y)
            swap( arr[0].y, arr[1].y );

        base= arr[0];
        arr[2].x= arr[0].x;
        arr[2].y= arr[1].y;
        arr[3].x= arr[1].x;
        arr[3].y= arr[0].y;

        sort( arr, arr+4, cmp );

        bool intersect= 0;

        arr[4]= arr[0];

        for(int i=0; i<4 and !intersect; i++)
        {
            int pos1= area( arr[i], arr[i+1], lineA );
            int pos2= area( arr[i], arr[i+1], lineB );
            int pos3= area( lineA, lineB, arr[i] );
            int pos4= area( lineA, lineB, arr[i+1] );

            if(pos1!=pos2 and pos3!=pos4)
                intersect= 1;
        }

        if(intersect)
            cout<<"T\n";
        else
        {
            bool inside= 1;

            if(lineA==lineB)
            {
                int low= 1,high= 3;

                while(high-low>1)
                {
                    int mid= (low+high)/2;
                    if( area( arr[0], arr[mid], lineA )==2)
                        low= mid;
                    else
                        high= mid;
                }

                if( area( arr[0], arr[low], lineA )==1 )
                    inside= 0;
                if( area( arr[low], arr[high], lineA )==1 )
                    inside= 0;
                if( area( arr[high], arr[0], lineA )==1 )
                    inside= 0;

                if(inside)
                    printf("T\n");
                else
                    printf("F\n");
                continue;
            }

            set<int> st;
            for(int i=0; i<4 and inside; i++)
            {
                int pos1= area( arr[i], arr[i+1], lineA );
                int pos2= area( arr[i], arr[i+1], lineB );

                st.insert(pos1);
                st.insert(pos2);

            }

            if(st.size()==1)
                cout<<"T\n";
            else
            {
                bool bhitre= 0;
                for(int i=0; i<4 and !bhitre; i++)
                {
                    if( max(lineA.x,lineB.x)<=max( arr[i].x, arr[i+1].x ) and max(lineA.y,lineB.y)<=max( arr[i].y, arr[i+1].y )
                            and min(lineA.x,lineB.x)>=min( arr[i].x, arr[i+1].x ) and min(lineA.y,lineB.y)>=min( arr[i].y, arr[i+1].y ))
                        bhitre= 1;
                }

                if(bhitre)
                    printf("T\n");
                else
                    printf("F\n");
            }
        }

    }
}
