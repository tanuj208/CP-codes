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
	ll n,q;
	cin>>n>>q;
	vector<ll> a;
	ll i,val;
	ll cnt=0;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
		if(val==q)
			cnt++;
	}
	if(cnt!=0)
	{
		if(a[0]==0)
			a[0]=1;
		for(i=1;i<n;i++)
			if(a[i]==0)
				a[i]=a[i-1];
	}
	else
	{
		ll flag=0;
		if(a[0]==0)
			a[0]=q,flag=1;
		for(i=1;i<n;i++)
		{
			if(a[i]==0 && flag==0)
				a[i]=q,flag=1;
			else if(a[i]==0)
				a[i]=a[i-1];
		}
	}
	vector<ll> w[200005];
	ll req=1;
	for(i=0;i<n;i++)
		w[a[i]].pb(i);
	set<ll> x;
	ll j;
	i=1;
	while(sz(w[i])==0)
		i++;
	for(j=0;j<sz(w[i]);j++)
		x.insert(w[i][j]);
	if(sz(w[q])==0 && sz(w[0])==0)
	{
		cout<<"NO\n";
		return 0;
	}
	for(i=i+1;i<=q;i++)
	{
		if(sz(w[i])==0)
			continue;
		auto it=x.lower_bound(w[i][0]);
		if(it!=x.end() && (*it)<w[i][sz(w[i])-1])
		{
			cout<<"NO\n";
			exit(0);
		}
		for(j=0;j<sz(w[i]);j++)
			x.insert(w[i][j]);
	}
	cout<<"YES\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}