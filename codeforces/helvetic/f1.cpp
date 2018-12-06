#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll desired[1005];
ll got[1005];
ll n,m;

bool compare()
{
	ll i;
	for(i=1;i<=m;i++)
	{
		if(desired[i]!=got[i])
			return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll knights[1005];
	ll i;
	ll sum=0;
	for(i=0;i<n;i++)
		cin>>knights[i];
	for(i=1;i<=m;i++)
	{
		cin>>desired[i];
		sum+=desired[i];
	}
	for(i=0;i<sum;i++)
	{
		got[knights[i]]++;
	}
	if(compare()==true)
	{
		cout<<"YES\n";
		return 0;
	}
	ll j=0;
	for(i=sum;i<n;i++)
	{
		got[knights[i]]++;
		got[knights[j]]--;
		if(compare()==true)
		{
			cout<<"YES\n";
			return 0;
		}
		j++;
	}
	cout<<"NO\n";
	return 0;
}