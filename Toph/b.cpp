#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost; // set
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset; // multiset
*/
// direction array
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
// Bitmask

bool check(int mask,int pos){return mask&(1<<pos);}
int SET(int mask,int pos){return mask|(1<<pos);}
int FLIP(int mask,int pos){return mask^(1<<pos);}
int reset(int mask,int pos){return mask&~(1 << pos);}

const int OFFSET=(1<<15);

string str;
int tt=1,n,total;
int arr[50];
int dp[31][16][OFFSET*2+5];
int vis[31][16][OFFSET*2+5];

int dp2[31][16][7000];
int vis2[31][16][7000];

int score(int i,int baki,int sum)
{
	if(i==str.size()){
		return baki==(str.size()/2) && sum==OFFSET;
	}
	int &ret=dp[i][baki][sum];
	int &memo=vis[i][baki][sum];
	if(memo==tt){
		return ret;
	}
	memo=tt;
	ret=0;
	if(baki<(str.size()/2)){
		ret=ret+score(i+1,baki+1,sum+SET(1,baki)*(str[i]-'0'));
	}
	if(i-baki<(str.size()/2)){
		ret=ret+score(i+1,baki,sum-SET(1,i-baki)*(str[i]-'0'));
	}
	return ret;
}


int solve(int i,int baki,int sum)
{
	if(i==2*n){
		if(baki==n){
			return abs(total-2*sum);
		}
	}
	int &ret=dp2[i][baki][sum];
	int &memo=vis2[i][baki][sum];
	if(memo==tt){
		return ret;
	}
	memo=tt;
	ret=1e9;
	if(baki<n)
		ret=min(ret,solve(i+1,baki+1,sum+arr[i]));
	if(i-baki<n)
		ret=min(ret,solve(i+1,baki,sum));
	return ret;
}

vector<int>allsum[35];

int main()
{
	FAST
	int t;
	cin>>t;

	while(t--){
		cin>>n;
		total=0;
		for(int i=0;i<2*n;i++){
			cin>>str;
			reverse(str.begin(),str.end());
			arr[i]=score(0,0,OFFSET);
			total+=arr[i];
			tt++;
			// cout<<arr[i]<<endl;
		}
		for(int mask=0;mask<(1<<n);mask++){
			int sum1=0,sum2=0,cnt=0;
			for(int i=0;i<n;i++){
				if(check(mask,i)){
					sum1+=arr[i]
					cnt++;
				}else{
					sum2+=arr[i];
				}
			}
			allsum[cnt].push_back(sum1-sum2);
		}
		for(int mask=0;mask<(1<<n);mask++){
			int sum1=0,sum2=0,cnt=0;
			for(int i=0;i<n;i++){
				if(check(mask,i)){
					sum1+=arr[n+i]
					cnt++;
				}else{
					sum2+=arr[n+i];
				}
			}
			int sum=sum1-sum2;
			
		}
		tt++;
	}
}