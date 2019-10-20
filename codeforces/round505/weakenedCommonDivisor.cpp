#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll ans=0;
	ll i;
	ll a,b;
	cin>>a>>b;
	set<ll> p;
	for(i=2;i<=100000;i++)
	{
		if(a%i!=0)
			continue;
		p.insert(i);
		while(a%i==0)
			a/=i;
	}
	if(a!=1)
		p.insert(a);
	for(i=2;i<=100000;i++)
	{
		if(b%i!=0)
			continue;
		p.insert(i);
		while(b%i==0)
			b/=i;
	}
	if(b!=1)
		p.insert(b);
	set<ll> tmp;
	for(i=1;i<n;i++)
	{
		cin>>a>>b;
		for(auto it=p.begin();it!=p.end();it++)
		{
			ll x=*it;
			if(a%x==0 || b%x==0)
				tmp.insert(x);
		}
		p=tmp;
		tmp.clear();
	}
	if(sz(p)==0)
		cout<<"-1\n";
	else
		cout<<*p.begin()<<endl;
	return 0;
}