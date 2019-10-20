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
	ll mat[n+5][n+5];
	ll i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>mat[i][j];
	vector<ll> gcds;
	vector<ll> row_sums;
	for(i=0;i<n;i++)
	{
		ll gcd = -1;
		ll s=0;
		for(j=0;j<n;j++)
		{
			s+=mat[i][j];
			if(j!=i)
			{
				if(gcd==-1)
					gcd=mat[i][j];
				else
					gcd=__gcd(gcd, mat[i][j]);
			}
		}
		row_sums.pb(s);
		gcds.pb(gcd);
	}
	vector<ll> divs;
	for(i=1;i<=sqrt(gcds[0]);i++)
	{
		if(gcds[0]%i==0)
		{
			divs.pb(i);
			divs.pb(gcds[0]/i);
		}
	}
	for(i=0;i<sz(divs);i++)
	{
		ll x=divs[i];
		// cout<<x<<endl;
		ll sum=x;
		vector<ll> nums;
		nums.pb(x);
		bool ans=true;
		for(j=1;j<n;j++)
		{
			ll no=mat[0][j]/x;
			if(gcds[j]%no!=0)
			{
				ans=false;
				break;
			}
			sum+=no;
			nums.pb(no);
		}
		if(ans)
		{
			for(j=0;j<n;j++)
			{
				if(nums[j] > 1e18/sum)
				{
					ans=false;
					break;
				}
				if(nums[j] > 1e18/nums[j])
				{
					ans=false;
					break;
				}
				if(nums[j]*sum != row_sums[j]+nums[j]*nums[j])
				{
					ans=false;
					break;
				}
			}
		}
		if(ans)
		{
			cout<<x<<" ";
			for(j=1;j<n;j++)
				cout<<mat[0][j]/x<<" ";
			cout<<endl;
			return 0;
		}
	}
	return 0;
}