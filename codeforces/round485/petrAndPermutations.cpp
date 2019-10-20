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
	vector<ll> a;
	vector<ll> pos(1000005,0);
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
		pos[val]=i;
	}
	ll swaps=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==i+1)
			continue;
		ll ind=pos[i+1];
		pos[a[i]]=ind;
		pos[i+1]=i;
		a[ind]=a[i];
		a[i]=i+1;
		swaps++;
	}
	if(n%2==0)
	{
		if(swaps%2==0)
			cout<<"Petr\n";
		else
			cout<<"Um_nik\n";
	}
	else
	{
		if(swaps%2==0)
			cout<<"Um_nik\n";
		else
			cout<<"Petr\n";
	}
	return 0;
}