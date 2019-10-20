#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<ll> sm(1005,-1);
ll n;

ll sma(ll x)
{
	if(x>n)
		return x;
	if(sm[x]==-1)
		return x;
	sm[x]=sma(sm[x]);
	return sm[x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	vector<ll> x(1005,0);
	ll i;
	ll no=0;
	ll cnt=0;
	for(i=1;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		if(a==b)
			no=1;
		if(a!=n && b!=n)
			no=1;
		if(a==n)
			x[b]++;
		else
			x[a]++;
		if(a==1 || b==1)
			cnt++;
	}
	if(cnt>1 || no==1)
	{
		cout<<"NO\n";
		return 0;
	}
	ll cur=-1;
	vector<pii> ans;
	for(i=1;i<n;i++)
	{
		if(x[i]==0)
			continue;
		if(cur!=-1)
			ans.pb(mp(cur,i));
		cur=i;
		x[i]--;
		sm[i]=i+1;
		ll j=i;
		while(x[i]!=0)
		{
			j=sma(1);
			sm[j]=j+1;
			if(j>=i)
			{
				cout<<"NO\n";
				return 0;
			}
			ans.pb(mp(cur,j));
			cur=j;
			x[i]--;
		}
	}
	cout<<"YES\n";
	for(i=0;i<n-2;i++)
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	cout<<cur<<" "<<n<<endl;
	return 0;
}