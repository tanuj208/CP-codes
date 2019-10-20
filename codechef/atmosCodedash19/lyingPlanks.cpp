#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define endl "\n"

typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;
    
vector<ll> segtree(800010, 0);
vector<ll> lazy(800010, 0);

//query returns the required answer between given ranges
ll query(ll l, ll r,ll index,ll low, ll high) //verify return type
{
    //if we visit a node it must hold the correct value
    if(lazy[index]){
        //means whole of the range was eligible to be updated
        // so as we visited this node we will update it, so that it holds correct value
        segtree[index] = lazy[index];
        if(high!=low){
            lazy[2*index] = lazy[index]; 
            lazy[2*index+1] = lazy[index]; 
        }
        lazy[index] = 0;
    }
    if(r<low || l>high) return 0;
    
    ll m=(low+high)>>1;
    if(l<=low && high<=r)
    {
        // cout<<segtree[index]<<"seg"<<endl;
        return segtree[index];//as it holds the up-to-date value
    }
    else{
        ll xx = max(query(l,r,2*index,low,m), query(l,r,2*index+1,m+1,high));
        // cout<<xx<<"DFFD"<<endl;
        return xx;
    }
}

void update(ll l, ll r,ll index,ll low, ll high,ll val){
    //if we visit a node it must hold the correct value
    ll m=(low+high)/2;

    // resolve the old lazy on this node first
    if(lazy[index]){
        //means whole of the range was eligible to be updated, so as we visited this node we will update it
        segtree[index] = lazy[index];
        // cout<<segtree[index]<<" "<<lazy[index]<<"F\n";
        if(high!=low){ 
            lazy[2*index] = lazy[index]; 
            lazy[2*index+1] = lazy[index]; 
        }
        lazy[index] = 0;
    }

    // then impose new lazy onto it
    if(l<=low && high<=r){
        segtree[index] = val;//make it completely up-to-date
        // cout<<segtree[index]<<"VF\n";
        if(high!=low){
            lazy[2*index] = val; 
            lazy[2*index+1] = val;
        }
    }
    else if(r<low || l>high) return;
    else{
        update(l,r,2*index,low,m,val);
        update(l,r,2*index+1,m+1,high,val);
        segtree[index]=max(segtree[2*index], segtree[2*index+1]);
    }
}
  
// Driver program to test above function 
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N = 2*1e5+5;
    ll q;
    cin>>q;
    while(q--)
    {
        ll x;
        cin>>x;
        if(x==1)
        {
            ll l,r,d;
            cin>>l>>r>>d;
            ll val = query(l, r, 1, 1, N);
            update(l, r, 1, 1, N, d+val);
        }
        else
        {
            ll X;
            cin>>X;
            ll val = query(X, X, 1, 1, N);
            cout<<val<<endl;
        }
    }
  
    return 0; 
} 
