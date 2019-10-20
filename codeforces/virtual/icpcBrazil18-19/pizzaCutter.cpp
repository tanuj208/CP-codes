#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

typedef long long ll;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll xx,y;
	cin>>xx>>y;
	ll h,v;
	cin>>h>>v;
	vector<pii> cor;
	ll i;
	ll ans=1+h*v;
	for(i=0;i<h;i++)
	{
		ll a,b;
		cin>>a>>b;
		cor.pb(mp(a,b));
	}
	sort(cor.begin(),cor.end());
	pbds x;
	for(i=0;i<h;i++)
	{
		ll a=cor[i].first;
		ll b=cor[i].second;
		ll cnt=x.order_of_key(b);
		cnt=sz(x)-cnt;
		ans+=(cnt+1);
		x.insert(b);
	}
	x.clear();
	cor.clear();
	for(i=0;i<v;i++)
	{
		ll a,b;
		cin>>a>>b;
		cor.pb(mp(a,b));
	}
	sort(cor.begin(),cor.end());
	for(i=0;i<v;i++)
	{
		ll a=cor[i].first;
		ll b=cor[i].second;
		ll cnt=x.order_of_key(b);
		cnt=sz(x)-cnt;
		ans+=(cnt+1);
		x.insert(b);
	}
	cout<<ans<<endl;
	return 0;
}