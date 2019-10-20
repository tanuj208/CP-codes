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
	vector<vector<ll>> ans;
	vector<ll> tmp;
	tmp.pb(1);
	ans.pb(tmp);
	ll i;
	bool flag=true;
	for(i=2;i<=n;i++)
	{
		ll j;
		vector<vector<ll>> tmp2;
		for(j=0;j<sz(ans);j++)
		{
			if(flag)
			{
				vector<ll> tmp3 = ans[j];
				tmp3.pb(i);
				tmp2.pb(tmp3);
				ll k;
				for(k=i-2;k>=0;k--)
				{
					swap(tmp3[k], tmp3[k+1]);
					tmp2.pb(tmp3);
				}
				flag=false;
			}
			else
			{
				vector<ll> tmp3{i};
				ll k;
				for(k=0;k<sz(ans[j]);k++)
					tmp3.pb(ans[j][k]);
				tmp2.pb(tmp3);
				for(k=1;k<i;k++)
				{
					swap(tmp3[k], tmp3[k-1]);
					tmp2.pb(tmp3);
				}
				flag=true;
			}
		}
		ans=tmp2;
	}
	for(i=0;i<sz(ans);i++)
	{
		ll j;
		bool flag = true;
		for(j=0;j<n;j++)
		{
			if(ans[i][j] != j+1)
				flag=false;
		}
		if(flag)
			break;
	}
	for(ll j=i;j<sz(ans);j++)
	{
		ll k;
		for(k=0;k<n;k++)
			cout<<ans[j][k]<<" ";
		cout<<endl;
	}
	for(ll j=0;j<=i-1;j++)
	{
		ll k;
		for(k=0;k<n;k++)
			cout<<ans[j][k]<<" ";
		cout<<endl;
	}
	return 0;
}