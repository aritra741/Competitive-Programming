#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
#define mod 1000000007
#define mx 200007
using namespace std;

set<int, greater<int> >fire, light;
set<pii>boro;
ll sum, borotelight;

int main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ )
	{
		int tp, val;
		cin >> tp >> val;

		if ( !tp )
		{
			if (val < 0)
			{
				fire.erase(fire.find(-val));

				if ( boro.find(pii(-val, 0)) != boro.end() )
				{
					boro.erase(boro.find(pii(-val, 0)));
					sum-= -val;

					int fireboro = -1;

					if (fire.size())
						fireboro = *(fire.begin());

					int lightboro = -1;

					if (light.size())
						lightboro = *(light.begin());

					if ( lightboro > fireboro )
						boro.insert(pii(lightboro, 1)), borotelight++, light.erase(lightboro), sum+= lightboro;
					else if( fireboro!=-1 )
						boro.insert(pii(fireboro, 0)), fire.erase(fireboro), sum+= fireboro;
				}
			}

			else
			{
				fire.insert(val);

				if (boro.size())
				{
					pii pp = *(boro.begin());

					if (pp.ff <= val)
					{
						boro.erase(boro.find(pp)), sum-= pp.ff, boro.insert(pii(val, 0)), sum+= val, fire.erase(val);

						if (pp.ss)
							borotelight--, light.insert(pp.ff);
						else
							fire.insert(pp.ff);
					}
				}

			}
		}
		elseck
		{
			if (val < 0)
			{
				if(light.find(-val)!=light.end())
					light.erase(-val);

				if (boro.find(pii(-val,1)) != boro.end())
					boro.erase(pii(-val, 1)), borotelight--, sum-= -val;
				else
				{
					pii pp = *(boro.begin());
					boro.erase(pp);
					sum-= pp.ff;
					light.insert(pp.ff);

					if (pp.ss)
						borotelight--;
				}
			}
			else
			{
				light.insert(val);

				int fireboro = -1;

				if (fire.size())
					fireboro = *(fire.begin());

				int lightboro = -1;

				if (light.size())
					lightboro = *(light.begin());

                cout<<lightboro<<" "<<fire.size()<<endl;
				assert( fireboro != -1 or lightboro != -1 );

				if ( lightboro > fireboro )
					boro.insert(pii(lightboro, 1)), sum+= lightboro, light.erase(lightboro), borotelight++;
				else
					boro.insert(pii(fireboro, 0)), sum+= fireboro;
			}
		}


	}
}
