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

typedef int ll;
typedef pair<ll,ll> pii;

vector<ll> lvl(2000005);

bool remove(ll index, vector<ll>& a, ll g, unordered_map<ll,ll>& pos)
{
	ll bck = index;
	while(a[index]!=0)
	{
		ll i1 = 2*index;
		ll i2 = 2*index+1;
		if(a[i1]==0 && a[i2]==0)
		{
			if(lvl[index] > g)
				break;
			else
				return false;
		}
		if(a[i1]>a[i2])
			index=i1;
		else
			index=i2;
	}
	index = bck;
	pos.erase(a[index]);
	while(a[index] != 0)
	{
		ll i1 = 2*index;
		ll i2 = i1+1;
		if(a[i1]==0 && a[i2]==0)
		{
			a[index]=0;
			break;
		}
		if(a[i1] > a[i2])
		{
			pos[a[i1]] = index;
			a[index] = a[i1];
			index = i1;
		}
		else
		{
			pos[a[i2]] = index;
			a[index] = a[i2];
			index = i2;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll i;
	lvl[1]=1;
	for(i=1;i<=1000000;i++)
	{
		if(2*i+1 > 2000000)
			break;
		lvl[2*i] = lvl[i]+1;
		lvl[2*i+1] = lvl[i]+1;
	}
	while(t--)
	{
		ll h,g;
		cin>>h>>g;
		ll n = ((ll)1<<h) - 1;
		ll final_n = ((ll)1<<g) - 1;
		vector<ll> a;
		a.pb(-1);
		ll sum=0;
		vector<ll> arr;
		unordered_map<ll,ll> pos;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
			arr.pb(val);
			pos[val] = i+1;
			sum += val;
		}

		ll tttmp = sz(a);
		for(i=0;i<tttmp;i++)
			a.pb(0);
		sort(all(arr));
		reverse(all(arr));

		ll removed=0;
		vector<ll> ans;
		ll cur_idx = 0;

		while(removed != n-final_n)
		{
			ll cur_val = arr[cur_idx];
			ll index = pos[cur_val];
			cur_idx++;
			if(remove(index, a, g, pos))
			{
				removed++;
				sum -= cur_val;
				ans.pb(index);
			}
		}
		cout<<sum<<endl;
		for(i=0;i<sz(ans);i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}		