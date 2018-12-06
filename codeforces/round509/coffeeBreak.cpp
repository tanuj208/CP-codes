#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<ll> ne(200005,-1);

ll nn(ll x)
{
	if(ne[x]==-1)
		return x;
	ne[x]=nn(ne[x]);
	return ne[x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,d;
	cin>>n>>m>>d;
	ll i,val;
	vector<ll> a;
	vector<pii> b;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
		b.pb(mp(val,i));
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	vector<ll> ans(200005,-1);
	ll cur=1;
	for(i=0;i<n;i++)
	{
		i=nn(i);
		if(i==n)
			break;
		ans[b[i].second]=cur;
		ne[i]=i+1;
		ll x=a[i];
		ll j=lower_bound(a.begin(),a.end(),x+d+1)-a.begin();
		j=nn(j);
		while(j<n)
		{
			ans[b[j].second]=cur;
			x=a[j];
			ne[j]=j+1;
			j=lower_bound(a.begin(),a.end(),x+d+1)-a.begin();
			j=nn(j);
		}
		cur++;
	}
	cur=0;
	for(i=0;i<n;i++)
		cur=max(cur,ans[i]);
	cout<<cur<<endl;
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;	
	return 0;
}