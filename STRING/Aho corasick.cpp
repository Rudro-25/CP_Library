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

ll node_id[1007][28],end_word[1007],n,failure[1007];
string pat[1007];

void insert_in_trie(string s,ll id){
	ll par_node=0;
	for(ll i=0;i<s.size();i++){
		if(node_id[par_node][s[i]-'a']==-1)
			node_id[par_node][s[i]-'a']=++n;
		par_node=node_id[par_node][s[i]-'a'];
	}
	end_word[par_node]=id;
}

void make_failure_function(){
	queue<ll> q;
	for(ll i=0;i<26;i++){
		if(node_id[0][i]!=-1)
			q.push(node_id[0][i]);
	}

	while(!q.empty()){
		ll u=q.front();
		q.pop();
		for(ll i=0;i<26;i++){
			if(node_id[u][i]!=-1){
				ll p=u;
				while(p!=0){
					p=failure[u];
					if(node_id[p][i]!=-1){
						failure[node_id[u][i]]=node_id[p][i];
						break;
					}
				}
				q.push(node_id[u][i]);
			}
		}
	}
}

vector<ll> ans[1007];
void match_string(string s){
	ll par=0;
	for(ll i=0;i<s.size();i++){
		while(par!=0 && node_id[par][s[i]-'a']==-1)
			par=failure[par];
		if(node_id[par][s[i]-'a']!=-1){
			par=node_id[par][s[i]-'a'];
			if(end_word[par]){
				ans[end_word[par]].pb(i-(ll)pat[end_word[par]].size()+1);
			}
			ll fal=failure[par];
			if(end_word[fal]){
				ans[end_word[fal]].pb(i-(ll)pat[end_word[fal]].size()+1);
			}

		}
	}
}

int main()
{   
    memset(node_id,-1,sizeof(node_id));
    ll n;
    cin>>n;

    for(ll i=1;i<=n;i++){
    	cin>>pat[i];
    	insert_in_trie(pat[i],i);
    }

    make_failure_function();
    string s;
    cin>>s;
    match_string(s);

    for(ll i=1;i<=n;i++){
    	if(ans[i].size()!=0){
    		cout<<pat[i]<<" matches at positions ";
    		for(ll j=0;j<ans[i].size();j++){
    			cout<<ans[i][j];
    			if(j+1!=ans[i].size()) cout<<", ";
    		}
    		cout<<endl;
    	}
    	else cout<<pat[i]<<" doesn't match anywhere!"<<endl;
    }

    return 0;
}
