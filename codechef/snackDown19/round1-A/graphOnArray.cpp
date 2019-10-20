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

vector<ll> ad[55];
vector<ll> vis(55,0);

void dfs(ll v)
{
	if(vis[v]==1)
		return;
	vis[v]=1;
	ll i;
	for(i=0;i<sz(ad[v]);i++)
		dfs(ad[v][i]);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll i,j;
		for(i=0;i<=50;i++)
		{
			ad[i].clear();
			vis[i]=0;
		}
		vector<ll> a;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(__gcd(a[i],a[j])==1)
				{
					ad[i].pb(j);
					ad[j].pb(i);
				}
			}
		}
		dfs(0);
		bool x=true;
		for(i=0;i<n;i++)
			if(vis[i]!=1)
				x=false;
		if(x)
		{
			cout<<"0\n";
			for(i=0;i<n;i++)
				cout<<a[i]<<" ";
			cout<<"\n";
		}
		else
		{
			cout<<"1\n";
			ll flag=0;
			for(i=0;i<n;i++)
			{
				if(a[i]!=47)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				a[0]=47;
			else
				a[0]=2;
			for(i=0;i<n;i++)
				cout<<a[i]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}