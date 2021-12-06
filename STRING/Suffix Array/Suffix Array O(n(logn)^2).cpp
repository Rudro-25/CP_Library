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

int main()
{	

	string s;
	cin>>s;

	s+='$';
	ll len=s.size();

	ll pos[s.size()];

	vector<pair<ll,ll>> temp;
	for(ll i=0;i<len;i++)
		temp.pb({(ll)s[i],i});
	sort(all(temp));
	pos[temp[0].second]=0;
	for(ll i=1,ok=0;i<len;i++){
		if(temp[i].first!=temp[i-1].first) ok++;
		pos[temp[i].second]=ok;
	}

	ll ans[len];
	for(ll k=1;k<=len;){
		k*=2;
		vector<pair<pair<ll,ll>,ll>> a;
		for(ll i=0;i<len;i++)
			a.pb({{pos[i],pos[(i+k/2)%len]},i});
		sort(all(a));
		pos[a[0].second]=0;
		ans[0]=a[0].second;
		for(ll i=1,ok=0;i<len;i++){
			if(a[i].first!=a[i-1].first) ok++;
			pos[a[i].second]=ok;
			ans[i]=a[i].second;
		}
	}

	for(ll i=0;i<len;i++)
		cout<<ans[i]<<" ";
	cout<<endl;

	return 0;
}
