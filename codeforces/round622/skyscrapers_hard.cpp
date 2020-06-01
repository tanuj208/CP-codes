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
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	set<pii, greater<pii>> ht;
	ht.insert(mp(a[0], 1));
	vector<ll> arr1(n+5, 0), arr2(n+5,0);
	arr1[0]=a[0];
	for(i=1;i<n;i++)
	{
		ll cnt=0;
		ll sub=0;
		while(!ht.empty())
		{
			ll tmp = ht.begin()->first;
			ll cc = ht.begin()->ss;
			if(tmp>a[i])
			{
				ht.erase(ht.begin());
				cnt+=cc;
				sub+=(tmp*cc);
			}
			else
				break;
		}
		ht.insert(mp(a[i], cnt+1));
		arr1[i]=arr1[i-1]-sub+a[i]*(cnt+1);
	}

	ht.clear();
	ht.insert(mp(a[n-1], 1));
	arr2[n-1]=a[n-1];
	for(i=n-2;i>=0;i--)
	{
		ll cnt=0;
		ll sub=0;
		while(!ht.empty())
		{
			ll tmp = ht.begin()->first;
			ll cc = ht.begin()->ss;
			if(tmp>a[i])
			{
				ht.erase(ht.begin());
				cnt+=cc;
				sub+=(tmp*cc);
			}
			else
				break;
		}
		ht.insert(mp(a[i], cnt+1));
		arr2[i]=arr2[i+1]-sub+a[i]*(cnt+1);
	}
	for(i=0;i<n;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;
	for(i=0;i<n;i++)
		cout<<arr2[i]<<" ";
	cout<<endl;
	ll mx=0;
	ll idx;
	for(i=0;i<n;i++)
	{
		if(mx <= arr1[i]+arr2[i]-a[i])
		{
			mx=arr1[i]+arr2[i]-a[i];
			idx=i;
		}
	}

// cout<<mx<<" "<<idx<<endl;

	vector<ll> ans(n+5);
	ans[idx]=a[idx];
	ll curmax=a[idx];
	for(i=idx-1;i>=0;i--)
	{
		curmax=min(curmax, a[i]);
		ans[i]=curmax;
	}
	curmax=a[idx];
	for(i=idx+1;i<n;i++)
	{
		curmax=min(curmax, a[i]);
		ans[i]=curmax;
	}
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}