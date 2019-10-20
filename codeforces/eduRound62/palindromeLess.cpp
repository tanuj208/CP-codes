#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

// priority_queue <ll,vector<ll>,greater<ll> > p;

typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=998244353;

ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	ll i;
	vector<ll> a;
	vector<ll> b(n+1,k);
	vector<ll> flag(n+1, false);
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<n;i++)
	{
		if(i+2 >=n)
			break;
		if(a[i]==a[i+2] && a[i]!=-1)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	if(n==2)
	{
		ll cnt=0;
		if(a[0]==-1)
			cnt++;
		if(a[1]==-1)
			cnt++;
		cout<<power(k,cnt)<<endl;
		return 0;
	}
	else if(n==3)
	{
		ll ans=1;
		if(a[0]==-1 && a[2]==-1)
			ans=(k*(k-1))%mod;
		else if(a[0] == -1 || a[2] == -1)
			ans = (k-1)%mod;
		if(a[1]==-1)
			ans=(ans*k)%mod;
		cout<<ans<<endl;
		return 0;
	}
	ll dp1[200005]={0}; // a!=b
	ll dp2[200005]={0};
	dp1[1]=k-2;
	ll ans=1;
	dp2[1]=k-1;
	for(i=2;i<=200000;i++)
	{
		dp1[i]=(power(k-1, i) - dp1[i-1] + mod)%mod;
		dp2[i]=(power(k-1, i) - dp2[i-1] + mod)%mod;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]!=-1)
			continue;
		if(i+2 >=n)
		{
			if((i-2)<0)
			{
				ans  = (ans * k)%mod;
				a[i]=0;
			}
			else if(a[i-2]!=-1)
			{
				ans=(ans*(k-1))%mod;
				a[i]=0;
			}
		}
		else if(a[i+2]!=-1)
		{
			if((i-2)<0)
			{
				a[i]=0;
				ans=(ans*(k-1))%mod;
			}
			else if(a[i-2]==a[i+2])
			{
				a[i]=0;
				ans=(ans*(k-1))%mod;
			}
			else if(a[i-2]!=-1)
			{
				a[i]=0;
				ans=(ans*(k-2))%mod;
			}
		}
	}
	ll cnt=0;
	i=0;
	while(i<n && a[i]==-1)
	{
		cnt++;
		a[i]=0;
		i+=2;
	}
	if(i>=n)
	{
		ans=(ans*k)%mod;
		ans=(ans*power(k-1, cnt-1))%mod;
	}
	else
		ans=(ans*power(k-1, cnt))%mod;

	cnt=0;
	i=1;
	while(i<n && a[i]==-1)
	{
		cnt++;
		a[i]=0;
		i+=2;
	}
	if(i>=n)
	{
		ans=(ans*k)%mod;
		ans=(ans*power(k-1, cnt-1))%mod;
	}
	else
		ans=(ans*power(k-1, cnt))%mod;

	cnt=0;
	i=n-1;
	while(i>=0 && a[i]==-1)
	{
		cnt++;
		a[i]=0;
		i-=2;
	}
	if(i<0)
	{
		ans=(ans*k)%mod;
		ans=(ans*power(k-1, cnt-1))%mod;
	}
	else
		ans=(ans*power(k-1, cnt))%mod;

	cnt=0;
	i=n-2;
	while(i>=0 && a[i]==-1)
	{
		cnt++;
		a[i]=0;
		i-=2;
	}
	if(i<0)
	{
		ans=(ans*k)%mod;
		ans=(ans*power(k-1, cnt-1))%mod;
	}
	else
		ans=(ans*power(k-1, cnt))%mod;

	for(i=0;i<n;i+=2)
	{
		if(a[i]==-1)
		{
			ll ax=a[i-2];
			cnt=0;
			while(a[i]==-1)
			{
				cnt++;
				i+=2;
			}
			if(a[i]==ax)
				ans=(ans * dp2[cnt])%mod;
			else
				ans=(ans*dp1[cnt])%mod;
		}
	}
	for(i=1;i<n;i+=2)
	{
		if(a[i]==-1)
		{
			ll ax=a[i-2];
			cnt=0;
			while(a[i]==-1)
			{
				cnt++;
				i+=2;
			}
			if(a[i]==ax)
				ans=(ans * dp2[cnt])%mod;
			else
				ans=(ans*dp1[cnt])%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}