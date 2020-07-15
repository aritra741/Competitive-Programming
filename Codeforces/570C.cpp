#include<bits/stdc++.h>
#define pii pair<int,int>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update> tt;

tt st;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin>>n>>q;

    string s;
    cin>>s;

    int cnt= 0, ss= -1;
    int ans= 0;

    for( int i=0; i<n; i++ )
    {
        if( s[i]=='.' )
        {
            cnt++;
            if(cnt==1)
                ss= i;
        }
        else if( cnt )
            ans+= cnt-1, st.insert( pii( ss, cnt ) ), cnt= 0;
    }

    if( cnt )
        ans+= cnt-1, st.insert( pii( ss, cnt ) ), cnt= 0;

    while(q--)
    {
        int pos;
        char c;

        cin>>pos>>c;

        pos--;

        if( s[pos]!='.' and c!='.' )
        {
            cout<<ans<<"\n";
            continue;
        }
        if( s[pos]=='.' and c=='.' )
        {
            cout<<ans<<"\n";
            continue;
        }

        int pp= st.size();

        if( c=='.' )
        {
            int koto= st.order_of_key( pii(pos,0) );

            pii agey_shuru;
            if(koto)
                agey_shuru= (*st.find_by_order(koto-1));
            else
                agey_shuru= pii(-1,-1);

            bool f= 0, agey= 0;

            if( agey_shuru.first!=-1 )
            {
                agey= 1;
                if( agey_shuru.second+agey_shuru.first-1==pos-1 )
                {
                    koto= st.order_of_key( pii(pos,0) );

                    pii pore_shuru;
                    if(koto<st.size())
                        pore_shuru= (*st.find_by_order(koto));
                    else
                        pore_shuru= pii(-1,-1);

                    if( pore_shuru.first==pos+1 )
                    {
                        f= 1;
                        st.erase( pore_shuru );
                        st.erase( agey_shuru );
                        ans-= agey_shuru.second-1;
                        ans-= pore_shuru.second-1;
                        st.insert( pii( agey_shuru.first, agey_shuru.second+pore_shuru.second+1 ) );
                        ans+= agey_shuru.second+pore_shuru.second;
                    }
                    else
                    {
                        st.erase( agey_shuru );
                        ans-= agey_shuru.second-1;
                        st.insert( pii( agey_shuru.first, agey_shuru.second+1 ) );
                        ans+= agey_shuru.second;
                    }
                }
            }

            if(!f)
            {
                koto= st.order_of_key( pii(pos,0) );
                pii pore_shuru;
//                cout<<" "<<koto<<" "<<st.size()<<endl;
                if(koto<st.size())
                    pore_shuru= (*st.find_by_order(koto));
                else
                    pore_shuru= pii(-1,-1);

                if( pore_shuru.first==pos+1 )
                {
                    ans-= pore_shuru.second-1;
                    st.erase( pore_shuru );
                    ans+= pore_shuru.second;
                    st.insert( pii( pos, pore_shuru.second+1 ) );
                }
            }

            if( st.empty() )
                st.insert( pii( pos, 1 ) );
            else
            {
                if( !pos and pos+1<n and s[pos+1]!='.' )
                    st.insert( pii(pos,1) );
                else if( pos==n-1 and pos-1>-1 and s[pos-1]!='.' )
                    st.insert( pii(pos,1) );
                else if( pos>0 and pos<n-1 and s[pos-1]!='.' and s[pos+1]!='.' )
                    st.insert( pii(pos,1) );
            }
        }
        else
        {
            int koto= st.order_of_key( pii( pos, n+5 ) );

            pii agey_shuru= *( st.find_by_order( koto-1 ) );
//                cout<<"ekhon "<<koto<<" "<<agey_shuru.first<<" "<<agey_shuru.second<<endl;
            ans-= agey_shuru.second-1;
            st.erase( agey_shuru );
            if( pos-agey_shuru.first>0 )
                ans+= pos-agey_shuru.first-1,
                      st.insert( pii( agey_shuru.first, pos-agey_shuru.first ) );
            if( agey_shuru.first+agey_shuru.second-1-pos>0 )
                ans+= agey_shuru.first+agey_shuru.second-1-pos-1,
                      st.insert( pii( pos+1, agey_shuru.first+agey_shuru.second-1-pos ) );

        }

        s[pos]= c;

        cout<< ans <<"\n";
    }
}
