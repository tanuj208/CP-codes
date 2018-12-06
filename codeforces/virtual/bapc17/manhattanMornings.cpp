#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

typedef long long ll;
typedef pair<ll,ll> pii;
using namespace __gnu_pbds;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;



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
	pbds a,b;
	ll n;
	cin>>n;
	ll h1,h2,w1,w2;
	cin>>h1>>h2>>w1>>w2;
	if(h1>=w1 && h2>=w2)
	{
		swap(h1,w1);
		swap(h2,w2);
	}
	if(w1>=h1 && h2>=w2)
	{
		swap(h1,w1);
		swap(h2,w2);
	}
	bool mirror=false;
	if(h1>=w1 && w2>=h2)
	{
		w1+=(2*(h1-w1));
		mirror=true;
	}
	ll i;
	map<pii,ll> tmp;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		if(mirror)
		{
			if(x<=h1)
				x+=(2*(h1-x));
			else
				x-=(2*(x-h1));
		}
		if(x>w1 || y>w2 || x<h1 || y<h2)
			continue;
		a.insert(mp(x,y));
		b.insert(mp(y,x));
		tmp[mp(x,y)]++;
	}
	ll ans=0;
	while(!a.empty())
	{
		ll x=a.begin()->first;
		ll y=a.begin()->second;
		ll cnt=b.order_of_key(mp(y,x));
		ll ansInc=tmp[mp(x,y)];

		x=b.begin()->second;
		y=b.begin()->first;
		ll cnt2=a.order_of_key(mp(x,y));
		ll ansInc2=tmp[mp(x,y)];

		if(ansInc-cnt<ansInc2-cnt2)
		{
			ans+=ansInc2;
			auto it=a.begin();
			while(it->first != x || it->second != y)
			{
				b.erase(mp(it->second, it->first));
				a.erase(it);
				it=a.begin();
			}
			it=a.begin();
			b.erase(mp(it->second, it->first));
			a.erase(it);
		}
		else
		{
			ans+=ansInc;
			auto it=b.begin();
			ll x=a.begin()->first;
			ll y=a.begin()->second;
			while(it->first!=y || it->second != x)
			{
				a.erase(mp(it->second, it->first));
				b.erase(it);
				it=b.begin();
			}
			it=b.begin();
			a.erase(mp(it->second, it->first));
			b.erase(it);
		}
	}
	cout<<ans<<endl;
	return 0;
}