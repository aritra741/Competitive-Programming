void Man(string &S,bool T)
{
    n=S.size();
    for(int i=0,l=0,r=-1; i<n; i++)
    {
        int k=(i>r)?T:min(d[T][l+r-i+!T],r-i+1);
        while(0<=i-k-!T&&i+k<n&&S[i-k-!T]==S[i+k])
            k++;
        d[T][i]=k--;
        if(i+k>r)
        {
            l=i-k-!T;
            r=i+k;
        }
    }
}
