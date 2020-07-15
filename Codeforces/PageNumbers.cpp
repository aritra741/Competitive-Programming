#include <bits/stdc++.h>
using namespace std;
set <int> num;
vector <int> arr;

int main()
{
    bool flag=0;
    string s,t="";
    cin>>s;
    stringstream ss;
    ss<<s;
    while(getline(ss,t,','))
    {
        num.insert(stoi(t));
    }
    int init,fin;
    arr.assign(num.begin(), num.end());
    for(int i=0;i<arr.size();i++)
    {

        if(arr[i+1]-arr[i]==1)
        {if(i!=0)cout<<","<<arr[i]<<"-";
           else cout<<arr[i]<<"-";
            while(1)
            {
                if(arr[i+1]-arr[i]!=1 || i==arr[arr.size()-1])
                {cout<<arr[i];
                    break;}
                    else i++;
            }
        }
        else if(i!=0)cout<<","<<arr[i];
        else cout<<arr[i];

    }




}
