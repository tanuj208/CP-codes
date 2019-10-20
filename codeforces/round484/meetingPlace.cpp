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
vector<ll> visited(100005,0);
vector<ll> on(100005,0);
ll xx;
ll flag=0;
set<ll> possible;
ll cycles=0;

void dfs(ll v)
{
	ll i;
	visited[v]=1;
	on[v]=1;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(on[x]==1)
		{
			cout<<"-1\n";
			exit(0);
		}
		if(visited[x]==1)
		{
			flag=1;
			continue;
		}
		if(x==xx)
		{
			flag=1;
			continue;
		}
		dfs(x);
	}
	on[v]=0;
	return;
}

void dfs2(ll v)
{
	ll i;
	visited[v]=1;
	on[v]=1;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(possible.find(x)!=possible.end())
		{
			possible.insert(v);
			flag=1;
		}
		else
		{
			if(on[x]==1)
			{
				possible.insert(v);
				cycles++;
				continue;
			}
			if(visited[x]==1)
				continue;
			dfs2(x);
		}
	}
	return;
}

// ll mmmm=0;

// void dfs3(ll v,ll f,ll a)
// {
// 	if(f==0)
// 		possible.insert(v);
// 	else
// 		possible.erase(v);
// 	ll i;
// 	on[v]=1;
// 	visited[v]=1;
// 	for(i=0;i<sz(ad[v]);i++)
// 	{
// 		ll x=ad[v][i];
// 		if(on[x]==1)
// 		{
// 			if(mmmm==1)
// 			{
// 				if(possible.find(x)!=possible.end())
// 					dfs3(x,1,x);
// 			}
// 		}
// 		if(f==1 && x!=a)
// 		{
// 			dfs3()
// 		}
// 	}
// }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i;
	vector<ll> inDegree(100005,0);
	for(i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		inDegree[b]++;
	}
	ll out=0;
	ll in=0;
	vector<ll> z;
	for(i=1;i<=n;i++)
	{
		if(sz(ad[i])==0)
		{
			xx=i;
			out++;
		}
	}
	if(out!=1)
	{
		if(out>1)
		{
			cout<<"-1\n";
			return 0;
		}
		for(i=1;i<=n;i++)
		{
			if(inDegree[i]==0)
			{
				z.pb(i);
				in++;
			}
		}
		if(in!=0)
		{
			for(i=0;i<sz(z);i++)
			{
				flag=0;
				dfs2(z[i]);
				if(flag==0 || cycles>1)
				{
					cout<<"-1\n";
					return 0;
				}
			}
			if(sz(possible)==0)
			{
				cout<<"-1\n";
				return 0;
			}
			auto it=possible.begin();
			cout<<(*it)<<endl;
			return 0;
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				dfs2(i);
				if(flag==0 || cycles>1)
				{
					cout<<"-1\n";
					return 0;
				}
			}
			if(sz(possible)==0)
			{
				cout<<"-1\n";
				return 0;
			}
			auto it=possible.begin();
			cout<<(*it)<<endl;
			return 0;
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(inDegree[i]==0)
			{
				z.pb(i);
				in++;
			}
		}
		if(in==0)
		{
			cout<<"-1\n";
			return 0;
		}
		for(i=1;i<sz(z);i++)
		{
			flag=0;
			dfs(z[i]);
			if(flag==0)
			{
				cout<<"-1\n";
				return 0;
			}
		}
		cout<<xx<<endl;
		return 0;
	}
	return 0;
}