#include <bits/stdc++.h>
using namespace std;

void printstack(stack <string> gq)
{
    stack <string> g = gq;
    while (!g.empty())
    {
        cout << '\n' << g.top();
        g.pop();
    }
    cout << '\n';
}


int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        printf("Case %d:\n", i);
        stack <string> prev, next;
        prev.push("http://www.lightoj.com/");
        while(1){
        string s;
        cin>>s;
        string u;

        if(s=="VISIT")
        {
            cin>>u;
            prev.push(u);
            next=stack<string>();
            cout<<u<<endl;
        }
        else if(s=="BACK")
        {
            if(prev.empty())
                printf("Ignored\n");
            else{

            string t=prev.top();
            prev.pop();
            next.push(t);
            if(prev.empty())
                {
                    printf("Ignored\n");
                    prev.push(t);
                    next.pop();
                }
            else
            cout<<prev.top()<<endl;

            }
        }
        else if(s=="FORWARD")
        {
            if(next.empty())
                printf("Ignored\n");
            else{
            string t=next.top();
            next.pop();
            prev.push(t);
            cout<<t<<endl;
            }

        }
        else
            break;
        }

    }

}
