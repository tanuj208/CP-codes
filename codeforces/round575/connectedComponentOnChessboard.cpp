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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

// priority_queue <ll,vector<ll>,greater<ll> > p;

typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q;
	cin>>q;
	while(q--)
	{
		ll b,w;
		cin>>b>>w;
		bool white=false;
		if(b>w)
			white=true;
		ll x=1000000;
		ll y=1000001;
		if(white)
			y--;
		ll bb=max(b,w);
		ll ww=min(b,w);
		b=bb;
		w=ww;
		bool st=true;
		vector<pii> ans;
		while(true)
		{
			if(st && b>=w+3)
			{
				ans.pb(mp(x,y));
				ans.pb(mp(x-1,y));
				ans.pb(mp(x,y-1));
				ans.pb(mp(x+1,y));
				ans.pb(mp(x,y+1));
				b-=4;
				w--;
				x+=2;
				st=false;
			}
			else if(b>=w+2)
			{
				ans.pb(mp(x,y));
				ans.pb(mp(x+1,y));
				ans.pb(mp(x,y+1));
				ans.pb(mp(x,y-1));
				b-=3;
				w--;
				x+=2;
			}
			else if(b==w+1)
			{
				ans.pb(mp(x,y));
				ans.pb(mp(x+1,y));
				ans.pb(mp(x,y+1));
				b-=2;
				w--;
				x+=2;
			}
			else if(b==w)
			{
				ans.pb(mp(x,y));
				ans.pb(mp(x+1,y));
				x+=2;
				b--;
				w--;
			}
			if(b<=0 || w<=0)
				break;
		}
		if(b<0 || w<0 || w==0 && b!=0)
			cout<<"NO"<<endl;
		else
		{
			ll i;
			cout<<"YES"<<endl;
			for(i=0;i<sz(ans);i++)
				cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
		}
	}
	return 0;
}