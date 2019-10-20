#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> val(1000005,-1);
vector<ll> mark(1000005,0); // -1 -> AND -2->OR -3->XOR
vector<ll> ad[1000005];
ll ans[1000005][2];
ll n;

void dfs(ll v)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		dfs(x);
	}
	if(sz(ad[v])==1)
		val[v]=val[ad[v][0]]^1;
	if(sz(ad[v])==2)
	{
		if(mark[v]==-1)
			val[v]=val[ad[v][0]]&val[ad[v][1]];
		else if(mark[v]==-2)
			val[v]=val[ad[v][0]]|val[ad[v][1]];
		else
			val[v]=val[ad[v][0]]^val[ad[v][1]];
	}
	return;
}

ll calculate(ll v,ll vall,ll i)
{
	if(mark[v]==0)
		return vall^1;
	ll other;
	if(ad[v][0]==i)
		other=val[ad[v][1]];
	else
		other=val[ad[v][0]];
	if(mark[v]==-1)
		return vall&other;
	else if(mark[v]==-2)
		return vall|other;
	else
		return vall^other;
}

void dfs2(ll v)
{
	ll i;
	if(sz(ad[v])==1)
	{
		ll x=ad[v][0];
		ans[x][0]=ans[v][1];
		ans[x][1]=ans[v][0];
		dfs2(x);
	}
	if(sz(ad[v])==2)
	{
		ll x1=ad[v][0];
		ll x2=ad[v][1];
		ans[x1][0]=ans[v][calculate(v,0,x1)];
		ans[x1][1]=ans[v][calculate(v,1,x1)];
		dfs2(x1);
		ans[x2][0]=ans[v][calculate(v,0,x2)];
		ans[x2][1]=ans[v][calculate(v,1,x2)];
		dfs2(x2);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i;
	ans[1][1]=1;
	ans[1][0]=0;
	vector<ll> calculation;
	for(i=1;i<=n;i++)
	{
		string s;
		ll a,b;
		cin>>s>>a;
		if(s=="IN")
		{
			val[i]=a;
			calculation.pb(i);
		}
		else if(s=="NOT")
		{
			val[i]=-4;
			ad[i].pb(a);
		}
		else
		{
			cin>>b;
			if(s=="OR")
				mark[i]=-2;
			else if(s=="XOR")
				mark[i]=-3;
			else
				mark[i]=-1;
			ad[i].pb(a);
			ad[i].pb(b);
		}
	}
	dfs(1);
	dfs2(1);
	for(i=0;i<sz(calculation);i++)
		cout<<ans[calculation[i]][val[calculation[i]]^1];
	cout<<endl;
	return 0;
}