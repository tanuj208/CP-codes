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
	ll t;
	cin>>t;
	ll i,j;
	vector<ll> div[200005];
	for(i=2;i<=200000;i++)
		for(j=2*i;j<=200000;j+=i)
			div[j].pb(i);
	ll z=1;
	for(z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		ll n;
		cin>>n;
		vector<ll> cnt(200005,0);
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			cnt[val]++;
		}
		ll ans=0;
		for(i=200000;i>=2;i--)
		{
			if(cnt[i]==0)
				continue;
			if(cnt[i]>1 && cnt[1]>0)
				ans+=cnt[1]*(((cnt[i]-1)*(cnt[i]))/2);
			for(j=0;j<sz(div[i]);j++)
			{
				ll x=div[i][j];
				ll y=i/x;
				if(x>y)
					break;
				if(x==y)
				{
					if(cnt[x]>=2)
						ans+=cnt[i]*(((cnt[x])*(cnt[x]-1))/2);
					break;
				}
				ans+=cnt[i]*cnt[x]*cnt[y];
			}
		}
		if(cnt[1]>=3)
			ans+=((cnt[1])*(cnt[1]-1)*(cnt[1]-2))/6;
		if(cnt[0]>=2)
			ans+=(n-cnt[0])*((cnt[0])*(cnt[0]-1))/2;
		if(cnt[0]>=3)
			ans+=((cnt[0])*(cnt[0]-1)*(cnt[0]-2))/6;
		cout<<ans<<"\n";
	}
	return 0;
}