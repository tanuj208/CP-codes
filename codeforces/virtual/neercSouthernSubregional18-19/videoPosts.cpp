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
	ll n,k;
	cin>>n>>k;
	vector<ll> a;
	ll i;
	ll sum=0;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
		sum+=val;
	}
	if(sum%k!=0)
	{
		cout<<"No\n";
		return 0;
	}
	sum/=k;
	vector<ll> ans(100005);
	ll j=0;
	ll cnt=0;
	ll sumVal=0;
	for(i=0;i<n;i++)
	{
		sumVal+=a[i];
		cnt++;
		if(sumVal==sum)
		{
			ans[j]=cnt;
			j++;
			cnt=0;
			sumVal=0;
		}
		else if(sumVal>sum)
		{
			cout<<"No\n";
			return 0;
		}
	}
	if(j!=k)
	{
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	for(i=0;i<k;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}