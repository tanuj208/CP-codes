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
	ll n,m,q;
	cin>>n>>m>>q;
	vector<ll> a,b;
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
	vector<ll> pre;
	ll temp=0;
	ll x=0;
	for(i=0;i<n;i++)
	{
		if(i%2==1)
		{
			temp+=b[i];
			x-=a[i];
		}
		else
		{
			temp-=b[i];
			x+=a[i];
		}
	}
	pre.pb(temp);
	for(i=0;i<m-n;i++)
	{
		temp+=b[i];
		temp=-temp;
		if(n%2==0)
			temp+=b[i+n];
		else
			temp-=b[i+n];
		pre.pb(temp);
	}
	sort(pre.begin(),pre.end());
	ll w=-x;
	ll v=lower_bound(pre.begin(),pre.end(),w)-pre.begin();
	if(v==sz(pre))
		v--;
	ll ans=min(abs(x+pre[v]),abs(x+pre[v-1]));
	cout<<ans<<"\n";
	while(q--)
	{
		ll l,r,t;
		cin>>l>>r>>t;
		if(l%2==0)
			x-=t;
		if(r%2==1)
			x+=t;
		w=-x;
		v=lower_bound(pre.begin(),pre.end(),w)-pre.begin();
		if(v==sz(pre))
			v--;
		ans=min(abs(x+pre[v]),abs(x+pre[v-1]));
		cout<<ans<<"\n";
	}
	return 0;
}