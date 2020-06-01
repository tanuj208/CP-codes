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

void print_bits(ll x)
{
	string s = "";
	while(x!=0)
	{
		if(x%2==1)
			s += "1";
		else
			s += "0";
		x /= 2;
	}
	reverse(all(s));
	cout<<s<<endl;
	return;
}

ll get_value(ll cur_zone, ll st_val, ll st_idx, ll cur_idx)
{
	if(cur_zone == 4)
	{
		if(cur_idx == st_idx)
			return st_val;
		else if(cur_idx == st_idx+1)
			return st_val + 2;
		else if(cur_idx == st_idx + 2)
			return st_val + 3;
		else
			return st_val + 1;
	}
	ll rel_pos = cur_idx - st_idx;
	cur_zone/=4;
	ll tmp = rel_pos / cur_zone;
	if(tmp == 1)
		st_val += 2*cur_zone;
	else if(tmp == 2)
		st_val += 3*cur_zone;
	else if(tmp == 3)
		st_val += cur_zone;
	st_idx += tmp * cur_zone;

	// cout<<st_val<<endl;
	return get_value(cur_zone, st_val, st_idx, cur_idx);
}

vector<ll> tmp;
vector<ll> z;

ll get_one(ll n)
{
	ll x = n/3;
	ll idx = upper_bound(all(tmp), x) - tmp.begin();
	return z[idx] + (x - tmp[idx-1]);
}

ll get_two(ll n)
{
	ll x=n/3;
	ll idx = upper_bound(all(tmp), x) - tmp.begin();
	ll cur_zone = z[idx];
	ll st_idx = tmp[idx-1];
	ll st_val = 2*cur_zone;
	return get_value(cur_zone, st_val, st_idx, x);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// for(ll i=6;i<=21;i++)
	// 	cout<<get_value(16, 32, 6, i)<<" ";
	// cout<<endl;

	// cout<<get_value(16, 32, 6, 10)<<endl;
	// return 0;

	ll i;
	tmp.pb(1);
	z.pb(1);
	ll cur=1;
	for(i=1;i<=60;i++)
	{
		cur*=4;
		z.pb(cur);
		tmp.pb(tmp[i-1] + cur);
	}

	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		if(n<=3)
			cout<<n<<endl;
		else if(n%3==1)
		{
			cout<<get_one(n)<<endl;
		}
		else if(n%3==2)
		{
			cout<<get_two(n)<<endl;
		}
		else
		{
			ll x1 = get_one(n-2);
			ll x2= get_two(n-1);
			cout<<(x1^x2)<<endl;
		}
	}
	return 0;





	// vector<ll> vis(100005, 0);
	// vector<ll> ans;
	// for(i=1;i<=1000;i++)
	// {
	// 	if(vis[i] == 1)
	// 		continue;
	// 	for(ll j=i+1;j<=1000;j++)
	// 	{
	// 		if(vis[j]==1)
	// 			continue;
	// 		ll x = i^j;
	// 		if(vis[x] == 1)
	// 			continue;
	// 		ans.pb(i);
	// 		ans.pb(j);
	// 		ans.pb(x);
	// 		vis[i] = 1;
	// 		vis[j] = 1;
	// 		vis[x] = 1;
	// 		break;
	// 	}
	// }
	// for(i=1;i<100;i+=3)
	// 	cout<<ans[i]<<" ";
	// cout<<endl;
	// return 0;
}