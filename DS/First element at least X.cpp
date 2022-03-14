//single position update and range query.
//Find kth one with update
//https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/C

#include <bits/stdc++.h>
using namespace std;

#define      PSB         push_back
#define      MP          make_pair
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=5e6+5;
const ll INF =1e18;

struct seg{
  ll mx_val;
};
seg merge(seg a, seg b){
  seg c;
  c.mx_val = max ( a.mx_val , b.mx_val ) ;
  return c;
}

ll a[N];
seg b[4*N];

void build(ll l, ll r, ll node){
  if(l == r){
    b[node].mx_val = a[l];
    return;
  }
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  build(l, mid , n1);
  build(mid+1, r, n2);
  b[node] = merge(b[n1] , b[n2]);
  return;
}
 
seg dummy(){
  return {0};
}
 
ll query(ll l, ll r, ll node, ll val){
  //if(y < l || x > r) return dummy();
  if(l == r) return l;
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  ll bal= b[n1].mx_val;
  if(bal>=val){
    return query(l,mid,n1,val);
  }
  else{
    return query(mid+1,r,n2,val);
  }
  //return merge(query(l , mid , n1 , x , y) , query(mid+1 , r , n2 , x , y));
}
void update(ll l, ll r, ll node,ll x,ll v){
  if(x < l || x > r) return;
  if(l == r){
    b[node].mx_val = v;
    return;
  }
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  update(l, mid , n1, x, v);
  update(mid+1, r, n2 , x, v);
  b[node] = merge(b[n1] , b[n2]);
}

int main(){
  FastIO

    ll n,q;
    cin>>n>>q;

    for(ll i=1;i<=n;i++) cin>>a[i];

    build(1,n,1);
    /*for(ll i=0;i<20;i++)
      cout<<b[i].min<<' ';
    cout<<endl;*/

    while(q--){
      ll t,pos,val; cin>>t;
      if(t==1){
        cin>>pos>>val;
        update(1,n,1,pos+1,val);
      }
      else{
        cin>>val;
        if(b[1].mx_val<val) cout<<-1<<endl;
        else{
           ll ans = query(1,n,1,val);
           cout<<ans-1<<endl;
        }
      }

    }

    

  return 0;
}
/*
//asking for 0 index of [L,r)
5 7
1 3 2 4 6
2 2
2 5
1 2 5
2 4
2 8
1 3 7
2 6

ans:
5 7
1 3 2 4 6
2 2
2 5
1 2 5
2 4
2 8
1 3 7
2 6


*/
 
