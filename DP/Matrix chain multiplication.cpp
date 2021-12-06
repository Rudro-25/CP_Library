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
ll dp[107][107],path[107][107];

ll solve(ll i,ll j){
	if(i==j) return 0;
	if(dp[i][j]!=Max) return dp[i][j];

	for(ll k=i;k<j;k++){
		ll x=solve(i,k)+solve(k+1,j)+(a[i]*a[k+1]*a[j+1]);
		if(x<dp[i][j]){
			dp[i][j]=x;
			path[i][j]=k;
		}
	}
	return dp[i][j];
}

void print_path(ll i,ll j){
	cout<<"(";
	if(i==j){
		cout<<a[i]<<" x "<<a[j+1]<<")";
		return;
	}
	print_path(i,path[i][j]);
	print_path(path[i][j]+1,j);
	cout<<")";
}

int main()
{   

    ll n;
    cin>>n;
    for(ll i=1;i<=n+1;i++) cin>>a[i];

    for(ll i=1;i<=n;i++)
    	for(ll j=1;j<=n;j++)
    		dp[i][j]=Max;

    ll ans=solve(1,n);
    cout<<ans<<endl;

    print_path(1,n);

    return 0;
}
