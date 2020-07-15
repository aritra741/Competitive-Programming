#include <iostream>
#include <algorithm>

const int  MAX_L  = 50000 + 1 ;
const int  MAX_N  = 2 *  MAX_L  + . 1 ;
int  S [ MAX_N ];
int  n,  _k ;
int  SA [ MAX_N ],  LCP [ MAX_N ]; // SA [i]: = suffix i is lexicographically starting subscript; lcp [i]: = [ sa [i] S ... Longest common prefix length with S [sa [i + 1] ...]
int  rank [ MAX_N ],  tmp [ MAX_N ];

// compare (rank [i], rank [i + k]) and (rank [j], rank [j + k])
bool  compare_sa ( const int  i, const int  j )
{
    if ( rank [ i ] ! =  rank [ j ])
    {
        return  rank [ i ] <  rank [ j ];
    }
    return ( i  +  _k  <=  n  ?  rank [ i  +  _k ] : - 1 ) < ( j  +  _k  <=  n  ?  rank [ j  +  _k ] : - 1 );
}

// Calculate the suffix array of the string S
void  construct_sa ()
{
    // The initial length is 1, and rank directly takes the character encoding.
    for ( int  i  = 0 ;  i  <=  n ;  i ++)
    {
        sa [ i ] =  i ;
        rank [ i ] =  i  <  n  ?  S [ i ] : - 1 ;
    }

    // Use the result of sorting with length k to sort with length 2k
    for ( _k  = 1 ;  _k  <=  n ;  _k  << = 1 )
    {
        std :: sort ( sa,  sa  +  n  + 1,  compare_sa );

        // Now temporarily store the newly calculated rank in tmp, and then save it back to rank
        tmp [ sa [ 0 ]] = 0 ;
        for ( int  i  = 1 ;  i  <=  n ;  i ++)
        {
            tmp [ sa [ i ]] =  tmp [ sa [ i  - 1 ]] + ( compare_sa ( sa [ i  - 1 ],  sa [ i ]) ? 1 : 0 );
        }
        for ( int  i  = 0 ;  i  <=  n ;  i ++)
        {
            rank [ i ] =  tmp [ i ];
        }
    }
}

void  construct_lcp ()
{
    memset ( lcp, 0, sizeof ( lcp ));
    for ( int  i  = 0 ;  i  <=  n ;  i ++)
    {
        rank [ sa [ i ]] =  i ;
    }
    int  h  = 0 ;
    lcp [ 0 ] = 0 ;
    for ( int  i  = 0 ;  i  <  n ;  i ++)
    {
        int  J  =  SA [ Rank [ I ] - . 1 ];
        if ( h  > 0 )
        {
            h- ;
        }
        for (;  i  +  h  <  n  &&  j  +  h  <  n  &&  S [ i  +  h ] ==  S [ j  +  h ];  h ++);
        LCP [ Rank [ I ] - . 1 ] =  H ;
    }
}

int  nn, m, k ;
using namespace  std ;
// the number of C that can form a length greater than or equal to k

int  main ()
{
    while (scanf("%d %d %d", &nn, &M, &K ))
    {
        n  =  n+m+1;

        for( int i=0; i<n; i++ )
        {
            int p;
            scanf("%d", &p);

            S[i+m+1]= p;
        }

        S[m]=10001;
        S[n] = 0 ;

        construct_sa ();
        construct_lcp ();

        int cnt1= 0, cnt2= 0;

        for( int i=0; i<n+m; i++ )
        {
            if( lcp[i]>=k and n+m+1-saa[i]<=m and n+m+1-saa[i+1]>m )
                cnt1+= lcp[i]-k+1;
            else if( lcp[i]>=k and n+m+1-saa[i+1]<=m and n+m+1-saa[i]>m )
                cnt1+= lcp[i]-k+1;
        }

        for( int i=0; i<n+m; i++ )
        {
            if( lcp[i]>k and n+m+1-saa[i]<=m and n+m+1-saa[i+1]>m )
                cnt2+= lcp[i]-k;
            else if( lcp[i]>k and n+m+1-saa[i+1]<=m and n+m+1-saa[i]>m )
                cnt2+= lcp[i]-k;
        }


    }

}
