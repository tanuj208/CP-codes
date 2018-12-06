#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
 
ll xx=1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<ll> aa;
    ll i,j;
    for(i=2;i<=1000000;i++)
    {
        ll temp=i*i*i;
        while(temp<=xx)
        {
        	ll x=sqrt(temp);
        	if(x*x!=temp)
	        	aa.insert(temp);
            if(temp>xx/i)
                break;
            temp=temp*i;
        }
    }
    vector<ll> f;
    for(auto it=aa.begin();it!=aa.end();it++)
    	f.pb(*it);
    ll q;
    // cout<<f[0]<<" "<<f[1]<<endl;
    cin>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        ll r1=upper_bound(f.begin(),f.end(),r)-f.begin();
        ll l1=lower_bound(f.begin(),f.end(),l)-f.begin();
        ll ans=r1-l1;
        // cout<<ans<<endl;
        // cout<<(ll)sqrt(r)<<" "<<(ll)sqrt(l-1);
        ans+=sqrt(r)-(ll)sqrt(l-1);
        cout<<ans<<"\n";
    }
    return 0;
}
