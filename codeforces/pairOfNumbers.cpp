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
ll mindp[300005][30];
ll gcddp[300005][30];
ll n;
vector<ll> ans;

void preProcessing()
{
	ll i,j;
	for(i=0;i<=300000;i++)
		for(j=0;j<=25;j++)
			mindp[i][j]=LLONG_MAX,gcddp[i][j]=0;
	for(i=0;i<n;i++)
		mindp[i][0]=a[i],gcddp[i][0]=a[i];
	for(j=1;j<=25;j++)
	{
		for(i=0;i<n;i++)
		{
			if(i+(1<<(j-1))<n)
				mindp[i][j]=min(mindp[i][j-1],mindp[i+(1<<(j-1))][j-1]);
			if(i+(1<<(j-1))<n)
				gcddp[i][j]=__gcd(gcddp[i][j-1],gcddp[i+(1<<(j-1))][j-1]);
		}
	}
	return;
}

bool query(ll l,ll r)
{
	if(r>=n)
		return false;
	if(l==r)
		return true;
	ll j;
	ll minans=LLONG_MAX;
	ll gcdans=0;
	ll fuck=0;
	for(j=25;j>=0;j--)
	{
		if(l+(1<<j)<=r)
		{
			minans=min(minans,mindp[l][j]);
			gcdans=__gcd(gcdans,gcddp[l][j]);
			l=l+(1<<j);
		}
	}
	minans=min(minans,a[r]);
	gcdans=__gcd(gcdans,a[r]);
	if(minans==gcdans)
		return true;
	else
		return false;
}

bool possible(ll x)
{
	ll i;
	ll flag=0;
	for(i=0;i<n;i++)
	{
		if(query(i,i+x-1)==true)
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	preProcessing();
	ll l=1;
	ll r=n;
	ll mid=(l+r)/2;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(possible(mid)==true)
			l=mid+1;
		else
			r=mid-1;
	}
	while(possible(mid)==false)
		mid--;
	for(i=0;i<n;i++)
		if(query(i,i+mid-1)==true)
			ans.pb(i+1);
	cout<<sz(ans)<<" "<<mid-1<<endl;
	for(i=0;i<sz(ans);i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}