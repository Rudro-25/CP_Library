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

queue<int> q;
vector<bool> used(N);
vector<int> d(N), p(N); // for source to any node distance and parent node

void bfs(ll s){
q.push(s);
used[s] = true;
p[s] = -1;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
     }
  } 
}


int main(){
  FastIO

    cin>>n>>m;  // n nodes and m edges.
    for(ll i=0;i<m;i++){
        ll x,y; cin>>x>>y;
        x--,y--;
        adj[x].PSB(y); adj[y].PSB(x);
    }
    used.assign(n, false);

    bfs(0);

    //Find source to to a vertex u path
    ll u; cin>>u;
    u--;
    if (!used[u]) {
        cout << "No path!";
    } else {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v+1 << " ";
        cout<<endl;
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
5

ans:
path: 1->2->4->5.
*/