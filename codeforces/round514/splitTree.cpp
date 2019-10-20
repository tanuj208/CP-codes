#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> w(100005),p(100005);
vector<ll> sp(100005,0);
vector<ll> ad[100005];
vector<ll> nextt(100005,-1);
ll n,l,s;
ll ans=0;

bool dfs(ll v,ll remWt,ll remLen,ll flag)
{
	ll i;
	ll ind=-1;
	if(flag==1 && (remLen<=0 || remWt<=w[v]))
		return false;
	if(flag==1 && sp[v]==1)
	{
		if(remLen>0 && remWt>w[v])
			return true;
		else
			return false;
	}
	if(nextt[v]==-1)
	{
		for(i=0;i<sz(ad[v]);i++)
		{
			if(dfs(ad[v][i], remWt-w[v], remLen-1, 1))
			{
				ind=i;
				break;
			}
		}
		if(flag==1)
		{
			if(ind==-1)
				return false;
			else
			{
				nextt[v]=ind;
				return true;
			}
		}
	}
	if(nextt[v]!=-1 && flag==1)
		return true;
	if(nextt[v]!=-1)
		ind=nextt[v];
	for(i=0;i<sz(ad[v]);i++)
	{
		if(i==ind)
			bool tmp=dfs(ad[v][i], remWt-w[v], remLen-1, 0);
		else
		{
			ans++;
			bool tmp=dfs(ad[v][i],s,l,0);
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>l>>s;
	ll i,j;
	ll exit=0;
	for(i=1;i<=n;i++)
	{
		cin>>w[i];
		if(w[i]>s)
			exit=1;
	}
	for(i=2;i<=n;i++)
	{
		cin>>p[i];
		ad[p[i]].pb(i);
	}
	if(exit==1)
	{
		cout<<"-1\n";
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(sz(ad[i])==0)
			sp[i]=1;
		else
		{
			ll flag=0;
			for(j=0;j<sz(ad[i]);j++)
			{
				if(w[i]+w[ad[i][j]]<=s)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
				sp[i]=1;
		}
	}
	ans=1;
	bool xx=dfs(1,s,l,0);
	cout<<ans<<endl;
	return 0;
}