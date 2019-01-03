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
	ll n;
	cin>>n;
	vector<ll> a;
	ll i;
	for(i=0;i<n/2;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	vector<ll> fac[200005];
	ll j;
	for(i=1;i<=200000;i++)
		for(j=2*i;j<=200000;j+=i)
			fac[j].pb(i);

	vector<ll> poss[100005];
	for(i=0;i<n/2;i++)
	{
		ll x=a[i];
		for(j=0;j<sz(fac[x]);j++)
		{
			ll tmp=x;
			ll factorr=fac[x][j];
			if(tmp%factorr!=0)
				continue;
			tmp/=factorr;
			tmp-=factorr;
			if(tmp>0 && tmp%2==0)
				poss[i].pb(tmp/2);
		}
	}
	ll prev=0;
	vector<ll> ans;
	for(i=0;i<n/2;i++)
	{
		sort(poss[i].begin(),poss[i].end());
		if(sz(poss[i])==0)
		{
			cout<<"No\n";
			return 0;
		}
		bool flag=false;
		for(j=0;j<sz(poss[i]);j++)
		{
			if(poss[i][j]>prev)
			{
				flag=true;
				ans.pb((poss[i][j]*poss[i][j]) - prev*prev);
				ans.pb(a[i]);
				prev=sqrt(poss[i][j]*poss[i][j]+a[i]);
				break;
			}
		}
		if(!flag)
		{
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}