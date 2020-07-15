#include <bits/stdc++.h>
#define mx 100007
using namespace std;

int l, l1, l2;
int pre[2*mx];
string s,s1;

void precal()
{
    int q= -1;

    for( int i=1; i<l2; i++ )
    {
        while(q>-1 and s[q+1]!=s[i])
            q= pre[q];
        if( s[q+1]==s[i] )
            q++;
        pre[i]= q;
    }
}

int find_occ(int mid, int m)
{
	int i = 0, j = l, c = 0;
	while (j < m)
	{
		if (s[i] == s[j])
		{
			i++, j++;
			if (i == mid)c++, i = pre[i - 1]+1;
		}
		else
		{
			if (i == 0)j++;
			else i = pre[i - 1]+1;
		}
	}
	return c;
}

int main()
{
    memset( pre, -1, sizeof(pre) );

    getline(cin,s1);
    getline(cin,s);

    int k;
    cin>>k;

    l= s.size();
    s.push_back(1);
    l1= s1.size();

    for( int i=0; i<l1; i++ )
        s.push_back(s1[i]);

    l2= s.size();

    precal();

    int low= 1, high= l;

    int out= -1;
    while(high>low+3)
    {
        int qq= (low+high)/2;

        int cnt= find_occ( qq, l2 );

        if( cnt>=k )
            out= qq, low= qq+1;
        else
            high= qq-1;
    }

    for( int qq=low;qq<=high;qq++ )
    {
        int cnt= find_occ(qq,l2);

        if( cnt>=k )
            out= qq;
    }

    if(out==-1)
        return cout<<"IMPOSSIBLE"<<endl, 0;

    for( int i=0; i<out; i++ )
        cout<<s[i];
}
