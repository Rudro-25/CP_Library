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

	ll FSA[p.size()][26];

	for(ll i=0,lps=0;i<p.size();i++){
		for(ll j=0;j<26;j++){
			if(!i) FSA[i][j]=0;
			else FSA[i][j]=FSA[lps][j];
		}
		FSA[i][p[i]-'a']=i+1;
		lps=FSA[lps][p[i]-'a'];
	}

	for(ll i=0,j=0;i<s.size();i++){
		j=FSA[j][s[i]-'a'];
		if(j==p.size()){
			cout<<"The pattern matches the string at index "<<i-p.size()+1<<endl;
			break;
		}
	}

	return 0;
}
