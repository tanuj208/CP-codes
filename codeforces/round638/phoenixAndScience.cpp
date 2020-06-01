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

bool possible(ll target, ll d, vector<ll>& arr)
{
	ll cur=d+1;
	ll i;
	ll lt=1;
	for(i=d;i>=1;i--)
	{
		ll tmp = (target - cur) / i;
		if(tmp > lt)
		{
			cur += i * lt;
			arr.pb(lt);
			lt *= 2;
		}
		else
		{
			cur += i * tmp;
			lt += tmp;
			arr.pb(tmp);
		}
	}
	if(cur == target)
		return true;
	else
		return false;
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
		vector<ll> tmp;
		ll i;
		for(i=1;i<=100;i++)
		{
			if(possible(n, i, tmp))
				break;
			tmp.clear();
		}
		cout<<sz(tmp)<<endl;
		for(i=0;i<sz(tmp);i++)
			cout<<tmp[i]<<" ";
		cout<<endl;
	}
	return 0;
}