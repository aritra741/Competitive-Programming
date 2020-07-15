#include <bits/stdc++.h>
#define ll long long
using namespace std;

string multiply(string str1, string str2){
    int sign = 1;
    if (str1[0] == '-') {
       sign = sign * (-1);
       str1.erase(str1.begin());
    }

    if (str2[0] == '-') {
       sign = sign * (-1);
       str2.erase(str2.begin());
    }
    int m=str1.length(),n=str2.length();

    int pos[m+n+1]={0};
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int mul=(str1[i]-'0')*(str2[j]-'0');
            int p1=i+j,p2=i+j+1;
            int sum=abs(mul)+abs(pos[p2]);
            pos[p1]+=sum/10;
            pos[p2]=sum%10;
        }
    }
    string sb;
    for(int i=0;i<m+n;i++)if(!(sb.length()==0 and pos[i]==0))sb+=to_string(pos[i]);
    if(sb.length()==0)return "0";
    if (sign == -1)
        sb.insert(sb.begin(), '-');
    return sb;
}

string Max( string s, string t )
{
    if(s.size()>t.size() and s[0]!='-')
        return s;
    if(t.size()>s.size() and t[0]!='-')
        return t;
    if(s[0]!='-' and t[0]=='-')
        return s;
    if(s[0]=='-' and t[0]!='-')
        return t;

    if(s[0]=='-')
    {
        for(int i=1;i<s.size();i++)
        {
            if( s[i]>t[i] )
                return t;
            if(t[i]>s[i])
                return s;
        }
    }

    else
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>t[i])
                return s;
            if(t[i]>s[i])
                return t;
        }
    }

    return s;

}

string Min( string s, string t )
{
    if(s.size()>t.size() and s[0]!='-')
        return t;
    if(t.size()>s.size() and t[0]!='-')
        return s;
    if(s[0]!='-' and t[0]=='-')
        return t;
    if(s[0]=='-' and t[0]!='-')
        return s;
    if(s[0]=='-' and t[0]=='-')
    {
        if(t.size()>s.size())
            return t;
        if(s.size()>t.size())
            return s;
    }
    if(s[0]=='-')
    {
        for(int i=1;i<s.size();i++)
        {
            if( s[i]>t[i] )
                return s;
            if(t[i]>s[i])
                return t;
        }
    }

    else
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>t[i])
                return t;
            if(t[i]>s[i])
                return s;
        }
    }

    return t;

}

vector<string> v(107);

int main()
{
    string s;
    int i= 0;

    while(cin>>s)
    {
        v[i++]= s;
        while(1)
        {
            cin>>s;
            v[i++]= s;
            if(s=="-999999")
                break;
        }

        int n= i-1;

        string prevmx= v[0], prevmn= v[0], mx= v[0];
        string currmx= v[0], currmn= v[0];

        for(int i=1;i<n;i++)
            currmx= Max( v[i], Max(multiply(prevmx,v[i]), multiply(prevmn,v[i]) )),
            currmn= Min( v[i], Min(multiply(prevmx,v[i]), multiply(prevmn,v[i])) ),
            mx= Max( mx, Max(currmx,currmn) ),
            prevmx= currmx, prevmn= currmn;

        cout<< mx <<endl;
        v.clear();
        i= 0;
    }
}
