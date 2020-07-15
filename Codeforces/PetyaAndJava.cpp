#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    long long num;
    if(s.length()<19)
    {
        stringstream ss;
        ss<<s;
        ss>>num;
        if(num<=127 && num>=-128)
        {
            cout<<"byte";
            return 0;
        }
        else if(num<=32767 && num>=-32768)
        {
            cout<<"short";
            return 0;
        }
        if(num>=-2147483648 && num<=2147483647)
        {
            cout<<"int";
            return 0;
        }
        else
        {
            cout<<"long";
            return 0;
        }
    }
    else if(s.length()>20)
    {
        cout<<"BigInteger";
        return 0;
    }
    else
    {
        if(s[0]=='-')
        {
            if(s.length()==19)
            {
                cout<<"long";
                return 0;
            }
            else
            {
                string test="9223372036854775808";
                for(int i=1;i<s.length();i++)
                {
                    if(s[i]<test[i-1])
                    {
                        cout<<"long";
                        return 0;
                    }
                    if(s[i]>test[i-1])
                    {
                        cout<<"BigInteger";
                        return 0;
                    }

                }
                cout<<"long";
            }
        }
        else
        {
            string test="9223372036854775807";
            for(int i=0;i<s.length();i++)
                {
                    if(s[i]<test[i])
                    {
                        cout<<"long";
                        return 0;
                    }
                    if(s[i]>test[i])
                    {
                        cout<<"BigInteger";
                        return 0;
                    }

                }
                cout<<"long";
        }

    }



}
