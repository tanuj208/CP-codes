#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n;
vector<ll> a;
vector<ll> dp(100005,-1);

void func(ll x)
{
	if(dp[x]!=-1)
		return;
	ll i;
	ll flag=0;
	for(i=x+a[x];i<n;i+=a[x])
	{
		if(a[i]<=a[x])
			continue;
		if(dp[i]==-1)
			func(i);
		if(dp[i]==0)
			flag=1;
	}
	for(i=x-a[x];i>=0;i-=a[x])
	{
		if(a[i]<=a[x])
			continue;
		if(dp[i]==-1)
			func(i);
		if(dp[i]==0)
			flag=1;
	}
	if(flag==1)
		dp[x]=1;
	else
		dp[x]=0;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll i,val;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<n;i++)
		func(i);
	for(i=0;i<n;i++)
	{
		if(dp[i]==0)
			cout<<"B";
		else
			cout<<"A";
	}
	cout<<endl;
	return 0;
}