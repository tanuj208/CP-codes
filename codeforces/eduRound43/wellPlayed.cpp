#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll hp[200006];
vector<pii> df;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,a,b;
	cin>>n>>a>>b;
	ll i;
	ll sum=0;
	for(i=0;i<n;i++)
	{
		ll x;
		cin>>hp[i]>>x;
		sum+=x;
		df.pb(mp(hp[i]-x,i));
	}
	ll x=((ll)1<<a)-1;
	ll mx=LLONG_MIN;
	ll ind=-1;
	for(i=0;i<n;i++)
	{
		if(mx<x*hp[i]+df[i].first)
		{
			mx=x*hp[i]+df[i].first;
			ind=i;
		}
	}
	sort(df.begin(),df.end());
	reverse(df.begin(),df.end());
	if(b==0)
	{
		cout<<sum<<endl;
		return 0;
	}
	if(mx>0)
	{
		sum+=mx;
		b--;
	}
	if(b==0)
	{
		cout<<sum<<endl;
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(b==0)
			break;
		if(df[i].first<=0)
			break;
		if(df[i].second==ind)
			continue;
		sum += df[i].first;
		b--;
	}
	cout<<sum<<endl;
	return 0;
}