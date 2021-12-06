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

	string s,p;
	cin>>s>>p;

	ll LPS[p.size()];

	for(ll i=0,j=0;i<p.size();){
		if(!i){
			LPS[i]=0;
			i++;
		}
		else{
			if(p[i]==p[j]){
				LPS[i]=j+1;
				i++,j++;
			}
			else{
				if(!j){
					LPS[i]=0;
					i++;
				}
				else j=LPS[j-1];
			}
		}
	}

	for(ll i=0,j=0;i<s.size();){
		if(s[i]==p[j]) j++,i++;
		else{
			if(!j) i++;
			else j=LPS[j-1];
		}
		if(j==p.size()){
			cout<<"The pattern matches the string at index "<<i-p.size()<<endl;
			break;
		}
	}

	return 0;
}
