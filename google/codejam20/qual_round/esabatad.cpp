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

ll ask_query(ll bit_index)
{
	cout<<bit_index<<endl;
	fflush(stdout);
	ll x;
	cin>>x;
	return x;
}

bool break_loop(vector<ll>& ans, ll b)
{
	// for(ll i=1;i<=b;i++)
	// 	cout<<ans[i]<<" ";
	// cout<<endl;
	for(ll i=1;i<=b;i++)
		if(ans[i]==-1)
			return false;
	return true;
}

vector<ll> reverse_array(vector<ll>& ans, ll b)
{
	vector<ll> ans2(b+2, -1);
	for(ll i=1;i<=b;i++)
		if(ans[i]!=-1)
			ans2[i] = ans[b-i+1];
	return ans2;
}

vector<ll> flip_array(vector<ll>& ans, ll b)
{
	vector<ll> ans2(b+2, -1);
	for(ll i=1;i<=b;i++)
	{
		if(ans[i]==1)
			ans2[i]=0;
		else if(ans[i] == 0)
			ans2[i]=1;
	}
	return ans2;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	ll t,b,i;
	cin>>t>>b;
	ll op = 10;
	while(t--)
	{
		ll same=-1, diff=-1;
		ll l=1,r=b;
		vector<ll> ans(b+5,-1);
		ll queries=0;
		while(l<=r)
		{
			// cout<<l<<" "<<r<<endl;
			while(true)
			{
				if(queries % op == 0 && queries!=0)
					break;
				if((queries+1) % op == 0)
				{
					ll tmp = ask_query(1);
					break;
				}
				if(l>r)
					break;
				ll x = ask_query(l);
				ll y = ask_query(r);
				ans[l]=x;
				ans[r]=y;

				if(ans[l] == ans[r] && same == -1)
					same = l;
				else if(ans[l] != ans[r] && diff == -1)
					diff = l;
				l++;
				r--;
				queries+=2;
			}
			// cout<<l<<" "<<r<<endl;
			if(break_loop(ans, b))
				break;

			bool reverse = false;
			bool flip = false;
			if(same == -1)
			{
				ll x = ask_query(diff);
				queries++;
				if(x!=ans[diff])
					flip = true;
			}
			else if(diff == -1)
			{
				ll x = ask_query(same);
				queries++;
				if(x!=ans[same])
					flip = true;
			}
			else
			{
				ll x = ask_query(same);
				ll y = ask_query(diff);
				queries+=2;

				if(x!=ans[same])
					flip = true;

				if((y!=ans[diff] && !flip) || (y==ans[diff] && flip))
					reverse = true;
			}
			if(reverse)
				ans = reverse_array(ans, b);
			if(flip)
				ans = flip_array(ans, b);
		}

		for(i=1;i<=b;i++)
			cout<<ans[i];
		cout<<endl;
		fflush(stdout);
		char c;
		cin>>c;
		if(c=='Y')
			continue;
		else
			break;
	}
	return 0;
}