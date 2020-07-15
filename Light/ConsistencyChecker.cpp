#include <bits/stdc++.h>
using namespace std;

bool flag=0;

struct node
{
    bool ending;
    node* next[10];
    node()
    {
        ending=false;
        for(int i=0;i<10;i++)
            next[i]=NULL;
    }
}*root;

void Insert(char *str, int len)
{
    node *curr=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-48;
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->ending=true;
}

void result(char *str, int len)
{
    node* curr=root;
    for(int i=0;i<len-1;i++)
    {
        int id=str[i]-48;
        curr=curr->next[id];
        if(curr->ending==true)
            {
                flag=1;
                return;
            }
    }
    int id=str[len-1]-48;
    curr=curr->next[id];
    for(int i=0;i<10;i++)
    {
        if(curr->next[i]!=NULL)
            {
                flag=1;
                return;
            }
    }

}

void del(node* curr)
{
    for(int i=0;i<10;i++)
    {
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}

int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        flag=0;
        root=new node();

        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            char str[15];
            cin>>str;
            int len=strlen(str);
            Insert(str, len);
            result(str, len);
        }
        del(root);
        if(flag==0)
            printf("Case %d: YES\n", t);
        else
            printf("Case %d: NO\n", t);
    }
}
