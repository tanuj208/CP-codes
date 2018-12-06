#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n,w;
vector<ll> a;

bool validUpper(ll t)
{
	ll i;
	if(t>w)
		return false;
	for(i=0;i<n;i++)
	{
		t+=a[i];
		if(t>w)
			return false;
	}
	return true;
}

bool validLower(ll t)
{
	ll i;
	if(t<0)
		return false;
	for(i=0;i<n;i++)
	{
		t+=a[i];
		if(t<0)
			return false;
	}
	return true;
}

ll searchUpper(ll l,ll r)
{
	if(l>=r)
	{
		if(validUpper(l)==true)
			return l; 
		else
			return l-1;
	}
	ll mid=(l+r)/2;
	if(validUpper(mid)==true)
		searchUpper(mid+1,r);
	else
		searchUpper(l,mid-1);
}

ll searchLower(ll l,ll r)
{
	if(l>=r)
	{
		if(validLower(l)==true)
			return l;
		else
			return l+1;
	}
	ll mid=(l+r)/2;
	if(validLower(mid)==false)
		searchLower(mid+1,r);
	else
		searchLower(l,mid-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>w;
	ll val,i;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	ll a=searchLower(0,1000000000);
	ll b=searchUpper(0,1000000000);
	ll ans=b-a+1;
	if(ans>0)
		cout<<ans<<endl;
	else
		cout<<"0\n";
	return 0;
}