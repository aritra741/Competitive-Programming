#include <bits/stdc++.h>
#define ull unsigned long long
#define pii pair<int, int>
#define mx 80000007
using namespace std;

//vector < pii > v;
//
//vector<ull> sum(mx);
//vector<ull> ::iterator it;

//void pre()
//{
//    sum[0]=0;
//
//    for(int i=1; i<mx; i++)
//        sum[i]=sum[i-1]+i;
//}

int main()
{
    cout<<"         6         8"<<endl
        <<"        35        49"<<endl
        <<"       204       288"<<endl
        <<"      1189      1681"<<endl
        <<"      6930      9800"<<endl
        <<"     40391     57121"<<endl
        <<"    235416    332928"<<endl
        <<"   1372105   1940449"<<endl
        <<"   7997214  11309768"<<endl
        <<"  46611179  65918161"<<endl;         ///The brute force code is in the comments


//    pre();
//    int cnt=0;
//    ull prevnum=0;
//
//    for(int i=1; i<mx; i++)
//    {
//        if(cnt>=10)
//            break;
//
//        ull tot= sum[i];
//
//        tot/=2;
//
//        if(tot<5)
//            continue;
//
//        it= lower_bound( sum.begin(), sum.end(), tot  );
//        int pos= it- sum.begin();
//
//        if(sum[pos]!=tot)
//            pos--;
//
//        if( sum[pos]== (sum[i]-sum[pos+1]) ){
//            cout<<"\""<<setw(10)<<pos+1<<setw(10)<<i<<"\"<<endl"<<endl;
//        cnt++;
//        }
//    }

}
