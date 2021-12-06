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

string s;
ll dp[107][107][2];

ll solve(ll i,ll j,ll m){
	if(i==j) return ((ll)(s[i]-'0'));
	if(dp[i][j][m]!=-1) return dp[i][j][m];

	if(m) dp[i][j][m]=Max;
	else dp[i][j][m]=-Max;
	for(ll k=i;k<j;k+=2){
		ll x=solve(i,k,m),y;
		if(s[k+1]=='-') y=solve(k+2,j,m==0);
		else y=solve(k+2,j,m);

		if(s[k+1]=='*') x*=y;
		if(s[k+1]=='+') x+=y;
		if(s[k+1]=='-') x-=y;

		if(m) dp[i][j][m]=min(dp[i][j][m],x);
		else dp[i][j][m]=max(dp[i][j][m],x);
	}
	return dp[i][j][m];
}

int main()
{   

	memset(dp,-1,sizeof(dp));
    cin>>s;
    cout<<solve(0,s.size()-1,0)<<" "<<solve(0,s.size()-1,1)<<endl;

    return 0;
}
