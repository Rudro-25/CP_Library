#include <bits/stdc++.h>
using namespace std;

#define      PSB         push_back
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=3e6+5;

vector<ll> adj[N];  // adjacency list of graph
int n,m; // number of nodes and edges
//int s; // source vertex

int dfs_timer=0;
vector<bool> visited(N);
vector<int> time_in(N), time_out(N); // for source to any node distance and parent node

void dfs(ll v){
    time_in[v]=dfs_timer++;
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    time_out[v]=dfs_timer++;
}


int main(){
  FastIO

    cin>>n>>m;  // n nodes and m edges.
    for(ll i=0;i<m;i++){
        ll x,y; cin>>x>>y;
        x--,y--;
        adj[x].PSB(y); adj[y].PSB(x);
    }
    visited.assign(n, false);

    dfs(0);

    for(ll i=0;i<n;i++){
        cout<<time_in[i]<<' '<<time_out[i]<<endl;
    }

  return 0;
}

/*
5 5
1 2
2 3
1 3
2 4
4 5

ans:

0 9
1 8
2 3
4 7
5 6
*/
