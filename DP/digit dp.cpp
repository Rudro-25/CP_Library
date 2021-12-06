// How many numbers existed from a to b, which digit sum is equals to s.
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

ll dp[11][2][100];
string x;
ll solve(ll pos,ll chk,ll sum){
	if(sum<0) return 0;
	if(!sum) return 1;
	if(pos==x.size()) return 0;

	if(dp[pos][chk][sum]!=-1) return 0;

	dp[pos][chk][sum]=0;
	for(char i='0';i<='9';i++){
		if(!chk && i>x[pos]) break;
		ll new_chk=chk?1:(i!=x[pos]);
		dp[pos][chk][sum]+=solve(pos+1,new_chk,sum-(ll)(i-'0'));
	}
	return dp[pos][chk][sum];
}

int main()
{   

    ll a,b,s;
    cin>>a>>b>>s;

    a--;
    while(a){
    	x+=(char)(a%10+'0');
    	a/=10;
    }reverse(all(x));
    memset(dp,-1,sizeof(dp));
    ll p=solve(0,0,s);

    x.clear();
    while(b){
    	x+=(char)(b%10+'0');
    	b/=10;
    }reverse(all(x));
    memset(dp,-1,sizeof(dp));
    ll q=solve(0,0,s);

    cout<<q-p<<endl;

    return 0;
}
