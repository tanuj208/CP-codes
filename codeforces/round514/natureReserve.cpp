#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll fac=1000000;
ll n;
vector<pii> c;

bool checkDistance(ll x,ll y,ll x1,ll y1)
{
	long double a,b,cc,d;
	a=(double)x/fac;
	b=(double)y/fac;
	cc=(double)x1/fac;
	d=(double)y1/fac;
	if((a-cc)*(a-cc)+(b-d)*(b-d)>b*b)
		return false;
	else
		return true;
}

ll check(ll x,ll y)
{
	ll i;
	ll returnVal=0;
	for(i=0;i<n;i++)
	{
		bool xx=checkDistance(x,y,c[i].first,c[i].second);
		if(!xx)
		{
			if((c[i].first<x && returnVal==2) || (c[i].first>x && returnVal==1))
				return -1;
			if(c[i].first<x)
				returnVal=1;
			if(c[i].first>x)
				returnVal=2;
			if(c[i].first==x)
				return -1;
		}
	}
	return returnVal;
}

bool valid(ll rad)
{
	ll l=-fac*fac*10;
	ll r=fac*fac*10;
	ll m=(l+r)/2;
	while(l<r)
	{
		m=(l+r)/2;
		ll x=check(m,rad);
		if(x==0)
			return true;
		else if(x==1)
			r=m-1;
		else if(x==2)
		{
			l=m+1;
		}
		else if(x==-1)
			return false;
	}
	if(check(m,rad)!=0 && check(l,rad)!=0)
		return false;
	else
		return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i;
	ll pos=0,exit=0;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		x*=fac;
		y*=fac;
		if((y>0 && pos<0) || (y<0 && pos>0))
			exit=1;
		if(y>0)
			pos=1;
		if(y<0)
			pos=-1;
		c.pb(mp(x,y));
	}
	if(exit==1)
	{
		cout<<"-1\n";
		return 0;
	}
	ll l=0;
	ll r=fac*fac*10;
	ll m=(l+r)/2;
	while(l<r)
	{
		m=(l+r)/2;
		if(valid(m))
			r=m-1;
		else
			l=m+1;
	}
	if(valid(m))
	{
		double ans=(double)m/fac;
		printf("%.6lf\n",ans);
	}
	else
	{
		double ans=(double)l/fac;
		printf("%.6f\n",ans);
	}
	return 0;
}