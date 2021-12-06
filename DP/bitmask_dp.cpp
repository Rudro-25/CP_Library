// How many ways existed to make a number of length n without leading zeroes in which every digit occures at least once.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll dp[1007][2048],n;

ll solve(ll pos,ll chk){
    if(pos==n){
        if(chk==1023) return 1;
        else return 0;
    }
    if(dp[pos][chk]!=-1) return dp[pos][chk];
    dp[pos][chk]=0;
    for(ll i=0;i<=9;i++){
        if(!i && !pos) continue;
        dp[pos][chk]+=solve(pos+1,chk|(1<<i));
    }
    return dp[pos][chk];
}

int main()
{   

    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0)<<endl;

    return 0;
}
