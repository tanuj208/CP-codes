#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<pii> child(2005);
vector<ll> arr1,arr2;
vector<ll> p(2005,-1);
vector<ll> c(2005,1);

void preOrder(ll v)
{
	if(v==0)
		return;
	arr1.pb(v);
	preOrder(child[v].first);
	preOrder(child[v].second);
	return;
}

void postOrder(ll v)
{
	if(v==0)
		return;
	postOrder(child[v].first);
	postOrder(child[v].second);
	arr2.pb(v);
	return;
}

ll parent(ll v)
{
	if(p[v]==-1)
		return v;
	p[v]=parent(p[v]);
	return p[v];
}

void dsu(ll v1,ll v2)
{
	ll x1=parent(v1);
	ll x2=parent(v2);
	if(x1!=x2)
	{
		if(c[x1]<c[x2])
		{
			p[x1]=x2;
			c[x2]+=c[x1];
		}
		else
		{
			p[x2]=x1;
			c[x1]+=c[x2];
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll q;
	for(q=1;q<=t;q++)
	{
		ll n,k;
		cin>>n>>k;
		ll i;
		for(i=1;i<=n;i++)
		{
			ll a,b;
			cin>>a>>b;
			child[i]=mp(a,b);
		}
		cout<<"Case #"<<q<<": ";
		arr1.clear();
		arr2.clear();
		preOrder(1);
		postOrder(1);
		for(i=0;i<=2000;i++)
			p[i]=-1,c[i]=1;
		vector<ll> ans(2005,0);
		for(i=0;i<n;i++)
			if(arr1[i]!=arr2[i])
				dsu(arr1[i],arr2[i]);
		ll cnt=1;
		for(i=1;i<=n;i++)
		{
			ll x=parent(i);
			if(ans[x]==0)
			{
				ans[x]=cnt;
				ans[i]=cnt;
				cnt++;
			}
			else
				ans[i]=ans[x];
		}
		cnt--;
		if(cnt<k)
			cout<<"Impossible\n";
		else
		{
			for(i=1;i<=n;i++)
			{
				if(ans[i]>k)
					cout<<"1 ";
				else
					cout<<ans[i]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}