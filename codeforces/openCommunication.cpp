#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<pii> a,b;

bool ffind(ll num,ll other,ll flag)
{
	ll i;
	vector<pii> tmp;
	if(flag==1)
		tmp=a;
	else
		tmp=b;
	for(i=0;i<sz(tmp);i++)
	{
		ll x1=tmp[i].first;
		ll x2=tmp[i].second;
		if(x1==num && x2!=other)
			return true;
		if(x2==num && x1!=other)
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		a.pb(mp(x,y));
	}
	for(i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		b.pb(mp(x,y));
	}
	set<ll> c;
	for(i=0;i<n;i++)
	{
		ll j;
		ll x1=a[i].first;
		ll x2=a[i].second;
		for(j=0;j<m;j++)
		{
			ll y1=b[j].first;
			ll y2=b[j].second;
			if(x1==y1 && x2!=y2)
				c.insert(x1);
			else if(x1==y2 && x2!=y1)
				c.insert(x1);
			else if(x2==y1 && x1!=y2)
				c.insert(x2);
			else if(x2==y2 && x1!=y1)
				c.insert(x2);
		}
	}
	if(sz(c)==1)
	{
		cout<<(*c.begin())<<endl;
		return 0;
	}
	for(i=0;i<n;i++)
	{
		ll j;
		ll x1=a[i].first;
		ll x2=a[i].second;
		for(j=0;j<m;j++)
		{
			ll y1=b[j].first;
			ll y2=b[j].second;
			if(x1==y1 && x2!=y2)
			{
				if(ffind(x2,x1,0)==true)
				{
					cout<<"-1\n";
					return 0;
				}
			}
			else if(x1==y2 && x2!=y1)
			{
				c.insert(x1);
				if(ffind(x2,x1,0)==true)
				{
					cout<<"-1\n";
					return 0;
				}
			}
			else if(x2==y1 && x1!=y2)
			{
				c.insert(x2);
				if(ffind(x1,x2,0)==true)
				{
					cout<<"-1\n";
					return 0;
				}
			}
			else if(x2==y2 && x1!=y1)
			{
				c.insert(x2);
				if(ffind(x1,x2,0)==true)
				{
					cout<<"-1\n";
					return 0;
				}
			}
		}
	}
	for(i=0;i<m;i++)
	{
		ll j;
		ll x1=b[i].first;
		ll x2=b[i].second;
		for(j=0;j<n;j++)
		{
			ll y1=a[j].first;
			ll y2=a[j].second;
			if(x1==y1 && x2!=y2)
			{
				if(ffind(x2,x1,1)==true)
				{
					cout<<"-1\n";
					return 0;
				}
			}
			else if(x1==y2 && x2!=y1)
			{
				c.insert(x1);
				if(ffind(x2,x1,1)==true)
				{
					cout<<"-1\n";
					return 0;
				}
			}
			else if(x2==y1 && x1!=y2)
			{
				c.insert(x2);
				if(ffind(x1,x2,1)==true)
				{
					cout<<"-1\n";
					return 0;
				}
			}
			else if(x2==y2 && x1!=y1)
			{
				c.insert(x2);
				if(ffind(x1,x2,1)==true)
				{
					cout<<"-1\n";
					return 0;
				}
			}
		}
	}
	cout<<"0\n";
	return 0;
}