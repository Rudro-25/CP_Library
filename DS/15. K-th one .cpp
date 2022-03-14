//single position update and range query.

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
  ll t_one,l_one,r_one;
};
seg merge(seg a, seg b){
  seg c;
  c.t_one = a.t_one + b.t_one ;
  c.l_one = a.t_one;
  c.r_one = b.t_one;
  return c;
}

ll a[N];
seg b[4*N];

void build(ll l, ll r, ll node){
  if(l == r){
    b[node].t_one = (a[l]==1);
    b[node].l_one = 0;
    b[node].r_one = 0;
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
  return {0,0,0};
}
 
ll query(ll l, ll r, ll node, ll val){
  //if(y < l || x > r) return dummy();
  if(l == r) return l;
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  ll bal= b[n1].t_one;
  if(bal>=val){
    return query(l,mid,n1,val);
  }
  else{
    return query(mid+1,r,n2,val-bal);
  }
  //return merge(query(l , mid , n1 , x , y) , query(mid+1 , r , n2 , x , y));
}
void update(ll l, ll r, ll node,ll v){
  if(v < l || v > r) return;
  if(l == r){
    a[l]=(a[l]^1LL);
    b[node].t_one = a[l];
    b[node].l_one = 0;
    b[node].r_one = 0;
    return;
  }
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  update(l, mid , n1, v);
  update(mid+1, r, n2 , v);
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
      ll t,pos; cin>>t>>pos;
      if(t==1){
        update(1,n,1,pos+1);
      }
      else{
        ll ans = query(1,n,1,pos+1);
        cout<<ans-1<<endl;
      }

    }

    

  return 0;
}
/*
//asking for 0 index of [L,r)
5 1
1 1 0 1 0
2 0


ans:
11 5 2
8 5 1
14 5 1

*/
 
