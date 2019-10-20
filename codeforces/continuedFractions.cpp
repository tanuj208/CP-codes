#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

void reduce(ll *p, ll *q)
{
	ll x1=*p;
	ll x2=*q;
	ll x=__gcd(x1,x2);
	x1/=x;
	x2/=x;
	return;
}

pii sub(ll a, ll p, ll q)
{
	ll num=p-q*a;
	ll den=q;
	reduce(&num,&den);
	return mp(num,den);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll p,q;
	cin>>p>>q;
	reduce(&p,&q);
	ll n;
	cin>>n;
	ll i,val;
	vector<ll> c,m;
	for(i=0;i<n;i++)
	{
		cin>>val;
		c.pb(val);
	}
	ll num=p;
	ll den=q;
	while(true)
	{
		ll x=num/den;
		m.pb(x);
		pii tmp=sub(x,num,den);
		num=tmp.second;
		den=tmp.first;
		if(den==0)
			break;
	}
	ll flag=0;
	if(sz(m)>n)
		flag=1;
	for(i=0;i<n;i++)
	{
		if(i==sz(m))
		{
			flag=1;
			break;
		}
		if(c[i]!=m[i])
		{
			ll j,x=c[i];
			for(j=i+1;j<n;j++)
			{
				x+=c[j];
				if(c[j]!=1)
				{
					flag=1;
					break;
				}
			}
			if(m[i]!=x || i!=sz(m)-1)
				flag=1;
			break;
		}
	}
	if(flag==1)
		cout<<"NO\n";
	else
		cout<<"YES\n";
	return 0;
}