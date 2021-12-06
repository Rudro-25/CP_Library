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

ll mod=1000000607;
ll base=43;
//ll double_Hash_base=903;

int main()
{   

    string s,p;
    cin>>s>>p;

    ll len=s.size();
    ll bigmod[len+1];
    bigmod[0]=1;
    for(ll i=1;i<=len;i++)
    	bigmod[i]=(bigmod[i-1]*base)%mod;

    ll hash_val[len+1];
    hash_val[0]=0;
    for(ll i=1;i<=len;i++)
    	hash_val[i]=(hash_val[i-1]+(ll)(s[i-1]-'a'+1)*bigmod[i-1])%mod;

    ll hash=0;
    for(ll i=0;i<p.size();i++)
    	hash=(hash+(ll)(p[i]-'a'+1)*bigmod[i])%mod;

    for(ll i=0;i<len;i++){
    	ll l=i,r=i+p.size()-1;
    	ll h1=(hash_val[r+1]-hash_val[l]+mod)%mod;
    	ll h2=(hash*bigmod[l])%mod;
    	if(h1==h2){
    		cout<<"Pattern found!"<<endl;
    		return 0;
    	}
    }

    cout<<"Pattern not found!"<<endl;

	return 0;
}
