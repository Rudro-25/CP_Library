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

ll a[107];

ll solve(ll n,ll sum){
	ll dp[sum+1];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	vector<ll> idx;
	idx.pb(0);
	for(ll i=1;i<=n;i++){
		ll len=idx.size();
		for(ll j=0;j<len;j++){
			if(idx[j]+a[i]<=sum && !dp[idx[j]+a[i]]){
				dp[idx[j]+a[i]]=1;
				idx.pb(idx[j]+a[i]);
			}
		}
	}
	return dp[sum];
}

int main()
{   

    ll n,s;
    cin>>n>>s;
    for(ll i=1;i<=n;i++) cin>>a[i];
    if(solve(n,s)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

	return 0;
}
