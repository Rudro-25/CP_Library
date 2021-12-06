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

    ll n;
    cin>>n;

    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];

    ll sparse[n][(ll)log2(n)+5];
    memset(sparse,-1,sizeof(sparse));
    for(ll i=1;i<=n;i*=2){
        for(ll j=0;j<n;j++){
            if(i==1) sparse[j][(ll)log2(i)]=a[j];
            else if(j+i<=n)
                sparse[j][(ll)log2(i)]=min(sparse[j][(ll)log2(i)-1],sparse[j+i/2][(ll)log2(i)-1]);
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<=(ll)log2(n)+1;j++){
            if(sparse[i][j]!=-1) cout<<sparse[i][j]<<" ";
        }cout<<endl;
    }

    ll q;
    cin>>q;

    while(q--){
        ll l,r;
        cin>>l>>r;
        ll d=log2(r-l+1);
        cout<<min(sparse[l][d],sparse[r-(ll)pow(2,d)+1][d])<<endl;
    }

    return 0;
}
