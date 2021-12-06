//Problem link: https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/A
//Solution:

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

pair<pair<ll,ll>,ll> a[300007];
ll cnt[300007];
pair<pair<ll,ll>,ll> temp[300007];
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

    char s[300007];
    scanf("%s",s);
 
    ll len=strlen(s)+1;
    s[len-1]='$';

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

    ll ans[len];
    for(ll k=1;k<=len;){
        k*=2;
        for(ll i=0;i<len;i++)
            a[i]={{pos[i],pos[(i+k/2)%len]},i};
        redix_sort(len);
        pos[a[0].second]=0;
        ans[0]=a[0].second;
        for(ll i=1,ok=0;i<len;i++){
            if(a[i].first!=a[i-1].first) ok++;
            pos[a[i].second]=ok;
            ans[i]=a[i].second;
        }
    }

	ll q;
	scanf("%lli",&q);

	while(q--){
		char p[300007];
		scanf("%s",&p);

		ll length=strlen(p);

		ll l=0,r=len-1;
		ll u=l,v=r;
		for(ll i=0;i<length;i++){
			//cout<<l<<" "<<r<<endl;
			while(l<r){
				ll m=(l+r)/2;
				if(ans[m]+i>=len || p[i]>s[ans[m]+i]) l=m+1;
				if(p[i]==s[ans[m]+i]) r=m;
				if(p[i]<s[ans[m]+i]) r=m-1;
				//cout<<i<<" "<<l<<" "<<r<<" "<<m<<" "<<p[i]<<" "<<ans[m]+i<<" "<<s[ans[m]+i]<<endl;
			}
			u=l;
			r=v;
			while(l+1<r){
				ll m=(l+r)/2;
				if(ans[m]+i>=len || p[i]>s[ans[m]+i]) l=m+1;
				if(p[i]==s[ans[m]+i]) l=m;
				if(p[i]<s[ans[m]+i]) r=m-1;
				//cout<<i<<" "<<l<<" "<<r<<" "<<m<<" "<<p[i]<<" "<<ans[m]+i<<" "<<s[ans[m]+i]<<endl;
			}
			if(ans[r]+i<len && p[i]!=s[ans[r]+i]) r=l;
			v=r;
			l=u;
			//cout<<u<<" "<<v<<" "<<ans[u]<<" "<<ans[v]<<endl;
		}
		ll ok=0;
		for(ll i=0;i<length;i++) if(ans[u]+i>=len || p[i]!=s[ans[u]+i]) ok=1;
		if(!ok) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}
