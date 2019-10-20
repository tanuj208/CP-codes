#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> a;
vector<ll> ans;
vector<ll> mark(105,0);
ll n;

void rec(ll i)
{
	if(i==n-1)
	{
		for(ll j=0;j<n;j++)
			cout<<ans[j]<<" ";
		cout<<endl;
		exit(0);
	}
	if(ans[i]%3==0)
	{
		ll j,x=-1;
		for(j=0;j<n;j++)
		{
			if(a[j]==ans[i]/3 && mark[j]==0)
			{
				x=j;
				break;
			}
		}
		if(x!=-1)
		{
			ans.pb(ans[i]/3);
			mark[x]=1;
			rec(i+1);
			mark[x]=0;
			ans.pop_back();
		}
	}
	ll j,x=-1;
	for(j=0;j<n;j++)
	{
		if(a[j]==ans[i]*2 && mark[j]==0)
		{
			x=j;
			break;
		}
	}
	if(x!=-1)
	{
		ans.pb(ans[i]*2);
		mark[x]=1;
		rec(i+1);
		mark[x]=0;
		ans.pop_back();
	}
	// if(i==1)
	// 	cout<<ans[1]<<endl;
	// cout<<i<<endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<n;i++)
	{
		ans.pb(a[i]);
		rec(0);
		ans.pop_back();
	}
	return 0;
}