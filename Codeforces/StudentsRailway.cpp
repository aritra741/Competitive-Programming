#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    bool flag=0;
	ull n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	ull mx,mn;
	mx=max(a,b);
	mn=min(a,b);
	for(int i=0;i<=n-1;i++)
	{

		if(mx>0 && mn>0)
		{
		    if(s[i]=='.' && i==n-1)
                mx--;
		if(s[i]=='.' && s[i+1]=='.')
			{
				mx--;
				mn--;
				i++;
			}


		else if(s[i]=='.' && s[i+1]=='*')
			mx--;
		}
		else if(mn>0)
			{if(s[i]=='.')
            {
                if(i!=0 && s[i-1]!='.')
                    mn--;
                if(i==0)
                    mn--;
                else
                    break;

            }}
        else if(mx>0 && mn==0)
        {

        if(flag==0)
            {if(s[i]=='.')
            {

                mx--;
                flag=1;
            }}
            else
            {
                if(s[i-1]=='*')
                    mx--;
            }
        }
		else
		break;


	}
	cout<<a+b-mx-mn<<endl;
}
