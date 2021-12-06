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

pair<pair<ll,ll>,ll> a[400007];
ll cnt[400007];
pair<pair<ll,ll>,ll> temp[400007];
void redix_sort(ll len){
    memset(cnt,0,sizeof(cnt));
    for(ll i=0;i<len;i++)
        cnt[a[i].first.second]++;
    for(ll i=1;i<len;i++)
        cnt[i]+=cnt[i-1];
    for(ll i=len-1;i>=0;i--){
        cnt[a[i].first.second]--;
        temp[cnt[a[i].first.second]]=a[i];
    }

    memset(cnt,0,sizeof(cnt));
    for(ll i=0;i<len;i++)
        cnt[temp[i].first.first]++;
    for(ll i=1;i<len;i++)
        cnt[i]+=cnt[i-1];
    for(ll i=len-1;i>=0;i--){
        cnt[temp[i].first.first]--;
        a[cnt[temp[i].first.first]]=temp[i];
    }
}

int main()
{   

    string s,t;
    cin>>s>>t;

    ll p=s.size(),q=t.size();
 
    s=t+"#"+s+"$";
    ll len=s.size()+1;

    ll pos[len];

    vector<pair<ll,ll>> temp;
    for(ll i=0;i<len;i++)
        temp.pb({(ll)s[i],i});
    sort(all(temp));
    pos[temp[0].second]=0;
    for(ll i=1,ok=0;i<len;i++){
        if(temp[i].first!=temp[i-1].first) ok++;
        pos[temp[i].second]=ok;
    }

    ll ans[len],ind[len];
    for(ll k=1;k<=len;){
        k*=2;
        for(ll i=0;i<len;i++)
            a[i]={{pos[i],pos[(i+k/2)%len]},i};
        redix_sort(len);
        pos[a[0].second]=0;
        ans[0]=a[0].second;
        ind[a[0].second]=0;
        for(ll i=1,ok=0;i<len;i++){
            if(a[i].first!=a[i-1].first) ok++;
            pos[a[i].second]=ok;
            ans[i]=a[i].second;
            ind[a[i].second]=i;
        }
    }

	ll lcp[len];
	lcp[0]=-1;
	for(ll i=0,k=0;i<len-1;i++){
		ll idx=ind[i];
		ll j=ans[idx-1];
		while(s[i+k]==s[j+k]) k++;
		lcp[idx]=k;
		if(k) k--;
	}

	ll longest_common_substring=0,idx=len+1;
	for(ll i=1;i<len;i++){
		if(((ans[i]>q && ans[i-1]<q) || (ans[i]<q && ans[i-1]>q)) && lcp[i]>longest_common_substring){
			longest_common_substring=max(longest_common_substring,lcp[i]);
			idx=ans[i];
		}
	}
	for(ll i=idx;i<idx+longest_common_substring;i++) cout<<s[i];
	cout<<endl;

	return 0;
}
