#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> ad[100005];
vector<ll> deg(100006,0);

ll func(ll v,ll p)
{
	if(sz(ad[v])==1)
		return v;
	if(ad[v][0]!=p)
		return func(ad[v][0],v);
	else
		return func(ad[v][1],v);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	for(i=1;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
		deg[a]++;
		deg[b]++;
	}
	ll maxdegree=0;
	ll number=0;
	ll root=0;
	for(i=1;i<=n;i++)
	{
		if(maxdegree<deg[i])
		{
			root=i;
			maxdegree=deg[i];
		}
		if(deg[i]>=3)
			number++;
	}
	if(maxdegree==1)
	{
		cout<<"Yes\n";
		cout<<"1\n";
		cout<<"1 2\n";
	}
	if(maxdegree==2)
	{
		cout<<"Yes\n";
		cout<<"1\n";
		cout<<func(ad[root][0],root)<<" "<<func(ad[root][1],root)<<endl;
		return 0;
	}
	vector<ll> ans;
	if(maxdegree>=3)
	{
		if(number>=2)
		{
			cout<<"No\n";
			return 0;
		}
		for(i=0;i<sz(ad[root]);i++)
			ans.pb(func(ad[root][i],root));
		cout<<"Yes\n";
		cout<<(sz(ans)+1)/2<<endl;
		for(i=0;i<sz(ans)-1;i+=2)
			cout<<ans[i]<<" "<<ans[i+1]<<endl;
		if(sz(ans)%2==1)
			cout<<ans[sz(ans)-1]<<" "<<root<<endl;
	}
	return 0;
}