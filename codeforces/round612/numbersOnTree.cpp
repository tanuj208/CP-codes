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

vector<ll> ad[2005];
vector<ll> c;
bool ans=true;

vector<ll> dfs(ll v)
{
	ll i;
	vector<vector<ll>> tmp;
	for(i=0;i<sz(ad[v]);i++)
	{
		tmp.pb(dfs(ad[v][i]));
	}
	// if(v==1)
	// {
	// 	for(i=0;i<sz(tmp);i++)
	// 	{
	// 		for(ll j=0;j<sz(tmp[i]);j++)
	// 			cout<<tmp[i][j]<<" ";
	// 		cout<<endl;
	// 	}
	// }
	ll cur_rank=c[v-1];
	vector<ll> new_vec;
	for(i=0;i<sz(tmp);i++)
	{
		ll j;
		if(cur_rank>=sz(tmp[i]))
		{
			cur_rank-=sz(tmp[i]);
			for(j=0;j<sz(tmp[i]);j++)
				new_vec.pb(tmp[i][j]);
		}
		else if(cur_rank==-1)
		{
			for(j=0;j<sz(tmp[i]);j++)
				new_vec.pb(tmp[i][j]);
		}
		else
		{
			for(j=0;j<sz(tmp[i]);j++)
			{
				if(cur_rank==0)
				{
					new_vec.pb(v);
					new_vec.pb(tmp[i][j]);
					cur_rank--;
				}
				else if(cur_rank==-1)
					new_vec.pb(tmp[i][j]);
				else
				{
					cur_rank--;
					new_vec.pb(tmp[i][j]);
				}
			}
		}
	}
	if(cur_rank==0)
	{
		new_vec.pb(v);
		cur_rank--;
	}
	if(cur_rank!=-1)
		ans=false;
	// if(v==1)
	// {
	// 	for(i=0;i<sz(new_vec);i++)
	// 		cout<<new_vec[i]<<" ";
	// 	cout<<endl;
	// }
	return new_vec;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	ll root=-1;
	for(i=0;i<n;i++)
	{
		ll p,val;
		cin>>p>>val;
		c.pb(val);
		if(p==0)
			root=i+1;
		else
			ad[p].pb(i+1);
	}
	vector<ll> ord=dfs(root);
	if(!ans)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES"<<endl;
		vector<ll> val(n+5, 0);
		for(i=0;i<sz(ord);i++)
		{
			// cout<<ord[i]<<" ";
			val[ord[i]]=i+1;
		}
		// cout<<endl;
		for(i=1;i<=n;i++)
			cout<<val[i]<<" ";
		cout<<endl;
	}
	return 0;
}