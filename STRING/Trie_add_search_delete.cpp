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

ll node_id[1007][28],end_word[1007],n;

void insert_in_trie(string s){
	ll par_node=0;
	for(ll i=0;i<s.size();i++){
		if(node_id[par_node][s[i]-'a']==-1)
			node_id[par_node][s[i]-'a']=++n;
		par_node=node_id[par_node][s[i]-'a'];
	}
	end_word[par_node]=1;
}

void search_in_trie(string s){
	ll par_node=0;
	for(ll i=0;i<s.size();i++){
		if(node_id[par_node][s[i]-'a']==-1){
			cout<<"String not found!"<<endl;
			return;
		}
		par_node=node_id[par_node][s[i]-'a'];
	}
	if(end_word[par_node]) cout<<"String found!"<<endl;
	else cout<<"String not found!"<<endl;
}

void delete_word_in_trie(string s){
	ll par_node=0;
	for(ll i=0;i<s.size();i++)
		par_node=node_id[par_node][s[i]-'a'];
	end_word[par_node]=0;
}

int main()
{   
    memset(node_id,-1,sizeof(node_id));
    ll q;
    cin>>q;
    while(q--){
        ll c;
        string s;
        cin>>c>>s;
        if(c==1) insert_in_trie(s);
        if(c==2) search_in_trie(s);
        if(c==3) delete_word_in_trie(s);
    }

    return 0;
}
