#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> factors[2000006];
vector<bool> isPrime(2000006,true);
vector<bool> erased(2000006,false);
set<ll> available;

void factorsCalc()
{
	ll i,j;
	for(i=2;i<=2000006;i++)
	{
		if(isPrime[i])
		{
			factors[i].pb(i);
			for(j=2*i;j<=2000006;j+=i)
			{
				factors[j].pb(i);
				isPrime[j]=false;
			}
		}
		available.insert(i);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> a;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	factorsCalc();
	ll flag=0;
	for(i=0;i<n;i++)
	{
		ll x;
		if(flag==0)
		{
			x=*(available.lower_bound(a[i]));
			if(x!=a[i])
				flag=1;
		}
		else
			x=*(available.begin());
		for(ll j=0;j<sz(factors[x]);j++)
		{
			ll q=factors[x][j];
			for(ll k=q;k<=2000000;k+=q)
			{
				if(!erased[k])
				{
					available.erase(k);
					erased[k]=true;
				}
			}
		}
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}