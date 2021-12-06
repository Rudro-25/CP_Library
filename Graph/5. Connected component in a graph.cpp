#include <bits/stdc++.h>
using namespace std;

#define      PSB         push_back
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=3e6+5;

int n,m;
vector<int> g[N] ;
bool used[N] ;
vector<int> comp ;

void dfs(int v) {
    used[v] = true ;
    comp.push_back(v);
    for (size_t i = 0; i < (int) g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

void find_comps() {
    for (int i = 0; i < n ; ++i)
        used [i] = false;
    for (int i = 0; i < n ; ++i)
        if (!used[i]) {
            comp.clear();
            dfs(i);
            cout << "Component:" ;
            for (size_t j = 0; j < comp.size(); ++j)
                cout << ' ' << comp[j]+1;
            cout << endl ;
        }
}


int main(){
  FastIO

    cin>>n>>m;  // n nodes and m edges.
    for(ll i=0;i<m;i++){
        ll x,y; cin>>x>>y;
        x--,y--;
        g[x].PSB(y); g[y].PSB(x);
    }

    find_comps();


  return 0;
}

/*
5 3
1 2
1 4
3 5

ans:
1st component: 1 2 4
2nd component: 3 5
*/
