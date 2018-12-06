#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

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
	ll n,q;
	cin>>n>>q;
	vector<ll> a;
	ll i,j;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	vector<ll> dp(1005,0);
	for(i=2;i<=n;i++)
	{
		for(j=2*i;j<=n;j+=i);
		j-=i;
		dp[i]=j;
	}
	vector<ll> ans[1005];

	while(q--)
	{
		ll x;
		cin>>x;
		cout<<"YES\n";
		if(x==1)
		{
			cout<<a[0]<<endl;
			continue;
		}
		x=dp[x];
		if(sz(ans[x])!=0)
		{
			for(i=0;i<sz(ans[x]);i++)
				cout<<ans[x][i]<<" ";
			cout<<endl;
			continue;
		}
		for(i=0;i<n;i++)
		{
			ll s=0;
			ll e=0;
			for(j=i;j<n;j++)
			{
				s+=a[j];
				if(s%x==0)
				{
					for(ll k=i;k<=j;k++)
						ans[x].pb(a[k]);
					e=1;
					break;
				}
			}
			if(e==1)
				break;
		}
		for(i=0;i<sz(ans[x]);i++)
			cout<<ans[x][i]<<" ";
		cout<<endl;
	}
	return 0;
}