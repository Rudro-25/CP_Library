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

    string a;
    cin>>a;

    string s="#";
    for(ll i=0;i<a.size();i++){
        s+=a[i];
        s+='#';
    }

    ll pal[s.size()];

    for(ll center=0,i=0;center<s.size();){
        if(i<s.size() && 2*center-i>=0 && s[i]==s[2*center-i]){
            i++;
        }
        else{
            ll len=2*(i-center-1)+1;
            pal[center]=len;
            for(ll j=1;center+j<=i;j++){
                if(center+j==i || center+j+pal[center-j]/2+1>=i){
                    center=center+j;
                    break;
                }
                pal[center+j]=pal[center-j];
            }
        }
    }

    for(ll i=1;i<s.size();i+=2) cout<<pal[i]/2<<" ";cout<<endl;

    return 0;
}
