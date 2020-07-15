#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s;
    cin>>t;

    int dest=0, til=0, ques=0;
    for(int i=0;i<s.length();i++)
        (s[i]=='+')? dest++ : dest--;
    for(int i=0;i<t.length();i++)
        {
            switch(t[i]){
            case '+':
                til++;
                break;
            case '-':
                til--;
                break;
            default:
                ques++;;
            }
        }

    int rem= abs(dest - til);

    if(rem<=ques){

    int numer=1,denom=1;
    rem+= (ques-rem)/2;
    int it= min(rem, ques-rem);

    for(int i=ques;i>ques-it;i--)
        numer*=i;
    for(int i=it;i>=1;i--)
        denom*=i;

    double poss= (double)numer/(double)denom;

    double all= pow( 2, ques );

    double ans= poss/all;

    cout<<setprecision(12)<<fixed<<ans<<endl;
    return 0;
    }

    cout<<"0.00000000000"<<endl;

}
