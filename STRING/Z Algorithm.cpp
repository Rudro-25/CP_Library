//Solution of LOJ-1255
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

	ll t,ii=0;
	cin>>t;

	while(t--){
		string a,b;
		cin>>a>>b;
		string s=b+'#'+a+'$';
		ll z[s.size()];
		z[0]=0;

		for(ll i=1,j=1,k=0;i<s.size();){
			if(i==j && s[0]!=s[i]) z[i]=0,i++,j++;
			else if(s[i]!=s[k]){
				ll len=i-j;
				z[j]=len;
				j++;
				k=0;
				while(k+1<len){
					k++;
					if(j+z[k]>=i) break;
					z[j]=z[k];
					j++;
				}
				k=z[k];
			}
			else k++,i++;
		}

		ll ans=0;
		for(ll i=0;i<s.size();i++){
			if(z[i]==b.size()) ans++;
		}

		cout<<"Case "<<++ii<<": "<<ans<<endl;
	}

	return 0;
}
