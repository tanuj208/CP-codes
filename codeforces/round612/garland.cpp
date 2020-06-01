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
	vector<ll> a;
	ll i;
	set<ll> tmp;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		tmp.insert(val);
		a.pb(val);
	}
	ll last=-1;
	ll cnt=0;
	vector<ll> even;
	vector<ll> odd;
	ll ans=0;
	ll e=0,o=0;
	ll stEven=0;
	ll stOdd=0;
	ll enEven=0;
	ll enOdd=0;
	for(i=1;i<=n;i++)
	{
		if(tmp.find(i)==tmp.end())
		{
			if(i%2==0)
				e++;
			else
				o++;
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
			cnt++;
		else
		{
			if(last==-1)
			{
				if(a[i]%2==0)
				{
					last=0;
					stEven=cnt;
				}
				else
				{
					last=1;
					stOdd=cnt;
				}
			}
			else if(last==0)
			{
				if(a[i]%2==0)
				{
					even.pb(cnt);
					last=0;
				}
				else
				{
					last=1;
					ans++;
				}
			}
			else
			{
				if(a[i]%2==1)
				{
					odd.pb(cnt);
					last=1;
				}
				else
				{
					last=0;
					ans++;
				}
			}
			cnt=0;
		}
	}
	if(last==0)
		enEven=cnt;
	else
		enOdd=cnt;
	sort(all(even));
	sort(all(odd));
	// cout<<enOdd<<endl;
	for(i=0;i<sz(even);i++)
	{
		if(even[i]>e)
			break;
		else
			e-=even[i];
	}
	ans+=(2*(sz(even)-i));
	if(e<stEven)
		ans++;
	else
		e-=stEven;
	if(e<enEven)
		ans++;
	else
		e-=enEven;
		// cout<<even[i]<<" ";
	// cout<<ans<<endl;
	for(i=0;i<sz(odd);i++)
	{
		if(odd[i]>o)
			break;
		else
			o-=odd[i];
	}
	ans+=(2*(sz(odd)-i));
	if(o<stOdd)
		ans++;
	else
		o-=stOdd;
	if(o<enOdd)
		ans++;
	else
		o-=enOdd;
	cout<<ans<<endl;
	return 0;
}