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

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


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

vector<ll> ad[100005];
queue<pii> q;
vector<ll> deg(100005,0);
vector<ll> vis(100005,0);
vector<ll> val(100005,0);
vector<ll> vis2(100005,0);
ll n,k;

bool check(ll v)
{
	ll i;
	vis2[v]=1;
	ll checkk=0;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(vis2[x]==1)
			continue;
		val[x]=val[v]+1;
		if(!check(x))
			checkk=1;
	}
	if(checkk==1)
		return false;
	if(sz(ad[v])==1 && val[v]!=k)
		return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	ll i;
	for(i=1;i<n;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(v);
		ad[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	ll f=0;
	ll countt=0;
	for(i=1;i<=n;i++)
	{
		if(deg[i]==1)
		{
			q.push(mp(i,0));
			vis[i]=1;
		}
		else
		{
			if(deg[i]<=2)
			{
				f=-1;
				break;
			}
		}
		if(deg[i]==3)
		{
			countt++;
		}
	}
	if(f==-1 || countt>1)
	{
		cout<<"No\n";
		return 0;
	}
	while(!q.empty())
	{
		ll v=q.front().first;
		ll cntr=q.front().second;
		q.pop();
		ll cnt=0;
		for(i=0;i<sz(ad[v]);i++)
		{
			ll x=ad[v][i];
			if(vis[x]==1)
				continue;
			vis[x]=1;
			cnt++;
			q.push(mp(x,cntr+1));
		}
		if(sz(q)==1)
			break;
	}
	ll xx=q.front().first;
	if(deg[xx]!=3 && countt==1)
	{
		cout<<"No\n";
		return 0;
	}
	if(check(xx))
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}