#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> goodPrime;
vector<ll> a,b;

void seive()
{
	ll i,j;
	bool isPrime[100005];
	for(i=0;i<=100004;i++)
		isPrime[i]=true;
	for(i=2;i<=100000;i++)
		for(j=2*i;j<=100000;j+=i)
			isPrime[j]=false;
	j=0;
	for(i=2;i<=100000;i++)
	{
		if(isPrime[i] && b[j]!=i)
			goodPrime.pb(i);
		else if(b[j]==i)
			j++;
	}
	return;
}

ll beauty(ll x)
{
	if(x==1)
		return 0;
	ll ans=0;
	ll i;
	for(i=0;i<sz(goodPrime);i++)
	{
		while(x%goodPrime[i]==0)
		{
			ans++;
			x/=goodPrime[i];
		}
		if(x<goodPrime[i])
			break;
	}
	for(i=0;i<sz(b);i++)
	{
		while(x%b[i]==0)
		{
			ans--;
			x/=b[i];
		}
		if(x<b[i])
			break;
	}
	if(x!=1)
	{
		if(binary_search(b.begin(),b.end(),x)==false)
			ans++;
		else
			ans--;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<m;i++)
	{
		cin>>val;
		b.pb(val);
	}
	seive();
	vector<ll> gcds;
	ll x=0;
	for(i=0;i<n;i++)
	{
		x=__gcd(x,a[i]);
		gcds.pb(x);
	}
	ll divide=1;
	for(i=n-1;i>=0;i--)
	{
		gcds[i]/=divide;
		if(beauty(gcds[i])<0)
			divide=divide*gcds[i];
		a[i]/=divide;
	}
	ll ans=0;
	for(i=0;i<n;i++)
		ans+=beauty(a[i]);
	cout<<ans<<endl;
	return 0;
}