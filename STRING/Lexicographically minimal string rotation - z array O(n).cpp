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

	ll n=s.size();
	s=s+s+"z";
	ll z[s.size()],id=0;
	z[0]=0;
	for(ll i=1,j=1,k=0;i<s.size();){
		if(i==j && s[id]!=s[i]){
			if(s[id]>s[i] && i<n){
				id=i;
				k=id;
			}
			z[i]=0,i++,j++;
		}
		else if(s[i]!=s[k]){
			ll len=i-j,temp=id;
			z[j]=len;
			if(s[k]>s[i] && j<n){
				id=j;
				z[id]=0;
			}
			k=temp;
			j++;
			while(k+1<len){
				k++;
				if(j+z[k]>=i) break;
				z[j]=z[k];
				j++;
			}
			k=id+z[k];
		}
		else k++,i++;
	}

	for(ll i=id;i<id+n;i++) cout<<s[i];
	cout<<endl;

    return 0;
}
