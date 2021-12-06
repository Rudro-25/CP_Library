#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define      mxx                 1e18
#define      mnn                 -1e18
//#define      int                 long long
#define      Y()                 cout<< "YES" <<endl
#define      N()                 cout << "NO"<<endl
#define      endl                "\n"
#define      Ceil(x,y)           ((x+y-1)/y)
#define      sz(s)               (int)s.size()
#define      angle(x)            double(x * acos(-1) / 180.0)
#define      max_3(a,b,c)        max(a, max(b,c))
#define      min_3(a,b,c)        min(a, min(b,c))
#define      gcd(a,b)            __gcd(a,b)
#define      lcm(a,b)           (a*b)/gcd(a,b)
#define      ll                  long long
#define      PI                  acos(-1)
#define      mem(a,v)            memset(a,v,sizeof(a))
#define      SORT(v)             sort(v.begin(),v.end())
#define      REV(v)              reverse(v.begin(),v.end())
#define      B                   begin()
#define      E                   end()
#define      V                   vector
#define      F                   first
#define      S                   second
#define      pb                 push_back
#define      mp                  make_pair
#define      flash               cout.flush()
#define      InTheNameOfGod      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<ll> s;
//*s.find_by_order(x) //val at x index in sorted order.
//s.order_of_key(x); //index of x or if not find x , it show index no in sort array.


constexpr ll MOD = 998244353;
constexpr ll mod = 1e9 + 7;
const double eps = 1e-7;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*-----*/
#define bug1(a)  cerr<<a<<endl;
#define bug2(a,b)  cerr<<a<<" "<<b<<endl;
#define bug3(a,b,c)  cerr<<a<<" "<<b<<" "<<c<<endl;
/*----*/
const ll N=3e6+5;
vector<ll> adj[N];
ll power(ll n,ll p){if(p==0) return 1;if(p==1)return n;if(p%2)return power(n,p-1)*n;else{ll x=power(n,p/2);return x*x;}}
ll modpow(ll a,ll b,ll m){ll ans=1;while(b){if(b&1)ans=(ans*a)%m;b/=2;a=(a*a)%m;}return ans;}
ll nsum(ll num){return (num*(num+1))/2;}
void edge (ll u,ll v) {adj[u].PSB(v) ;adj[v].PSB(u);}
/*------------------START---------------------*/
//memset(dp,0x3f,sizeof dp); //3d_dp
void init_code(){
   //#ifndef ONLINE_JUDGE
   InTheNameOfGod
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   //#endif
}

ll c;


/*-----*/
void solve(){
   ll n;
   string s;
   cin>>n;




   //cout << fixed << setprecision(10);
}
/*-----*/
//signed main(){
int main(){
   //init_code();
   ll Test=1;
   //cin>>Test;
   while(Test--){
     solve();
    }
  return 0;
}
