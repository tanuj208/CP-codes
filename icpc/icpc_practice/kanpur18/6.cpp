#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()


typedef long long ll;
typedef pair<ll,ll> pii;
std::vector<ll> v;
std::vector<ll> len;
ll solve(ll f,ll i)
{
	if(i<len[f-1])
		return solve(f-1,i);
	if(i==len[f-1])
		return v[f-2];
	return solve(f-2,i-len[f-1]-1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	v.pb(1);
	len.pb(0);
	v.pb(2);
	v.pb(3);
	len.pb(0);
	ll x=2;
	while(1)
	{
		v.pb(v[x]+v[x-1]);
		x++;
		len.pb(v[x]-v[x-1]-1);
		if(v[x]>1e10)
			break;
	}
	while(1)
	{
		ll n;
		cin>>n;
		if(n==0)
			break;
		if(n==1)
		{
			cout<<"D\n";
			continue;
		}
		ll p=(ll)(upper_bound(v.begin(),v.end(),n)-v.begin());
		p--;
		if(v[p]==n)
		{
			cout<<"L\n";
			continue;
		}
		cout<<solve(p,n-v[p]-1)<<"\n";
	}
	return 0;
}