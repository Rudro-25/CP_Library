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

ll dp[1002][1002];
int main()
{	

	string s;
	cin>>s;

	for(ll i=1;i<=s.size();i++){
		for(ll j=1,k=i;k<=s.size();j++,k++){
			if(j==k) dp[j][k]=1;
			else{
				if(s[j-1]==s[k-1]){
					if(i==2) dp[j][k]=2;
					else dp[j][k]=dp[j+1][k-1]+2;
				}
				else dp[j][k]=max(dp[j+1][k],dp[j][k-1]);
			}
		}
	}

	for(ll i=1;i<=s.size();i++){
		for(ll j=1;j<=s.size();j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}

	cout<<dp[1][s.size()]<<endl;

	return 0;
}
